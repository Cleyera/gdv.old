#include <iostream>
#include "gdv/gdv.h"

int main() {
    Vector2<int> p{0, 0};
    p += 10;
    std::cout << p.x << ", " << p.y << std::endl;
    return 0;
}
