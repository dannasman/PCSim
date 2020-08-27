#include <iostream>
#include "./headers/vector3.h"
#include "./headers/particle.h"

using namespace std;

int main()
{
    Particle particle;

    particle.setPosition(0.0, 0.0, 0.0);
    particle.setVelocity(0.0, 0.0, 0.0);
    particle.setAcceleration(10.0, 0.0, 0.0);
    particle.setMass(0.010);
    particle.setDamping(0.995);

    for (float i = 1; i < 1000; i++)
    {
        particle.integrate(i);
        cout << "position(x, y, z): " << particle.position.x << " " << particle.position.y << " " << particle.position.z;
        cout << " velocity(x, y, z): " << particle.velocity.x << " " << particle.velocity.y << " " << particle.velocity.z;
        cout << " acceleration(x, y, z): " << particle.acceleration.x << " " << particle.acceleration.y << " " << particle.acceleration.z << endl;
        if (i > 10)
            particle.setAcceleration(0.0, 0.0, 0.0);
    }

    return 0;
}
