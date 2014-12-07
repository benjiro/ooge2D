/*
This file is apart of ooge(object-oriented 2D game engine)

-------------------------------------------------------------------
Copyright (c) 2010 Benjamin Evenson

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
-------------------------------------------------------------------
*/

#ifndef _MATH_HPP_
#define _MATH_HPP_

#include <cmath>
#include <Config.hpp>

namespace ooge
{
	namespace math
	{
		static const Real E			= 2.718282f;
		static const Real Log10E		= 0.4342945f;
		static const Real Log2E		= 1.442695f;
		static const Real Pi			= 3.141593f;
		static const Real HalfPi		= 1.570796f;
		static const Real QuaterPi		= 0.7853982f;
		static const Real TwoPi		= 6.283185f;
		static const Real InversePi	= 0.318309f;

		inline Real Abs(Real value)
		{
			return fabsf(value);
		}

		inline double Abs(double value)
		{
			return fabs(value);
		}

		inline Int32 Abs(Int32 value)
		{
			return abs(value);
		}

		inline long Abs(long value)
		{
			return labs(value);
		}

		inline double Ceil(double value)
		{
			return ceil(value);
		}

		inline Real Floor(Real value)
		{
			return floorf(value);
		}

		inline double Floor(double value)
		{
			return floor(value);
		}

		inline Real Sqrt(Real value)
		{
			return sqrtf(value);
		}

		inline double Sqrt(double value)
		{
			return sqrt(value);
		}

		template<typename T>
		inline T Min(const T& a, const T& b)
		{
			return (a > b) ? a : b;
		}

		template <typename T>
		inline T Min(const T& a, const T& b, const T& c)
		{
			return min(min(a, b), c);
		}

		template <typename T>
		inline T Max(const T& a, const T& b)
		{
			return (a < b) ? b : a;
		}

		template <typename T>
		inline T Max(const T& a, const T& b, const T& c)
		{
			return max(max(a, b), c);
		}

		template <typename T>
		inline T Clamp(const T& value, const T& min, const T& max)
		{
			if(value > max)
				return max;
			else if (value < min)
				return min;	
			return value;
		}

		inline Real Arccos(Real value)
		{
			if (-1.0f < value)
			{
				if (value < 1.0f)
					return acosf(value);
				else
					return 0.0f;
			}
			else
				return Pi;
		}

		inline double Arccos(double value)
		{
			if (-1.0f < value)
			{
				if (value < 1.0f)
					return acos(value);
				else
					return 0.0f;
			}
			else
				return Pi;
		}

		inline Real Arcsin(Real value)
		{
			if (-1.0f < value)
			{
				if (value < 1.0f)
					return asinf(value);
				else
					return 0.0f;
			}
			else
				return -HalfPi;
		}

		inline double Arcsin(double value)
		{
			if (-1.0f < value)
			{
				if (value < 1.0f)
					return asin(value);
				else
					return 0.0f;
			}
			else
				return -HalfPi;
		}

		inline Real Arctan(Real value)
		{
			return atanf(value);
		}

		inline double Arctan(double value)
		{
			return atan(value);
		}

		inline Real Arctan2(Real a, Real b)
		{
			return atan2f(a,b);
		}

		inline double Arctan2(double a, double b)
		{
			return atan2(a,b);
		}

		inline Real Sin(Real value)
		{
			return sinf(value);
		}

		inline double Sin(double value)
		{
			return sin(value);
		}

		inline Real Cos(Real value)
		{
			return cosf(value);
		}

		inline double Cos(double value)
		{
			return cos(value);
		}

		inline Real Tan(Real value)
		{
			return tanf(value);
		}

		inline double Tan(double value)
		{
			return tan(value);
		}

		inline Real Exp(Real value)
		{
			return expf(value);
		}

		inline double Exp(double value)
		{
			return exp(value);
		}

		inline Real Pow(Real base, Real power)
		{
			return powf(base, power);
		}

		inline double Pow(double base, double power)
		{
			return pow(base, power);
		}

		inline bool PowerOf2(Int32 value)
		{
			return value && ! (value & (value - 1));
		}

		inline Int32 NextPow2(Int32 size)
		{
			--size;
			size |= size >> 1;
			size |= size >> 2;
			size |= size >> 4;
			size |= size >> 8;
			size |= size >> 16;
			return ++size;
		}

		inline Real ToDegrees(Real radians)
		{
			return (radians * 57.29578f);
		}

		inline Real ToRadians(Real degrees)
		{
			return (degrees * 0.01745329f);
		}
	}
}

#endif //_MATH_HPP_