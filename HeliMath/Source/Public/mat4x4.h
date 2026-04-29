#pragma once 

// A matrix is an array of vectors that is arragned into rows and columns 

#include "math_defines.h"
#include "vec3.h"
#include <cmath>

struct Mat4x4 {
	// Column major for OpenGL 
	// m[column][row] 
	float m11, m12, m13, m14,
		  m21, m22, m23, m24,
		  m31, m32, m33, m34,
		  m41, m42, m43, m44;

	HELI_FORCE_INLINE Mat4x4() 
		: m11(1.0f), m12(0.0f), m13(0.0f), m14(0.0f),
		  m21(1.0f), m22(0.0f), m23(0.0f), m24(0.0f),
		  m31(1.0f), m32(0.0f), m33(0.0f), m34(0.0f),
		  m41(1.0f), m42(0.0f), m43(0.0f), m44(0.0f)
	{

	}

	
};