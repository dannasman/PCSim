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
    float dx = position.x - particle.position.x;
    float dy = position.y - particle.position.y;
    float dz = position.z - particle.position.z;

    float distance = sqrt(dx * dx + dy * dy + dz * dz);

    if (distance <= particle.radius + radius)
    {
        float angle = acos((dx * velocity.x + dy * velocity.y + dz * velocity.z) /
                           sqrt((dx + dy + dz) * (velocity.x + velocity.y + velocity.z)));
        Vector3 velocity_center = velocity * cos(angle);
    }
}