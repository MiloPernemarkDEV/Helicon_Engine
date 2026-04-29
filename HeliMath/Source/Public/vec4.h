#pragma once

#include "math_defines.h"
#include <cmath>
#include <algorithm>
#include <cfloat>

struct vec4 {

	float x, y, z, w;
	 
	constexpr vec4(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{
	}

	constexpr vec4()
		: x(0), y(0), z(0), w(0)
	{
	}


	HELI_FORCE_INLINE constexpr vec4 operator+(const vec4& other) const
	{
		return vec4(
			x + other.x,
			y + other.y,
			z + other.z,
			w + other.w
		);
	}


	HELI_FORCE_INLINE constexpr vec4 operator-(const vec4& other) const
	{
		return vec4(
			x - other.x,
			y - other.y,
			z - other.z,
			w - other.w
		);
	}
	HELI_FORCE_INLINE constexpr vec4 operator-() const
	{
		return vec4(-x, -y, -z, -w);
	}


	HELI_FORCE_INLINE vec4 operator*(const vec4& other) const
	{
		return vec4(
			x * other.x,
			y * other.y,
			z * other.z,
			w * other.w
		);
	}

	HELI_FORCE_INLINE vec4 operator*(float s) const
	{
		return vec4(
			x * s,
			y * s,
			z * s,
			w * s
		);
	}

	HELI_FORCE_INLINE bool operator ==(const vec4& other) const
	{
		return (is_float_close_enough(x, other.x) && is_float_close_enough(y, other.y) && is_float_close_enough(z, other.z));
	}

	HELI_FORCE_INLINE  static bool is_float_close_enough(float a, float b, float precision = 1e-4f)
	{
		return std::abs(b - a) <= precision;
	}
};

HELI_FORCE_INLINE vec4 operator*(float s, const vec4& v)
{
	return v * s;
}