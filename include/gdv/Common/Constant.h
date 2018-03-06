#ifndef GDV_CONSTANT_H_
#define GDV_CONSTANT_H_

namespace gdv {

//関数の戻り値
enum ReturnState : int {
	RETURN_FAILED	= 0,	//正常終了
	RETURN_SUCCESS	= 1,	//異常終了
};


} // namespace gdv

#endif
