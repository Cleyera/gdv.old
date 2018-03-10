/**
* @file Types.h
* @brief gdv内で使用する型のエイリアスが定義されたファイルです
**/
#ifndef GDV_TYPES_H_
#define GDV_TYPES_H_

#include <stdint.h>

namespace gdv {

using uint      = unsigned int;

using uchar     = unsigned char;
using ushort    = unsigned short;
using ulong     = unsigned long;

using byte      = unsigned char;
using word      = unsigned short;
using dword     = unsigned long;
using qword     = unsigned long long;

using int8      = char;
using int16     = short;
using int32     = long;
using int64     = long long;

using uint8     = unsigned char;
using uint16    = unsigned short;
using uint32    = unsigned long;
using uint64    = unsigned long long;

} // namespace gdv

#endif
