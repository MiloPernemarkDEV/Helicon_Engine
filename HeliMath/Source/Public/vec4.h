#pragma once

#include "math_defines.h"
#include <cmath>
#include <algorithm>
#include "mat4x4.h"	
#include <cfloat>

struct Vec4 {

	float x, y, z, w;
	 
	constexpr Vec4(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{
	}

	constexpr Vec4()
		: x(0), y(0), z(0), w(0)
	{
	}

	HELI_FORCE_INLINE constexpr Vec4 operator*(const Mat4x4& a) const noexcept {
		return Vec4(
			(x * a.m11) + (y * a.m21) + (z * a.m31) + (w * a.m41),
			(x * a.m12) + (y * a.m22) + (z * a.m32) + (w * a.m42),
			(x * a.m13) + (y * a.m23) + (z * a.m33) + (w * a.m43),
			(x * a.m14) + (y * a.m24) + (z * a.m34) + (w * a.m44)
		);
	}


	HELI_FORCE_INLINE constexpr Vec4 operator+(const Vec4& other) const
	{
		return Vec4(
			x + other.x,
			y + other.y,
			z + other.z,
			w + other.w
		);
	}


	HELI_FORCE_INLINE constexpr Vec4 operator-(const Vec4& other) const
	{
		return Vec4(
			x - other.x,
			y - other.y,
			z - other.z,
			w - other.w
		);
	}
	HELI_FORCE_INLINE constexpr Vec4 operator-() const
	{
		return Vec4(-x, -y, -z, -w);
	}


	HELI_FORCE_INLINE Vec4 operator*(const Vec4& other) const
	{
		return Vec4(
			x * other.x,
			y * other.y,
			z * other.z,
			w * other.w
		);
	}

	HELI_FORCE_INLINE Vec4 operator*(float s) const
	{
		return Vec4(
			x * s,
			y * s,
			z * s,
			w * s
		);
	}

	HELI_FORCE_INLINE bool operator ==(const Vec4& other) const
	{
		return (is_float_close_enough(x, other.x) && is_float_close_enough(y, other.y) && is_float_close_enough(z, other.z));
	}

	HELI_FORCE_INLINE  static bool is_float_close_enough(float a, float b, float precision = 1e-4f)
	{
		return std::abs(b - a) <= precision;
	}
};

HELI_FORCE_INLINE Vec4 operator*(float s, const Vec4& v)
{
	return v * s;
}