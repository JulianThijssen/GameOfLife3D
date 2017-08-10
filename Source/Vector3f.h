#ifndef LIFE_VECTOR3F_H
#define LIFE_VECTOR3F_H

namespace Life
{
    class Vector3f
    {
    public:
        Vector3f() : x(0), y(0), z(0) { }

        Vector3f(float x, float y, float z) :
            x(x), y(y), z(z) { }


        float x, y, z;
    };
}

#endif // LIFE_VECTOR3F_H
