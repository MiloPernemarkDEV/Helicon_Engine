#pragma once 

#include "math_defines.h"
#include <cmath>

namespace MathUtil {
	HELI_FORCE_INLINE static bool is_nearly_equal(float a, float b, float epsilon = 1e-5f)
	{
		return std::abs(a - b) <= epsilon;
	}
}


