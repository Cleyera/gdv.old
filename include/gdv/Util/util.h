#ifndef GDV_UTIL_H_
#define GDV_UTIL_H_

#include "gdv/Common/Types.h"

namespace gdv {


// change the order of bytes
constexpr uint16 convet_endian(uint16 val) noexcept;

constexpr uint32 convet_endian(uint32 val) noexcept;

constexpr uint64 convet_endian(uint64 val) noexcept;




// count the number of bits of 1
constexpr size_t bit_count(uint8 value) noexcept;

constexpr size_t bit_count(uint16 value) noexcept;

constexpr size_t bit_count(uint32 value) noexcept;

constexpr size_t bit_count(uint64 value) noexcept;




// MSBを求める
constexpr size_t msb(uint8 value) noexcept;

constexpr size_t msb(uint16 value) noexcept;

constexpr size_t msb(uint32 value) noexcept;

constexpr size_t msb(uint64 value) noexcept;


// LSBを求める
constexpr size_t lsb(uint8 value) noexcept;

constexpr size_t lsb(uint16 value) noexcept;

constexpr size_t lsb(uint32 value) noexcept;

constexpr size_t lsb(uint64 value) noexcept;

} // namespace gdv

#endif

