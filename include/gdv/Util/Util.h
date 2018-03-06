#ifndef GDV_UTIL_H_
#define GDV_UTIL_H_

#include "gdv/Common/Types.h"

namespace gdv {


/// <summary>
/// �G���f�B�A���𑊌ݕϊ�����
/// </summary>
/// <param name="val">
/// 16bit�����Ȃ�����
/// </param>
/// <returns>
/// �G���f�B�A�����ϊ������l
/// </returns>
constexpr uint16 ConvertEndian(uint16 val)noexcept;



/// <summary>
/// �G���f�B�A���𑊌ݕϊ�����
/// </summary>
/// <param name="val">
/// 16bit�������萮��
/// </param>
/// <returns>
/// �G���f�B�A�����ϊ������l
/// </returns>
constexpr int16 ConvertEndian(int16 val)noexcept;



/// <summary>
/// �G���f�B�A���𑊌ݕϊ�����
/// </summary>
/// <param name="val">
/// 32bit�����Ȃ�����
/// </param>
/// <returns>
/// �G���f�B�A�����ϊ������l
/// </returns>
constexpr uint32 ConvertEndian(uint32 val)noexcept;


/// <summary>
/// �G���f�B�A���𑊌ݕϊ�����
/// </summary>
/// <param name="val">
/// 64bit�����Ȃ�����
/// </param>
/// <returns>
/// �G���f�B�A�����ϊ������l
/// </returns>
constexpr uint64 ConvertEndian(uint64 val)noexcept;







/// <summary>
/// ����1�ł����r�b�g�̐����J�E���g����
/// </summary>
/// <param name="value">
/// 8bit�����Ȃ�����
/// </param>
/// <returns>
/// ����1���Z�b�g�����Ă����r�b�g�̐�
/// </returns>
constexpr int BitCount(uint8 value)noexcept;


/// <summary>
/// ����1�ł����r�b�g�̐����J�E���g����
/// </summary>
/// <param name="value">
/// 16bit�����Ȃ�����
/// </param>
/// <returns>
/// ����1���Z�b�g�����Ă����r�b�g�̐�
/// </returns>
constexpr int BitCount(uint16 value)noexcept;


/// <summary>
/// ����1�ł����r�b�g�̐����J�E���g����
/// </summary>
/// <param name="value">
/// 32bit�����Ȃ�����
/// </param>
/// <returns>
/// ����1���Z�b�g�����Ă����r�b�g�̐�
/// </returns>
constexpr int BitCount(uint32 value)noexcept;


/// <summary>
/// ����1�ł����r�b�g�̐����J�E���g����
/// </summary>
/// <param name="value">
/// 64bit�����Ȃ�����
/// </param>
/// <returns>
/// ����1���Z�b�g�����Ă����r�b�g�̐�
/// </returns>
constexpr int BitCount(uint64 value)noexcept;






/// <summary>
/// ���͂��ꂽ���l�̍ŏ��ʃr�b�g�݂̂��c���ďo�͂����֐�
/// </summary>
/// <param name="value">
/// 8�r�b�g�����Ȃ�����
/// </param>
/// <returns>
/// �ŏ��ʃr�b�g�݂̂�1�̐��l
/// </returns>
constexpr int MostSignificantBit(uint8 value)noexcept;


/// <summary>
/// ���͂��ꂽ���l�̍ŏ��ʃr�b�g�݂̂��c���ďo�͂����֐�
/// </summary>
/// <param name="value">
/// 16�r�b�g�����Ȃ�����
/// </param>
/// <returns>
/// �ŏ��ʃr�b�g�݂̂�1�̐��l
/// </returns>
constexpr int MostSignificantBit(uint16 value)noexcept;


/// <summary>
/// ���͂��ꂽ���l�̍ŏ��ʃr�b�g�݂̂��c���ďo�͂����֐�
/// </summary>
/// <param name="value">
/// 32�r�b�g�����Ȃ�����
/// </param>
/// <returns>
/// �ŏ��ʃr�b�g�݂̂�1�̐��l
/// </returns>
constexpr int MostSignificantBit(uint32 value)noexcept;


/// <summary>
/// ���͂��ꂽ���l�̍ŏ��ʃr�b�g�݂̂��c���ďo�͂����֐�
/// </summary>
/// <param name="value">
/// 64�r�b�g�����Ȃ�����
/// </param>
/// <returns>
/// �ŏ��ʃr�b�g�݂̂�1�̐��l
/// </returns>
constexpr int MostSignificantBit(uint64 value)noexcept;




/// <summary>
/// �ŉ��ʃr�b�g���J�E���g�����֐�
/// </summary>
/// <param name="value">
/// 8�r�b�g�����Ȃ�����
/// </param>
/// <returns>
/// �ŉ��ʃr�b�g�̃J�E���g
/// </returns>
constexpr int LeastSignificantBit(uint8 value)noexcept;



/// <summary>
/// �ŉ��ʃr�b�g���J�E���g�����֐�
/// </summary>
/// <param name="value">
/// 16�r�b�g�����Ȃ�����
/// </param>
/// <returns>
/// �ŉ��ʃr�b�g�̃J�E���g
/// </returns>
constexpr int LeastSignificantBit(uint16 value)noexcept;



/// <summary>
/// �ŉ��ʃr�b�g���J�E���g�����֐�
/// </summary>
/// <param name="value">
/// 32�r�b�g�����Ȃ�����
/// </param>
/// <returns>
/// �ŉ��ʃr�b�g�̃J�E���g
/// </returns>
constexpr int LeastSignificantBit(uint32 value)noexcept;



/// <summary>
/// �ŉ��ʃr�b�g���J�E���g�����֐�
/// </summary>
/// <param name="value">
/// 64�r�b�g�����Ȃ�����
/// </param>
/// <returns>
/// �ŉ��ʃr�b�g�̃J�E���g
/// </returns>
constexpr int LeastSignificantBit(uint64 value)noexcept;

} // namespace gdv

#endif
