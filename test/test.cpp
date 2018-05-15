#include <iostream>
#include "gdv/gdv.h"

using namespace column_major;
using namespace left_hand;

int main() {

    vec3 p{1.0f, 2.0f, 0.0f};
    camera<float> c{
        {0.0f, 0.0f, -1.0f},
        {0.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        PI<float> / 3.0f,
        3.0f / 4.0f,
        0.01f,
        100.0f
    };

    p = c * p;
    std::cout << p.x << ", " << p.y << ", " << p.z << std::endl;

    return 0;
}

