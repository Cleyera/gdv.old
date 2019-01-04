#ifndef GDV_QUATERNION_H_
#define GDV_QUATERNION_H_


#include <type_traits>
#include <gdv/math/vector3.h>
#include <gdv/math/matrix4x4.h>
#include <gdv/math/euler.h>

namespace gdv {

template <class Ty>
class quaternion {
    static_assert(std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

    quaternion() noexcept :
        t{},x{},y{},z{} {}


    quaternion(Ty t, Ty x, Ty y, Ty z) noexcept :
        t{t},x{x},y{y},z{z} {}


    quaternion(vector3<Ty> v, Ty angle) noexcept :
        t{},x{},y{},z{} {
        vector3<Ty> v0 = normalize(v);
        Ty c = std::cos(static_cast<Ty>(0.5) * angle);
        Ty s = std::sin(static_cast<Ty>(0.5) * angle);
        t = c;
        x = v0.x * s;
        y = v0.y * s;
        z = v0.z * s;
    }




    quaternion(euler<Ty> e) noexcept :
        t{},x{},y{},z{} {
        constexpr Ty half = static_cast<Ty>(0.5);
        Ty t0 = std::cos(e.z * half);
        Ty t1 = std::sin(e.z * half);
        Ty t2 = std::cos(e.x * half);
        Ty t3 = std::sin(e.x * half);
        Ty t4 = std::cos(e.y * half);
        Ty t5 = std::sin(e.y * half);

        t = t0 * t2 * t4 + t1 * t3 * t5;
        x = t0 * t3 * t4 - t1 * t2 * t5;
        y = t0 * t2 * t5 + t1 * t3 * t4;
        z = t1 * t2 * t4 - t0 * t3 * t5;
    }



    quaternion(const quaternion<Ty>& q) noexcept :
        t{q.t},x{q.x},y{q.y},z{q.z} {}



    quaternion<Ty>& operator = (const quaternion<Ty> &v) noexcept = default;


    quaternion<Ty>& operator = (const euler<Ty> &e) noexcept {
        *this = quaternion<Ty>{e};
        return *this;
    }



    operator euler<Ty>() noexcept {
        constexpr Ty _1 = static_cast<Ty>(1);
        constexpr Ty _2 = static_cast<Ty>(2);
        euler<Ty> e;
        Ty t0 = _2 * (t * x + y * z);
        Ty t1 = _1 - _2 * (x * x + y * y);
        e.x = std::atan2(t0, t1);

        t0 = _2 * (t * y - z * x);
        t0 = t0 > _1  ? _1  : t0;
        t0 = t0 < -_1 ? -_1 : t0;
        e.y = std::asin(t0);

        t0 = _2 * (t * z + x * y);
        t1 = _1 - _2 * (y * y + z * z);
        e.z = std::atan2(t0, t1);
        return e;
    }


public:
    Ty t;
    Ty x;
    Ty y;
    Ty z;
};


namespace column_major {
namespace right_hand {

template <class Ty>
matrix4x4<Ty> to_matrix(quaternion<Ty> q) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _1 - _2 * q.y * q.y - _2 * q.z * q.z,
        _2 * q.x * q.y + _2 * q.t * q.z,
        _2 * q.x * q.z - _2 * q.t * q.y,
        _0,
        _2 * q.x * q.y - _2 * q.t * q.z,
        _1 - _2 * q.x * q.x - _2 * q.z * q.z,
        _2 * q.y * q.z + _2 * q.t * q.x,
        _0,
        _2 * q.x * q.z + _2 * q.t * q.y,
        _2 * q.y * q.z - _2 * q.t * q.x,
        _1 - _2 * q.x * q.x - _2 * q.y * q.y,
        _0,
        _0,
        _0,
        _0,
        _1,
    };
}

template <class Ty>
quaternion<Ty> operator * (quaternion<Ty> q1, quaternion<Ty> q2) noexcept {
    quaternion<Ty> q{};
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

template <class Ty>
vector3<Ty> operator * (const quaternion<Ty> q, const vector3<Ty> v) noexcept {
    quaternion<Ty> a = q
                        * quaternion<Ty>{static_cast<Ty>(0), v.x, v.y, v.z}
                        * quaternion<Ty>{q.t, -q.x, -q.y, -q.z};
    return {a.x, a.y, a.z};
}


template <class Ty>
matrix4x4<Ty> operator * (const matrix4x4<Ty> m, const quaternion<Ty> q) noexcept {
    return m * to_matrix(q);
}

} // namespace right_hand

namespace left_hand {
template <class Ty>
matrix4x4<Ty> to_matrix(quaternion<Ty> q) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _1 - _2 * q.y * q.y - _2 * q.z * q.z,
        _2 * q.x * q.y - _2 * q.t * q.z,
        _2 * q.x * q.z + _2 * q.t * q.y,
        _0,
        _2 * q.x * q.y + _2 * q.t * q.z,
        _1 - _2 * q.x * q.x - _2 * q.z * q.z,
        _2 * q.y * q.z - _2 * q.t * q.x,
        _0,
        _2 * q.x * q.z - _2 * q.t * q.y,
        _2 * q.y * q.z + _2 * q.t * q.x,
        _1 - _2 * q.x * q.x - _2 * q.y * q.y,
        _0,
        _0,
        _0,
        _0,
        _1,
    };
}

template <class Ty>
quaternion<Ty> operator * (quaternion<Ty> q1, quaternion<Ty> q2) noexcept {
    quaternion<Ty> q{};
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


template <class Ty>
vector3<Ty> operator * (const quaternion<Ty> q, const vector3<Ty> v) noexcept {
    quaternion<Ty> a = quaternion<Ty>{q.t, q.x, q.y, q.z}
                        * quaternion<Ty>{static_cast<Ty>(0), v.x, v.y, v.z}
                        * quaternion<Ty>{q.t, -q.x, -q.y, -q.z};
    return {a.x, a.y, a.z};
}

template <class Ty>
matrix4x4<Ty> operator * (const matrix4x4<Ty> m, const quaternion<Ty> q) noexcept {
    return m * to_matrix(q);
}

} // namespace left_hand
} // namespace column_major


