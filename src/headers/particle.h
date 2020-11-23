#ifndef PARTICLE_H
#define PARTICLE_H
#include "vector3.h"

class Particle
{
public:
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    Vector3 forceAccum;

    float damping;
    float inverseMass;
    float radius;

    void integrate(float);
    void clearAccumulator();
    void setRadius(float);
    void setMass(float);
    void setDamping(float);
    void setPosition(float, float, float);
    void setVelocity(float, float, float);
    void setAcceleration(float, float, float);
    void checkForCollision(Particle &);
};

#endif // PARTICLE_H
