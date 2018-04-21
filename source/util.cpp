#include <stddef.h>
#include "gdv/Util/util.h"

namespace gdv {

constexpr uint16 convet_endian(uint16 val) noexcept {
    return ((val & 0xff00) >> 8)
        |  ((val & 0x00ff) << 8);
}


constexpr uint32 convet_endian(uint32 val) noexcept {
    return ((val & 0xff000000) >> 24)
        |  ((val & 0x00ff0000) >>  8)
        |  ((val & 0x0000ff00) <<  8)
        |  ((val & 0x000000ff) << 24);
}


constexpr uint64 convet_endian(uint64 val) noexcept {
    return ((val & 0xff00000000000000) >> 56)
        |  ((val & 0x00ff000000000000) >> 40)
        |  ((val & 0x0000ff0000000000) >> 24)
        |  ((val & 0x000000ff00000000) >>  8)
        |  ((val & 0x00000000ff000000) <<  8)
        |  ((val & 0x0000000000ff0000) << 24)
        |  ((val & 0x000000000000ff00) << 40)
        |  ((val & 0x00000000000000ff) << 56);
}




constexpr size_t bit_count(uint8 value) noexcept {
    uint16
    count = (value & 0x55) + ((value >> 1) & 0x55);
    count = (count & 0x33) + ((count >> 2) & 0x33);
    return  (count & 0x0f) + ((count >> 4) & 0x0f);

}

constexpr size_t bit_count(uint16 value) noexcept {
    uint16
    count = (value & 0x5555) + ((value >> 1) & 0x5555);
    count = (count & 0x3333) + ((count >> 2) & 0x3333);
    count = (count & 0x0f0f) + ((count >> 4) & 0x0f0f);
    return  (count & 0x00ff) + ((count >> 8) & 0x00ff);

}

constexpr size_t bit_count(uint32 value) noexcept {
    uint32
    count = (value & 0x55555555) + ((value >>  1) & 0x55555555);
    count = (count & 0x33333333) + ((count >>  2) & 0x33333333);
    count = (count & 0x0f0f0f0f) + ((count >>  4) & 0x0f0f0f0f);
    count = (count & 0x00ff00ff) + ((count >>  8) & 0x00ff00ff);
    return  (count & 0x0000ffff) + ((count >> 16) & 0x0000ffff);
}


constexpr size_t bit_count(uint64 value) noexcept {
    uint64
    count = (value & 0x5555555555555555) + ((value >>  1) & 0x5555555555555555);
    count = (count & 0x3333333333333333) + ((count >>  2) & 0x3333333333333333);
    count = (count & 0x0f0f0f0f0f0f0f0f) + ((count >>  4) & 0x0f0f0f0f0f0f0f0f);
    count = (count & 0x00ff00ff00ff00ff) + ((count >>  8) & 0x00ff00ff00ff00ff);
    count = (count & 0x0000ffff0000ffff) + ((count >> 16) & 0x0000ffff0000ffff);
    return  (count & 0x00000000ffffffff) + ((count >> 32) & 0x00000000ffffffff);
}




constexpr size_t msb(uint8 value) noexcept {
    value |= (value >>  1);
    value |= (value >>  2);
    value |= (value >>  4);
    return bit_count(value);
}

constexpr size_t msb(uint16 value) noexcept {
    value |= (value >>  1);
    value |= (value >>  2);
    value |= (value >>  4);
    value |= (value >>  8);
    return bit_count(value);
}

constexpr size_t msb(uint32 value) noexcept {
    value |= (value >>  1);
    value |= (value >>  2);
    value |= (value >>  4);
    value |= (value >>  8);
    value |= (value >> 16);
    return bit_count(value);
}

constexpr size_t msb(uint64 value) noexcept {
    value |= (value >>  1);
    value |= (value >>  2);
    value |= (value >>  4);
    value |= (value >>  8);
    value |= (value >> 16);
    value |= (value >> 32);
    return bit_count(value);
}


constexpr size_t lsb(uint8 value) noexcept {
    value |= (value <<  1);
    value |= (value <<  2);
    value |= (value <<  4);
    return 8 - bit_count(value);
}

constexpr size_t lsb(uint16 value) noexcept {
    value |= (value <<  1);
    value |= (value <<  2);
    value |= (value <<  4);
    value |= (value <<  8);
    return 16 - bit_count(value);
}

constexpr size_t lsb(uint32 value) noexcept {
    value |= (value <<  1);
    value |= (value <<  2);
    value |= (value <<  4);
    value |= (value <<  8);
    value |= (value << 16);
    return 32 - bit_count(value);
}

constexpr size_t lsb(uint64 value) noexcept {
    value |= (value <<  1);
    value |= (value <<  2);
    value |= (value <<  4);
    value |= (value <<  8);
    value |= (value << 16);
    value |= (value << 32);
    return 64 - bit_count(value);
}

} // namespace gdv

