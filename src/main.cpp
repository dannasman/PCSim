#include <iostream>
#include <fstream>
#include "./headers/vector3.h"
#include "./headers/particle.h"

using namespace std;

int main()
{
    Particle particle1;
    Particle particle2;
    Particle helper;

    particle1.setPosition(0.0, 0.0, 0.0);
    particle1.setVelocity(0.2, 0.3, 0.0);
    particle1.setAcceleration(0.0, -0.981, 0.0);
    particle1.setMass(0.010);
    particle1.setDamping(1.0);
    particle1.setRadius(4.0);

    particle2.setPosition(20.0, 0.0, 0.0);
    particle2.setVelocity(-0.1, 0.2, 0.0);
    particle2.setAcceleration(0.0, -0.981, 0.0);
    particle2.setMass(0.010);
    particle2.setDamping(1.0);
    particle2.setRadius(4.0);

    ofstream ParticleData1("./particle1.csv");
    ofstream ParticleData2("./particle2.csv");

    for (float i = 1; i <= 15; i++)
    {
        particle1.integrate(i);
        particle2.integrate(i);
        helper = particle1;
        particle1.checkForCollision(particle2);
        particle2.checkForCollision(helper);

        ParticleData1 << particle1.position.x << ", " << particle1.position.y << ", " << particle1.position.z << "\n";
        ParticleData2 << particle2.position.x << ", " << particle2.position.y << ", " << particle2.position.z << "\n";
    }

    ParticleData1.close();
    ParticleData2.close();

    return 0;
}
