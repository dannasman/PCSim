#include <iostream>
#include <fstream>
#include "./headers/vector3.h"
#include "./headers/particle.h"

using namespace std;

int main()
{
    Particle particle1;
    Particle particle2;
    Particle particle3;
    Particle helper;

    particle1.setPosition(0.0, 0.0, 0.0);
    particle1.setVelocity(0.2, 5.0, 0.0);
    particle1.setAcceleration(0.0, -0.981, 0.0);
    particle1.setMass(0.010);
    particle1.setDamping(1.0);
    particle1.setRadius(5.0);

    particle2.setPosition(20.0, 0.0, 0.0);
    particle2.setVelocity(-0.1, 4.99, 0.0);
    particle2.setAcceleration(0.0, -0.981, 0.0);
    particle2.setMass(1.0);
    particle2.setDamping(1.0);
    particle2.setRadius(5.0);

    particle3.setPosition(0.0, 0.0, 20);
    particle3.setVelocity(0.0, 4.99, -0.2);
    particle3.setAcceleration(0.0, -0.981, 0.0);
    particle3.setMass(0.1);
    particle3.setDamping(1.0);
    particle3.setRadius(5.0);

    ofstream ParticleData1("./particle1.csv");
    ofstream ParticleData2("./particle2.csv");
    ofstream ParticleData3("./particle3.csv");

    for (float i = 1; i <= 15; i++)
    {
        particle1.integrate(i);
        particle2.integrate(i);
        particle3.integrate(i);

        Particle helper1 = particle1;
        Particle helper2 = particle2;

        particle1.checkForCollision(particle2);
        particle1.checkForCollision(particle3);

        particle2.checkForCollision(helper1);
        particle2.checkForCollision(particle3);

        particle3.checkForCollision(helper1);
        particle3.checkForCollision(helper2);

        ParticleData1 << particle1.position.x << ", " << particle1.position.y << ", " << particle1.position.z << "\n";
        ParticleData2 << particle2.position.x << ", " << particle2.position.y << ", " << particle2.position.z << "\n";
        ParticleData3 << particle3.position.x << ", " << particle3.position.y << ", " << particle3.position.z << "\n";
    }

    ParticleData1.close();
    ParticleData2.close();
    ParticleData3.close();

    return 0;
}
