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

    void integrate(float);
    void clearAccumulator();
    void setMass(float);
    void setDamping(float);
    void setPosition(float, float, float);
    void setVelocity(float, float, float);
    void setAcceleration(float, float, float);
};

#endif // PARTICLE_H
