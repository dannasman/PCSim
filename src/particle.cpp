#include <assert.h>
#include "cmath"
#include "./headers/particle.h"
#include "./headers/precision.h"

void Particle::integrate(float duration)
{
    assert(duration > 0.0);

    position.addScaledVector(velocity, duration);

    Vector3 resultingAcc = acceleration;
    resultingAcc.addScaledVector(forceAccum, duration);

    velocity.addScaledVector(resultingAcc, duration);

    velocity *= float_pow(damping, duration);
}

void Particle::clearAccumulator()
{
    forceAccum.clear();
}

void Particle::setRadius(float p_radius)
{
    radius = p_radius;
}

void Particle::setMass(float mass)
{
    assert(mass != 0);

    inverseMass = 1 / mass;
}

void Particle::setDamping(float p_damping)
{
    damping = p_damping;
}

void Particle::setPosition(float p_x, float p_y, float p_z)
{
    position.x = p_x;
    position.y = p_y;
    position.z = p_z;
}

void Particle::setVelocity(float p_x, float p_y, float p_z)
{
    velocity.x = p_x;
    velocity.y = p_y;
    velocity.z = p_z;
}

void Particle::setAcceleration(float p_x, float p_y, float p_z)
{
    acceleration.x = p_x;
    acceleration.y = p_y;
    acceleration.z = p_z;
}

void Particle::checkForCollision(Particle &particle)
{
    float dx = particle.position.x - position.x;
    float dy = particle.position.y - position.y;
    float dz = particle.position.z - position.z;

    Vector3 radius_vector;
    radius_vector.x = dx;
    radius_vector.y = dy;
    radius_vector.z = dz;

    float distance = sqrt(dx * dx + dy * dy + dz * dz);

    if (distance <= particle.radius + radius)
    {
        Vector3 normal_vector = (position - particle.position) * (1 / ((position - particle.position).magnitude()));
        Vector3 velocity_relative = velocity - particle.velocity;
        float f = (velocity_relative * normal_vector);
        Vector3 velocity_normal = normal_vector * (velocity_relative * normal_vector);
        velocity = velocity - velocity_normal * (2 / (particle.inverseMass * (1 / inverseMass + 1 / particle.inverseMass)));
    }
}