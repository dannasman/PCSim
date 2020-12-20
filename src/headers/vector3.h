#ifndef VECTOR_H
#define VECTOR_H

class Vector3
{

public:
    float x;
    float y;
    float z;

    Vector3() : x(0), y(0), z(0){};
    Vector3(float, float, float);
    float magnitude();
    float squareMagnitude();
    void normalize();
    void invert();
    void addScaledVector(const Vector3 &, float);
    Vector3 componentProduct(const Vector3 &) const;
    void componentProductUpdate(const Vector3 &);
    float scalarProduct(const Vector3 &) const;
    Vector3 vectorProduct(const Vector3 &) const;
    void clear();
    Vector3 vectorProjection(const Vector3 &) const;

    void operator*=(const float value)
    {
        x *= value;
        y *= value;
        z *= value;
    }

    Vector3 operator*(const float value) const
    {
        return Vector3(x * value, y * value, z * value);
    }

    float operator*(const Vector3 &vector) const
    {
        return x * vector.x + y * vector.y + z * vector.z;
    }

    void operator+=(const Vector3 &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    Vector3 operator+(const Vector3 &v) const
    {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    void operator-=(const Vector3 &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }

    Vector3 operator-(const Vector3 &v) const
    {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    void operator%=(const Vector3 &vector)
    {
        *this = vectorProduct(vector);
    }

    Vector3 operator%(const Vector3 &vector) const
    {
        return Vector3(y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x);
    }
};

#endif // VECTOR3_H
