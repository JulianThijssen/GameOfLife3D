#ifndef LIFE_MATH_H
#define LIFE_MATH_H

namespace Life {
    const float PI = 3.14159265359f;

    float toDegrees(const float radians)
    {
        return radians * (180 / PI);
    }
    
    float toRadians(const float degrees)
    {
        return degrees * (PI / 180);
    }
}

#endif /* LIFE_MATH_H */