namespace row_major {
namespace right_hand {

template <class Ty>
matrix4x4<Ty> to_matrix(quaternion<Ty> q) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _1 - _2 * q.y * q.y - _2 * q.z * q.z,
        _2 * q.x * q.y - _2 * q.t * q.z,
        _2 * q.x * q.z + _2 * q.t * q.y,
        _0,
        _2 * q.x * q.y + _2 * q.t * q.z,
        _1 - _2 * q.x * q.x - _2 * q.z * q.z,
        _2 * q.y * q.z - _2 * q.t * q.x,
        _0,
        _2 * q.x * q.z - _2 * q.t * q.y,
        _2 * q.y * q.z + _2 * q.t * q.x,
        _1 - _2 * q.x * q.x - _2 * q.y * q.y,
        _0,
        _0,
        _0,
        _0,
        _1,
    };
}

template <class Ty>
quaternion<Ty> operator * (quaternion<Ty> q1, quaternion<Ty> q2) noexcept {
    quaternion<Ty> q{};
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

template <class Ty>
vector3<Ty> operator * (const vector3<Ty> v, const quaternion<Ty> q) noexcept {
    quaternion<Ty> a = q
                        * quaternion<Ty>{static_cast<Ty>(0), v.x, v.y, v.z}
                        * quaternion<Ty>{q.t, -q.x, -q.y, -q.z};
    return {a.x, a.y, a.z};
}


template <class Ty>
matrix4x4<Ty> operator * (const quaternion<Ty> q, const matrix4x4<Ty> m) noexcept {
    return to_matrix(q) * m;
}

} // namesapce right_hand



namespace left_hand {

template <class Ty>
matrix4x4<Ty> to_matrix(quaternion<Ty> q) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _1 - _2 * q.y * q.y - _2 * q.z * q.z,
        _2 * q.x * q.y + _2 * q.t * q.z,
        _2 * q.x * q.z - _2 * q.t * q.y,
        _0,
        _2 * q.x * q.y - _2 * q.t * q.z,
        _1 - _2 * q.x * q.x - _2 * q.z * q.z,
        _2 * q.y * q.z + _2 * q.t * q.x,
        _0,
        _2 * q.x * q.z + _2 * q.t * q.y,
        _2 * q.y * q.z - _2 * q.t * q.x,
        _1 - _2 * q.x * q.x - _2 * q.y * q.y,
        _0,
        _0,
        _0,
        _0,
        _1,
    };
}


template <class Ty>
quaternion<Ty> operator * (quaternion<Ty> q1, quaternion<Ty> q2) noexcept {
    quaternion<Ty> q{};
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


template <class Ty>
vector3<Ty> operator * (const vector3<Ty> v, const quaternion<Ty> q) noexcept {
    quaternion<Ty> a = quaternion<Ty>{q.t, q.x, q.y, q.z}
                         * quaternion<Ty>{static_cast<Ty>(0), v.x, v.y, v.z}
                         * quaternion<Ty>{q.t, -q.x, -q.y, -q.z};
    return {a.x, a.y, a.z};
}


template <class Ty>
matrix4x4<Ty> operator * (const quaternion<Ty> q, const matrix4x4<Ty> m) noexcept {
    return to_matrix(q) * m;
}

} // namespace left_hand
} // namespace row_major



using rotation = quaternion<float>;

} // namespace gdv

#endif
