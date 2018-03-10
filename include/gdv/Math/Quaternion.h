#ifndef GDV_QUATERNION_H_
#define GDV_QUATERNION_H_


#include <type_traits>
#include "gdv/Math/Vector3.h"
#include "gdv/Math/Matrix4x4.h"
#include "gdv/Math/Euler.h"

namespace gdv {

template<class Ty>
class Quaternion {
    static_assert(std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

    Quaternion() noexcept :
        t{},x{},y{},z{} {}


    Quaternion(Ty t, Ty x, Ty y, Ty z) noexcept :
        t{t},x{x},y{y},z{z} {}


    Quaternion(Vector3<Ty> v, Ty angle) noexcept :
        t{},x{},y{},z{} {
        Vector3<Ty> v0 = Normalize(v);
        Ty c = cos(static_cast<Ty>(0.5) * angle);
        Ty s = sin(static_cast<Ty>(0.5) * angle);
        t = c;
        x = v0.x * s;
        y = v0.y * s;
        z = v0.z * s;
    }




    Quaternion(Euler<Ty> e) noexcept :
        t{},x{},y{},z{} {
        Ty t0 = cos(e.z * static_cast<Ty>(0.5));
        Ty t1 = sin(e.z * static_cast<Ty>(0.5));
        Ty t2 = cos(e.x * static_cast<Ty>(0.5));
        Ty t3 = sin(e.x * static_cast<Ty>(0.5));
        Ty t4 = cos(e.y * static_cast<Ty>(0.5));
        Ty t5 = sin(e.y * static_cast<Ty>(0.5));

        t = t0 * t2 * t4 + t1 * t3 * t5;
        x = t0 * t3 * t4 - t1 * t2 * t5;
        y = t0 * t2 * t5 + t1 * t3 * t4;
        z = t1 * t2 * t4 - t0 * t3 * t5;
    }



    Quaternion(const Quaternion<Ty>& q) noexcept :
        t{q.t},x{q.x},y{q.y},z{q.z} {}



    Quaternion<Ty>& operator = (const Quaternion<Ty> &v) noexcept = default;


    Quaternion<Ty>& operator = (const Euler<Ty> &e) noexcept {
        *this = Quaternion<Ty>{e};
        return *this;
    }



    operator Euler<Ty>() noexcept {
        Euler<Ty> e;
        Ty t0 = static_cast<Ty>(2) * (t * x + y * z);
        Ty t1 = static_cast<Ty>(1) - static_cast<Ty>(2) * (x * x + y * y);
        e.x = atan2(t0, t1);

        t0 = static_cast<Ty>(2) * (t * y - z * x);
        t0 = t0 > static_cast<Ty>(1)  ? static_cast<Ty>(1)  : t0;
        t0 = t0 < static_cast<Ty>(-1) ? static_cast<Ty>(-1) : t0;
        e.y = asin(t0);

        t0 = static_cast<Ty>(2) * (t * z + x * y);
        t1 = static_cast<Ty>(1) - static_cast<Ty>(2) * (y * y + z * z);
        e.z = atan2(t0, t1);
        return e;
    }


public:
    Ty t;
    Ty x;
    Ty y;
    Ty z;
};


namespace ColumnMajor {
namespace RH {

template <class Ty>
Matrix4x4<Ty> ToMatrix(Quaternion<Ty> q) noexcept {
    return {
        1 - 2 * q.y * q.y - 2 * q.z * q.z,
        2 * q.x * q.y + 2 * q.t * q.z,
        2 * q.x * q.z - 2 * q.t * q.y,
        0,
        2 * q.x * q.y - 2 * q.t * q.z,
        1 - 2 * q.x * q.x - 2 * q.z * q.z,
        2 * q.y * q.z + 2 * q.t * q.x,
        0,
        2 * q.x * q.z + 2 * q.t * q.y,
        2 * q.y * q.z - 2 * q.t * q.x,
        1 - 2 * q.x * q.x - 2 * q.y * q.y,
        0,
        0,
        0,
        0,
        1,
    };
}

template<class Ty>
Quaternion<Ty> operator * (Quaternion<Ty> q1, Quaternion<Ty> q2) noexcept {
    Quaternion<Ty> q{};
    Ty a0, a1, a2, a3;

    a0 = q1.t * q2.t;
    a1 = q1.x * q2.x;
    a2 = q1.y * q2.y;
    a3 = q1.z * q2.z;
    q.t = a0 - a1 - a2 - a3;

    a0 = q1.t * q2.x;
    a1 = q1.x * q2.t;
    a2 = q1.y * q2.z;
    a3 = q1.z * q2.y;
    q.x = a0 + a1 + a2 - a3;

    a0 = q1.t * q2.y;
    a1 = q1.y * q2.t;
    a2 = q1.z * q2.x;
    a3 = q1.x * q2.z;
    q.y = a0 + a1 + a2 - a3;

    a0 = q1.t * q2.z;
    a1 = q1.z * q2.t;
    a2 = q1.x * q2.y;
    a3 = q1.y * q2.x;
    q.z = a0 + a1 + a2 - a3;

    return q;
}

template<class Ty>
Vector3<Ty> operator * (const Vector3<Ty> v, const Quaternion<Ty> q) noexcept {
    Quaternion<Ty> a = q * Quaternion<Ty>{0, v.x, v.y, v.z} * Quaternion<Ty>{q.t, -q.x, -q.y, -q.z};
    return {a.x, a.y, a.z};
}


template<class Ty>
Matrix4x4<Ty> operator * (const Matrix4x4<Ty> m, const Quaternion<Ty> q) noexcept {
    return m * ToMatrix(q);
}

} // namespace RH

namespace LH {
template <class Ty>
Matrix4x4<Ty> ToMatrix(Quaternion<Ty> q) noexcept {
    return {
        1 - 2 * q.y * q.y - 2 * q.z * q.z,
        2 * q.x * q.y - 2 * q.t * q.z,
        2 * q.x * q.z + 2 * q.t * q.y,
        0,
        2 * q.x * q.y + 2 * q.t * q.z,
        1 - 2 * q.x * q.x - 2 * q.z * q.z,
        2 * q.y * q.z - 2 * q.t * q.x,
        0,
        2 * q.x * q.z - 2 * q.t * q.y,
        2 * q.y * q.z + 2 * q.t * q.x,
        1 - 2 * q.x * q.x - 2 * q.y * q.y,
        0,
        0,
        0,
        0,
        1,
    };
}

template<class Ty>
Quaternion<Ty> operator * (Quaternion<Ty> q1, Quaternion<Ty> q2) noexcept {
    Quaternion<Ty> q{};
    Ty a0, a1, a2, a3;

    a0 = q1.t * q2.t;
    a1 = q1.x * q2.x;
    a2 = q1.y * q2.y;
    a3 = q1.z * q2.z;
    q.t = a0 - a1 - a2 - a3;

    a0 = q1.t * q2.x;
    a1 = q1.x * q2.t;
    a2 = q1.y * q2.z;
    a3 = q1.z * q2.y;
    q.x = a0 + a1 - a2 + a3;

    a0 = q1.t * q2.y;
    a1 = q1.y * q2.t;
    a2 = q1.z * q2.x;
    a3 = q1.x * q2.z;
    q.y = a0 + a1 - a2 + a3;

    a0 = q1.t * q2.z;
    a1 = q1.z * q2.t;
    a2 = q1.x * q2.y;
    a3 = q1.y * q2.x;
    q.z = a0 + a1 - a2 + a3;

    return q;
}


template<class Ty>
Vector3<Ty> operator * (const Vector3<Ty> v, const Quaternion<Ty> q) noexcept {
    Quaternion<Ty> a = Quaternion<Ty>{q.t, q.x, q.y, q.z} * Quaternion<Ty>{0, v.x, v.y, v.z} * Quaternion<Ty>{q.t, -q.x, -q.y, -q.z};
    return {a.x, a.y, a.z};
}

template<class Ty>
Matrix4x4<Ty> operator * (const Matrix4x4<Ty> m, const Quaternion<Ty> q) noexcept {
    return m * ToMatrix(q);
}

} // namespace LH
} // namespace ColumnMajor


namespace RowMajor {
namespace RH {

template <class Ty>
Matrix4x4<Ty> ToMatrix(Quaternion<Ty> q) noexcept {
    return {
        1 - 2 * q.y * q.y - 2 * q.z * q.z,
        2 * q.x * q.y - 2 * q.t * q.z,
        2 * q.x * q.z + 2 * q.t * q.y,
        0,
        2 * q.x * q.y + 2 * q.t * q.z,
        1 - 2 * q.x * q.x - 2 * q.z * q.z,
        2 * q.y * q.z - 2 * q.t * q.x,
        0,
        2 * q.x * q.z - 2 * q.t * q.y,
        2 * q.y * q.z + 2 * q.t * q.x,
        1 - 2 * q.x * q.x - 2 * q.y * q.y,
        0,
        0,
        0,
        0,
        1,
    };
}

template<class Ty>
Quaternion<Ty> operator * (Quaternion<Ty> q1, Quaternion<Ty> q2) noexcept {
    Quaternion<Ty> q{};
    Ty a0, a1, a2, a3;

    a0 = q1.t * q2.t;
    a1 = q1.x * q2.x;
    a2 = q1.y * q2.y;
    a3 = q1.z * q2.z;
    q.t = a0 - a1 - a2 - a3;

    a0 = q1.t * q2.x;
    a1 = q1.x * q2.t;
    a2 = q1.y * q2.z;
    a3 = q1.z * q2.y;
    q.x = a0 + a1 + a2 - a3;

    a0 = q1.t * q2.y;
    a1 = q1.y * q2.t;
    a2 = q1.z * q2.x;
    a3 = q1.x * q2.z;
    q.y = a0 + a1 + a2 - a3;

    a0 = q1.t * q2.z;
    a1 = q1.z * q2.t;
    a2 = q1.x * q2.y;
    a3 = q1.y * q2.x;
    q.z = a0 + a1 + a2 - a3;

    return q;
}

template<class Ty>
Vector3<Ty> operator * (const Vector3<Ty> v, const Quaternion<Ty> q) noexcept {
    Quaternion<Ty> a = q * Quaternion<Ty>{0, v.x, v.y, v.z} * Quaternion<Ty>{q.t, -q.x, -q.y, -q.z};
    return {a.x, a.y, a.z};
}


template<class Ty>
Matrix4x4<Ty> operator * (const Quaternion<Ty> q, const Matrix4x4<Ty> m) noexcept {
    return ToMatrix(q) * m;
}

} // namesapce RH



namespace LH {

template <class Ty>
Matrix4x4<Ty> ToMatrix(Quaternion<Ty> q) noexcept {
    return {
        1 - 2 * q.y * q.y - 2 * q.z * q.z,
        2 * q.x * q.y + 2 * q.t * q.z,
        2 * q.x * q.z - 2 * q.t * q.y,
        0,
        2 * q.x * q.y - 2 * q.t * q.z,
        1 - 2 * q.x * q.x - 2 * q.z * q.z,
        2 * q.y * q.z + 2 * q.t * q.x,
        0,
        2 * q.x * q.z + 2 * q.t * q.y,
        2 * q.y * q.z - 2 * q.t * q.x,
        1 - 2 * q.x * q.x - 2 * q.y * q.y,
        0,
        0,
        0,
        0,
        1,
    };
}


template<class Ty>
Quaternion<Ty> operator * (Quaternion<Ty> q1, Quaternion<Ty> q2) noexcept {
    Quaternion<Ty> q{};
    Ty a0, a1, a2, a3;

    a0 = q1.t * q2.t;
    a1 = q1.x * q2.x;
    a2 = q1.y * q2.y;
    a3 = q1.z * q2.z;
    q.t = a0 - a1 - a2 - a3;

    a0 = q1.t * q2.x;
    a1 = q1.x * q2.t;
    a2 = q1.y * q2.z;
    a3 = q1.z * q2.y;
    q.x = a0 + a1 - a2 + a3;

    a0 = q1.t * q2.y;
    a1 = q1.y * q2.t;
    a2 = q1.z * q2.x;
    a3 = q1.x * q2.z;
    q.y = a0 + a1 - a2 + a3;

    a0 = q1.t * q2.z;
    a1 = q1.z * q2.t;
    a2 = q1.x * q2.y;
    a3 = q1.y * q2.x;
    q.z = a0 + a1 - a2 + a3;

    return q;
}


template<class Ty>
Vector3<Ty> operator * (const Vector3<Ty> v, const Quaternion<Ty> q) noexcept {
    Quaternion<Ty> a = Quaternion<Ty>{q.t, q.x, q.y, q.z} * Quaternion<Ty>{0, v.x, v.y, v.z} * Quaternion<Ty>{q.t, -q.x, -q.y, -q.z};
    return {a.x, a.y, a.z};
}


template<class Ty>
Matrix4x4<Ty> operator * (const Quaternion<Ty> q, const Matrix4x4<Ty> m) noexcept {
    return ToMatrix(q) * m;
}

} // namespace LH
} // namespace RowMajor



using Rotate = Quaternion<float>;

} // namespace gdv

#endif
