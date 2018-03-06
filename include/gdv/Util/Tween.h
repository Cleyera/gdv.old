#ifndef TWEEN_HEADER_
#define TWEEN_HEADER_

#include <math.h>
#include "gdv/Math/MathConstant.h"
#include "gdv/Math/Vector2.h"
#include "gdv/Math/Vector3.h"
#include "gdv/Math/Vector4.h"

namespace gdv {

namespace Tween {

template <class Ty>
Ty Linear(Ty begin, Ty end, Ty ratio) noexcept {
	return (end - begin) * ratio + begin;
}

template <class Ty>
Ty Linear(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return (end - begin) * ratio + begin;
}

template <class Ty>
Ty Linear(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return (end - begin) * ratio + begin;
}

template <class Ty>
Ty Linear(Vector4<Ty> begin, Vector4<Ty> end, Ty ratio) noexcept {
	return (end - begin) * ratio + begin;
}




template <class Ty>
Ty InQuad(Ty begin, Ty end, Ty ratio) noexcept {
	return (end - begin) * ratio * ratio + begin;
}

template <class Ty>
Ty OutQuad(Ty begin, Ty end, Ty ratio) noexcept {
	return (end - begin) * (ratio * (ratio - 2) - 1) + begin;
}

template <class Ty>
Ty InOutQuad(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return InQuad(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (OutQuad(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty OutInQuad(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return OutQuad(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (InQuad(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Vector2<Ty> InQuad(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InQuad(begin.x, end.x, ratio),
		InQuad(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutQuad(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutQuad(begin.x, end.x, ratio),
		OutQuad(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> InOutQuad(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InOutQuad(begin.x, end.x, ratio),
		InOutQuad(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutInQuad(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutInQuad(begin.x, end.x, ratio),
		OutInQuad(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector3<Ty> InQuad(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InQuad(begin.x, end.x, ratio),
		InQuad(begin.y, end.y, ratio),
		InQuad(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutQuad(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutQuad(begin.x, end.x, ratio),
		OutQuad(begin.y, end.y, ratio),
		OutQuad(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> InOutQuad(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InOutQuad(begin.x, end.x, ratio),
		InOutQuad(begin.y, end.y, ratio),
		InOutQuad(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutInQuad(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutInQuad(begin.x, end.x, ratio),
		OutInQuad(begin.y, end.y, ratio),
		OutInQuad(begin.z, end.z, ratio)
	};
}







template <class Ty>
Ty InCubic(Ty begin, Ty end, Ty ratio) noexcept {
	return (end - begin) * ratio * ratio * ratio + begin;
}

template <class Ty>
Ty OutCubic(Ty begin, Ty end, Ty ratio) noexcept {
	ratio -= static_cast<Ty>(1);
	return (end - begin) * (ratio * ratio * ratio + static_cast<Ty>(1)) + begin;
}

template <class Ty>
Ty InOutCubic(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return InCubic(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (OutCubic(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty OutInCubic(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return OutCubic(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (InCubic(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Vector2<Ty> InCubic(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InCubic(begin.x, end.x, ratio),
		InCubic(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutCubic(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutCubic(begin.x, end.x, ratio),
		OutCubic(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> InOutCubic(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InOutCubic(begin.x, end.x, ratio),
		InOutCubic(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutInCubic(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutInCubic(begin.x, end.x, ratio),
		OutInCubic(begin.y, end.y, ratio)
	};
}
template <class Ty>
Vector3<Ty> InCubic(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InCubic(begin.x, end.x, ratio),
		InCubic(begin.y, end.y, ratio),
		InCubic(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutCubic(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutCubic(begin.x, end.x, ratio),
		OutCubic(begin.y, end.y, ratio),
		OutCubic(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> InOutCubic(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InOutCubic(begin.x, end.x, ratio),
		InOutCubic(begin.y, end.y, ratio),
		InOutCubic(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutInCubic(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutInCubic(begin.x, end.x, ratio),
		OutInCubic(begin.y, end.y, ratio),
		OutInCubic(begin.z, end.z, ratio)
	};
}








template <class Ty>
Ty InQuart(Ty begin, Ty end, Ty ratio) noexcept {
	return (end - begin) * ratio * ratio * ratio * ratio + begin;
}

template <class Ty>
Ty OutQuart(Ty begin, Ty end, Ty ratio) noexcept {
	ratio -= static_cast<Ty>(1);
	return (end - begin) * (ratio * ratio * ratio * ratio - static_cast<Ty>(1)) + begin;
}

template <class Ty>
Ty InOutQuart(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return InQuart(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (OutQuart(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty OutInQuart(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return OutQuart(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (InQuart(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Vector2<Ty> InQuart(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InQuart(begin.x, end.x, ratio),
		InQuart(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutQuart(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutQuart(begin.x, end.x, ratio),
		OutQuart(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> InOutQuart(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InOutQuart(begin.x, end.x, ratio),
		InOutQuart(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutInQuart(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutInQuart(begin.x, end.x, ratio),
		OutInQuart(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector3<Ty> InQuart(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InQuart(begin.x, end.x, ratio),
		InQuart(begin.y, end.y, ratio),
		InQuart(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutQuart(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutQuart(begin.x, end.x, ratio),
		OutQuart(begin.y, end.y, ratio),
		OutQuart(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> InOutQuart(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InOutQuart(begin.x, end.x, ratio),
		InOutQuart(begin.y, end.y, ratio),
		InOutQuart(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutInQuart(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutInQuart(begin.x, end.x, ratio),
		OutInQuart(begin.y, end.y, ratio),
		OutInQuart(begin.z, end.z, ratio)
	};
}









template <class Ty>
Ty InQuint(Ty begin, Ty end, Ty ratio) noexcept {
	return (end - begin) * ratio * ratio * ratio * ratio * ratio + begin;
}

template <class Ty>
Ty OutQuint(Ty begin, Ty end, Ty ratio) noexcept {
	ratio -= static_cast<Ty>(1);
	return (end - begin) * (ratio * ratio * ratio * ratio * ratio + static_cast<Ty>(1)) + begin;
}

template <class Ty>
Ty InOutQuint(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return InQuint(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (OutQuint(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty OutInQuint(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return OutQuint(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (InQuint(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Vector2<Ty> InQuint(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InQuint(begin.x, end.x, ratio),
		InQuint(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutQuint(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutQuint(begin.x, end.x, ratio),
		OutQuint(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> InOutQuint(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InOutQuint(begin.x, end.x, ratio),
		InOutQuint(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutInQuint(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutInQuint(begin.x, end.x, ratio),
		OutInQuint(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector3<Ty> InQuint(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InQuint(begin.x, end.x, ratio),
		InQuint(begin.y, end.y, ratio),
		InQuint(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutQuint(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutQuint(begin.x, end.x, ratio),
		OutQuint(begin.y, end.y, ratio),
		OutQuint(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> InOutQuint(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InOutQuint(begin.x, end.x, ratio),
		InOutQuint(begin.y, end.y, ratio),
		InOutQuint(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutInQuint(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutInQuint(begin.x, end.x, ratio),
		OutInQuint(begin.y, end.y, ratio),
		OutInQuint(begin.z, end.z, ratio)
	};
}









template <class Ty>
Ty InSine(Ty begin, Ty end, Ty ratio) noexcept {
	end -= begin;
	return -end * cos(PI<Ty> * ratio) + begin + end;
}

template <class Ty>
Ty OutSine(Ty begin, Ty end, Ty ratio) noexcept {
	end -= begin;
	return end * sin(PI<Ty> * ratio) + begin;
}

template <class Ty>
Ty InOutSine(Ty begin, Ty end, Ty ratio) noexcept {
	end -= begin;
	return -end / static_cast<Ty>(2) * (cos(PI<Ty> * ratio) - static_cast<Ty>(1)) + begin;
}

template <class Ty>
Ty OutInSine(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return OutSine(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (InSine(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Vector2<Ty> InSine(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InSine(begin.x, end.x, ratio),
		InSine(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutSine(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutSine(begin.x, end.x, ratio),
		OutSine(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> InOutSine(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InOutSine(begin.x, end.x, ratio),
		InOutSine(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutInSine(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutInSine(begin.x, end.x, ratio),
		OutInSine(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector3<Ty> InSine(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InSine(begin.x, end.x, ratio),
		InSine(begin.y, end.y, ratio),
		InSine(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutSine(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutSine(begin.x, end.x, ratio),
		OutSine(begin.y, end.y, ratio),
		OutSine(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> InOutSine(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InOutSine(begin.x, end.x, ratio),
		InOutSine(begin.y, end.y, ratio),
		InOutSine(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutInSine(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutInSine(begin.x, end.x, ratio),
		OutInSine(begin.y, end.y, ratio),
		OutInSine(begin.z, end.z, ratio)
	};
}









template <class Ty>
Ty InExp(Ty begin, Ty end, Ty ratio) noexcept {
	end -= begin;
	return end * pow(static_cast<Ty>(2), static_cast<Ty>(10) * (ratio - 1)) + begin;
}

template <class Ty>
Ty OutExp(Ty begin, Ty end, Ty ratio) noexcept {
	end -= begin;
	return end * (static_cast<Ty>(1) - pow(static_cast<Ty>(2), static_cast<Ty>(-10) * ratio)) + begin;
}

template <class Ty>
Ty InOutExp(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return InExp(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (OutExp(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty OutInExp(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return OutExp(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (InExp(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Vector2<Ty> InExp(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InExp(begin.x, end.x, ratio),
		InExp(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutExp(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutExp(begin.x, end.x, ratio),
		OutExp(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> InOutExp(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InOutExp(begin.x, end.x, ratio),
		InOutExp(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutInExp(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutInExp(begin.x, end.x, ratio),
		OutInExp(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector3<Ty> InExp(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InExp(begin.x, end.x, ratio),
		InExp(begin.y, end.y, ratio),
		InExp(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutExp(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutExp(begin.x, end.x, ratio),
		OutExp(begin.y, end.y, ratio),
		OutExp(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> InOutExp(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InOutExp(begin.x, end.x, ratio),
		InOutExp(begin.y, end.y, ratio),
		InOutExp(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutInExp(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutInExp(begin.x, end.x, ratio),
		OutInExp(begin.y, end.y, ratio),
		OutInExp(begin.z, end.z, ratio)
	};
}







template <class Ty>
Ty InCirc(Ty begin, Ty end, Ty ratio) noexcept {
	end -= begin;
	return begin - end * (sqrt(static_cast<Ty>(1) - ratio * ratio) - static_cast<Ty>(1));
}

template <class Ty>
Ty OutCirc(Ty begin, Ty end, Ty ratio) noexcept {
	end -= begin;
	return end * sqrt(static_cast<Ty>(1) - ratio * ratio) + begin;
}

template <class Ty>
Ty InOutCirc(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return InCirc(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (OutCirc(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty OutInCirc(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return OutCirc(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (InCirc(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Vector2<Ty> InCirc(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InCirc(begin.x, end.x, ratio),
		InCirc(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutCirc(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutCirc(begin.x, end.x, ratio),
		OutCirc(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> InOutCirc(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InOutCirc(begin.x, end.x, ratio),
		InOutCirc(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutInCirc(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutInCirc(begin.x, end.x, ratio),
		OutInCirc(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector3<Ty> InCirc(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InCirc(begin.x, end.x, ratio),
		InCirc(begin.y, end.y, ratio),
		InCirc(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutCirc(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutCirc(begin.x, end.x, ratio),
		OutCirc(begin.y, end.y, ratio),
		OutCirc(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> InOutCirc(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InOutCirc(begin.x, end.x, ratio),
		InOutCirc(begin.y, end.y, ratio),
		InOutCirc(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutInCirc(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutInCirc(begin.x, end.x, ratio),
		OutInCirc(begin.y, end.y, ratio),
		OutInCirc(begin.z, end.z, ratio)
	};
}








template <class Ty>
Ty InBack(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
	end -= begin;
	return end * ratio * ratio * ((overshoot + static_cast<Ty>(1)) * ratio - overshoot) + end;
}

template <class Ty>
Ty OutBack(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
	end -= begin;
	return end * (ratio * ratio * ((overshoot + static_cast<Ty>(1)) * ratio * overshoot) + 1) + begin;
}

template <class Ty>
Ty InOutBack(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return InBack(begin, end, ratio * static_cast<Ty>(2), overshoot) * static_cast<Ty>(0.5);
	}
	return (OutBack(begin, end, ratio * static_cast<Ty>(2), overshoot) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty OutInBack(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return OutBack(begin, end, ratio * static_cast<Ty>(2), overshoot) * static_cast<Ty>(0.5);
	}
	return (InBack(begin, end, ratio * static_cast<Ty>(2), overshoot) + (end - begin)) * static_cast<Ty>(0.5);
}


template <class Ty>
Vector2<Ty> InBack(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio, Ty overshoot) noexcept {
	return {
		InBack(begin.x, end.x, ratio, overshoot),
		InBack(begin.y, end.y, ratio, overshoot)
	};
}

template <class Ty>
Vector2<Ty> OutBack(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio, Ty overshoot) noexcept {
	return {
		OutBack(begin.x, end.x, ratio, overshoot),
		OutBack(begin.y, end.y, ratio, overshoot)
	};
}

template <class Ty>
Vector2<Ty> InOutBack(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio, Ty overshoot) noexcept {
	return {
		InOutBack(begin.x, end.x, ratio, overshoot),
		InOutBack(begin.y, end.y, ratio, overshoot)
	};
}

template <class Ty>
Vector2<Ty> OutInBack(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio, Ty overshoot) noexcept {
	return {
		OutInBack(begin.x, end.x, ratio, overshoot),
		OutInBack(begin.y, end.y, ratio, overshoot)
	};
}

template <class Ty>
Vector3<Ty> InBack(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio, Ty overshoot) noexcept {
	return {
		InBack(begin.x, end.x, ratio, overshoot),
		InBack(begin.y, end.y, ratio, overshoot),
		InBack(begin.z, end.z, ratio, overshoot)
	};
}

template <class Ty>
Vector3<Ty> OutBack(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio, Ty overshoot) noexcept {
	return {
		OutBack(begin.x, end.x, ratio, overshoot),
		OutBack(begin.y, end.y, ratio, overshoot),
		OutBack(begin.z, end.z, ratio, overshoot)
	};
}

template <class Ty>
Vector3<Ty> InOutBack(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio, Ty overshoot) noexcept {
	return {
		InOutBack(begin.x, end.x, ratio, overshoot),
		InOutBack(begin.y, end.y, ratio, overshoot),
		InOutBack(begin.z, end.z, ratio, overshoot)
	};
}

template <class Ty>
Vector3<Ty> OutInBack(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio, Ty overshoot) noexcept {
	return {
		OutInBack(begin.x, end.x, ratio, overshoot),
		OutInBack(begin.y, end.y, ratio, overshoot),
		OutInBack(begin.z, end.z, ratio, overshoot)
	};
}





template <class Ty>
Ty InElastic(Ty begin, Ty end, Ty ratio) noexcept {
	end -= begin;
	return end * sin(static_cast<Ty>(13) * PI<Ty> * ratio) * pow(static_cast<Ty>(2), static_cast<Ty>(10) * (ratio - static_cast<Ty>(1))) + begin;
}

template <class Ty>
float OutElastic(Ty begin, Ty end, Ty ratio) noexcept {
	end -= begin;
	return end * sin(static_cast<Ty>(13) * PI<Ty> * ratio) * pow(static_cast<Ty>(2), static_cast<Ty>(-10) * ratio) + begin;
}

template <class Ty>
float InOutElastic(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return InElastic(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (OutElastic(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
float OutInElastic(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return OutElastic(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (InElastic(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Vector2<Ty> InElastic(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InElastic(begin.x, end.x, ratio),
		InElastic(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutElastic(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutElastic(begin.x, end.x, ratio),
		OutElastic(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> InOutElastic(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InOutElastic(begin.x, end.x, ratio),
		InOutElastic(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutInElastic(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutInElastic(begin.x, end.x, ratio),
		OutInElastic(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector3<Ty> InElastic(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InElastic(begin.x, end.x, ratio),
		InElastic(begin.y, end.y, ratio),
		InElastic(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutElastic(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutElastic(begin.x, end.x, ratio),
		OutElastic(begin.y, end.y, ratio),
		OutElastic(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> InOutElastic(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InOutElastic(begin.x, end.x, ratio),
		InOutElastic(begin.y, end.y, ratio),
		InOutElastic(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutInElastic(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutInElastic(begin.x, end.x, ratio),
		OutInElastic(begin.y, end.y, ratio),
		OutInElastic(begin.z, end.z, ratio)
	};
}







template <class Ty>
double OutBounce(Ty begin, Ty end, Ty ratio) noexcept {
	end -= begin;

	if (ratio < static_cast<Ty>(1.0 / 2.75)) {
		return end * (static_cast<Ty>(7.5625) * ratio * ratio) + begin;
	}
	else if (ratio < static_cast<Ty>(2.0 / 2.75)) {
		ratio -= static_cast<Ty>(1.5 / 2.75);
		return end * (static_cast<Ty>(7.5625) * ratio * ratio + static_cast<Ty>(0.75)) + begin;
	}
	else if (ratio < static_cast<Ty>(2.5 / 2.75)) {
		ratio -= static_cast<Ty>(2.25 / 2.75);
		return end * (static_cast<Ty>(7.5625) * ratio * ratio + static_cast<Ty>(0.9375)) + begin;
	}
	ratio -= static_cast<Ty>(2.625 / 2.75);
	return end * (static_cast<Ty>(7.5625) * ratio * ratio + static_cast<Ty>(0.984375)) + begin;
}

template <class Ty>
double InBounce(Ty begin, Ty end, Ty ratio) noexcept {
	return end - OutBounce(begin, end, ratio) + ratio;
}

template <class Ty>
double InOutBounce(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return InBounce(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (OutBounce(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
double OutInBounce(Ty begin, Ty end, Ty ratio) noexcept {
	if (ratio < static_cast<Ty>(0.5)) {
		return OutBounce(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
	}
	return (InBounce(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Vector2<Ty> InBounce(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InBounce(begin.x, end.x, ratio),
		InBounce(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutBounce(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutBounce(begin.x, end.x, ratio),
		OutBounce(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> InOutBounce(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		InOutBounce(begin.x, end.x, ratio),
		InOutBounce(begin.y, end.y, ratio)
	};
}

template <class Ty>
Vector2<Ty> OutInBounce(Vector2<Ty> begin, Vector2<Ty> end, Ty ratio) noexcept {
	return {
		OutInBounce(begin.x, end.x, ratio),
		OutInBounce(begin.y, end.y, ratio)
	};
}



template <class Ty>
Vector3<Ty> InBounce(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InBounce(begin.x, end.x, ratio),
		InBounce(begin.y, end.y, ratio),
		InBounce(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutBounce(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutBounce(begin.x, end.x, ratio),
		OutBounce(begin.y, end.y, ratio),
		OutBounce(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> InOutBounce(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		InOutBounce(begin.x, end.x, ratio),
		InOutBounce(begin.y, end.y, ratio),
		InOutBounce(begin.z, end.z, ratio)
	};
}

template <class Ty>
Vector3<Ty> OutInBounce(Vector3<Ty> begin, Vector3<Ty> end, Ty ratio) noexcept {
	return {
		OutInBounce(begin.x, end.x, ratio),
		OutInBounce(begin.y, end.y, ratio),
		OutInBounce(begin.z, end.z, ratio)
	};
}


} // namespace Tween
} // namespace gdv

#endif
