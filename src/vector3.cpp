#include "./headers/vector3.h"
#include "cmath"

Vector3::Vector3(float p_x, float p_y, float p_z)
{
    x = p_x;
    y = p_y;
    z = p_z;
}

float Vector3::magnitude()
{
    return sqrt(x * x + y * y + z * z);
}

float Vector3::squareMagnitude()
{
    return x * x + y * y + z * z;
}

void Vector3::normalize()
{
    float l = magnitude();
    if (l > 0)
        (*this) *= ((float)1) / l;
}

void Vector3::invert()
{
    x = -x;
    y = -y;
    z = -z;
}

void Vector3::addScaledVector(const Vector3 &vector, float scale)
{
    x += vector.x * scale;
    y += vector.y * scale;
    z += vector.z * scale;
}

Vector3 Vector3::componentProduct(const Vector3 &vector) const
{
    return Vector3(x * vector.x, y * vector.y, z * vector.z);
}

void Vector3::componentProductUpdate(const Vector3 &vector)
{
    x *= vector.x;
    y *= vector.y;
    z *= vector.z;
}

float Vector3::scalarProduct(const Vector3 &vector) const
{
    return x * vector.x + y * vector.y + z * vector.z;
}

Vector3 Vector3::vectorProduct(const Vector3 &vector) const
{
    return Vector3(y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x);
}

void Vector3::clear()
{
    x = 0;
    y = 0;
    z = 0;
}