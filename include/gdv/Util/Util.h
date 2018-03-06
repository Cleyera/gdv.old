#ifndef GDV_UTIL_H_
#define GDV_UTIL_H_

#include "gdv/Common/Types.h"

namespace gdv {


// change the order of bytes
constexpr uint16 ConvertEndian(uint16 val) noexcept;

constexpr uint32 ConvertEndian(uint32 val) noexcept;

constexpr uint64 ConvertEndian(uint64 val) noexcept;




// count the number of bits of 1
constexpr int BitCount(uint8 value) noexcept;

constexpr int BitCount(uint16 value) noexcept;

constexpr int BitCount(uint32 value) noexcept;

constexpr int BitCount(uint64 value) noexcept;




// MSBを求める
constexpr int MostSignificantBit(uint8 value) noexcept;

constexpr int MostSignificantBit(uint16 value) noexcept;

constexpr int MostSignificantBit(uint32 value) noexcept;

constexpr int MostSignificantBit(uint64 value) noexcept;


// LSBを求める
constexpr int LeastSignificantBit(uint8 value) noexcept;

constexpr int LeastSignificantBit(uint16 value) noexcept;

constexpr int LeastSignificantBit(uint32 value) noexcept;

constexpr int LeastSignificantBit(uint64 value) noexcept;

} // namespace gdv

#endif
