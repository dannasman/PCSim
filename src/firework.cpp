#include "./headers/firework.h"

struct FireworkRule
{
    unsigned type;

    float minAge;
    float maxAge;

    Vector3 minVelocity;
    Vector3 maxVelocity;

    float damping;

    struct Payload
    {
        unsigned type;
        unsigned count;
    };

    unsigned payloadCount;

    Payload *payloads;
};
