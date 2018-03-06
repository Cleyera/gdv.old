#include "gdv/Util/Util.h"

namespace gdv {

//16bit�����Ȃ������̃G���f�B�A���𑊌݂ɕϊ�����
constexpr uint16 ConvertEndian(uint16 val) noexcept {
	return ((val & 0xff00) >> 8)
		|  ((val & 0x00ff) << 8);
}


//16bit�������萮���̃G���f�B�A���𑊌݂ɕϊ�����
constexpr int16 ConvertEndian(int16 val) noexcept {
	return ((val & 0xff00) >> 8)
		|  ((val & 0x00ff) << 8);
}


//32bit�����Ȃ������̃G���f�B�A���𑊌݂ɕϊ�����
constexpr uint32 ConvertEndian(uint32 val) noexcept {
	return ((val & 0xff000000) >> 24)
		|  ((val & 0x00ff0000) >>  8)
		|  ((val & 0x0000ff00) <<  8)
		|  ((val & 0x000000ff) << 24);
}

//64bit�����Ȃ������̃G���f�B�A���𑊌݂ɕϊ�����
constexpr uint64 ConvertEndian(uint64 val) noexcept {
	return ((val & 0xff00000000000000) >> 56)
		|  ((val & 0x00ff000000000000) >> 40)
		|  ((val & 0x0000ff0000000000) >> 24)
		|  ((val & 0x000000ff00000000) >>  8)
		|  ((val & 0x00000000ff000000) <<  8)
		|  ((val & 0x0000000000ff0000) << 24)
		|  ((val & 0x000000000000ff00) << 40)
		|  ((val & 0x00000000000000ff) << 56);
}


//���������@�ŗ����Ă����r�b�g�̐����J�E���g����
constexpr int BitCount(uint8 value) noexcept {
	uint16
	count = (value & 0x55) + ((value >> 1) & 0x55);
	count = (count & 0x33) + ((count >> 2) & 0x33);
	return  (count & 0x0f) + ((count >> 4) & 0x0f);

}

constexpr int BitCount(uint16 value) noexcept {
	uint16
	count = (value & 0x5555) + ((value >> 1) & 0x5555);
	count = (count & 0x3333) + ((count >> 2) & 0x3333);
	count = (count & 0x0f0f) + ((count >> 4) & 0x0f0f);
	return  (count & 0x00ff) + ((count >> 8) & 0x00ff);

}

constexpr int BitCount(uint32 value) noexcept {
	uint32
	count = (value & 0x55555555) + ((value >>  1) & 0x55555555);
	count = (count & 0x33333333) + ((count >>  2) & 0x33333333);
	count = (count & 0x0f0f0f0f) + ((count >>  4) & 0x0f0f0f0f);
	count = (count & 0x00ff00ff) + ((count >>  8) & 0x00ff00ff);
	return  (count & 0x0000ffff) + ((count >> 16) & 0x0000ffff);
}


constexpr int BitCount(uint64 value) noexcept {
	uint64
	count = (value & 0x5555555555555555) + ((value >>  1) & 0x5555555555555555);
	count = (count & 0x3333333333333333) + ((count >>  2) & 0x3333333333333333);
	count = (count & 0x0f0f0f0f0f0f0f0f) + ((count >>  4) & 0x0f0f0f0f0f0f0f0f);
	count = (count & 0x00ff00ff00ff00ff) + ((count >>  8) & 0x00ff00ff00ff00ff);
	count = (count & 0x0000ffff0000ffff) + ((count >> 16) & 0x0000ffff0000ffff);
	return  (count & 0x00000000ffffffff) + ((count >> 32) & 0x00000000ffffffff);
}



//�ŏ��ʃr�b�g�����߂��֐�
constexpr int MostSignificantBit(uint8 value) noexcept {
	value |= (value >>  1);
	value |= (value >>  2);
	value |= (value >>  4);
	return BitCount(value);
}

constexpr int MostSignificantBit(uint16 value) noexcept {
	value |= (value >>  1);
	value |= (value >>  2);
	value |= (value >>  4);
	value |= (value >>  8);
	return BitCount(value);
}

constexpr int MostSignificantBit(uint32 value) noexcept {
	value |= (value >>  1);
	value |= (value >>  2);
	value |= (value >>  4);
	value |= (value >>  8);
	value |= (value >> 16);
	return BitCount(value);
}

constexpr int MostSignificantBit(uint64 value) noexcept {
	value |= (value >>  1);
	value |= (value >>  2);
	value |= (value >>  4);
	value |= (value >>  8);
	value |= (value >> 16);
	value |= (value >> 32);
	return BitCount(value);
}


constexpr int LeastSignificantBit(uint8 value) noexcept {
	value |= (value <<  1);
	value |= (value <<  2);
	value |= (value <<  4);
	return 8 - BitCount(value);
}

constexpr int LeastSignificantBit(uint16 value) noexcept {
	value |= (value <<  1);
	value |= (value <<  2);
	value |= (value <<  4);
	value |= (value <<  8);
	return 16 - BitCount(value);
}

constexpr int LeastSignificantBit(uint32 value) noexcept {
	value |= (value <<  1);
	value |= (value <<  2);
	value |= (value <<  4);
	value |= (value <<  8);
	value |= (value << 16);
	return 32 - BitCount(value);
}

constexpr int LeastSignificantBit(uint64 value) noexcept {
	value |= (value <<  1);
	value |= (value <<  2);
	value |= (value <<  4);
	value |= (value <<  8);
	value |= (value << 16);
	value |= (value << 32);
	return 64 - BitCount(value);
}

} // namespace gdv