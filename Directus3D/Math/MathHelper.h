/*
Copyright(c) 2016 Panos Karabelas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is furnished
to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

// It's not used here but it will provide functionality
// to any code that includes this header.
//= INCLUDES ==============
#include <cmath>
#include <limits>
#include "../Core/Helper.h"
//=========================

namespace Directus
{
	namespace Math
	{
		static const float M_EPSILON = 0.000001f;
		static const float PI = 3.14159265358979323846264338327950288f;
		static const float PI_2 = 6.283185307f;
		static const float PI_DIV_2 = 1.570796327f;
		static const float PI_DIV_4 = 0.785398163f;
		static const float PI_INV = 0.318309886f;
		static const float DEG_TO_RAD = PI / 180.0f;
		static const float DEG_TO_RAD_2 = PI / 360.0f;
		static const float RAD_TO_DEG = 180.0f / PI;

		inline DllExport double Cot(float x) { return cos(x) / sin(x); }
		inline DllExport float CotF(float x) { return cosf(x) / sinf(x); }
		inline DllExport float DegreesToRadians(float degrees){ return degrees * DEG_TO_RAD; }
		inline DllExport float RadiansToDegrees(float radians) { return radians * RAD_TO_DEG; }
		template <typename T>
		inline DllExport float Clamp(T x, T a, T b) { return x < a ? a : (x > b ? b : x); }

		// Lerp linearly between to values
		template <class T, class U>
		T Lerp(T lhs, T rhs, U t) { return lhs * (1.0 - t) + rhs * t; }

		// Returns the absolute value
		template <class T>
		T Abs(T value) { return value >= 0.0 ? value : -value; }

		// Check for equality but allow for a small error
		template <class T>
		bool Equals(T lhs, T rhs) { return lhs + std::numeric_limits<T>::epsilon() >= rhs && lhs - std::numeric_limits<T>::epsilon() <= rhs; }
	}
}
