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

#ifndef _VECTOR2_HPP_
#define _VECTOR2_HPP_

#include <Math.hpp>
#include <iostream>
#include <Config.hpp>

namespace ooge
{
	template<typename T>
	class OOGE_API Vector2T
	{
	public:
		T X, Y;

		inline Vector2T()
		{
			Set(0,0);
		}

		inline Vector2T(const T x1, const T y1) :	
			X(x1),
			Y(y1)
		{
		}

			inline Vector2T(const Vector2T &oVector) :
			X(oVector.X),
			Y(oVector.Y)
		{

		}

		template<typename Vector2T_class>
		explicit Vector2T(const Vector2T_class *oVector) :	
			X(p[0]),
			Y(p[1])
		{
		}

		inline const T operator [] (const size_t i) const
		{
			return (&X)[i];
		}

		inline T& operator [] (const size_t i)
		{			
			return (&X)[i];
		}

		inline T* ptr()
		{
			return &X;
		}


		inline const T* ptr() const
		{
			return &X;
		}

		inline Vector2T &operator = (const Vector2T &oVector)
		{
			X = oVector.X;
			Y = oVector.Y;

			return *this;
		}

		inline bool operator < (const Vector2T &oVector) const
		{
			return (X < oVector.X && Y < oVector.Y);
		}

		inline bool operator > (const Vector2T &oVector) const
		{
			return (X > oVector.X && Y > oVector.Y);
		}

		inline bool operator >= (const Vector2T &oVector) const
		{
			return (X >= oVector.X && Y >= oVector.Y);
		}

		inline bool operator <= (const Vector2T &oVector) const
		{
			return (X <= oVector.X && Y <= oVector.Y);
		}

		inline bool operator == (const Vector2T &oVector) const
		{
			return(X == oVector.X && Y == oVector.Y);
		}

		inline bool operator != (const Vector2T &oVector) const
		{
			return(X != oVector.X || Y != oVector.Y);
		}

		inline Vector2T operator + (const Vector2T &oVector) const
		{
			return Vector2T(
				X + oVector.X,
				Y + oVector.Y);
		}

		inline Vector2T operator - (const Vector2T &oVector) const
		{
			return Vector2T(
				X - oVector.X,
				Y - oVector.Y);
		}


		inline Vector2T operator * (const Vector2T &oVector) const
		{
			return Vector2T(
				X * oVector.X,
				Y * oVector.Y);
		} 

		inline Vector2T operator * (const T Scalar) const
		{
			return Vector2T(
				X * Scalar,
				Y * Scalar);
		} 

		inline Vector2T operator / (const Vector2T &oVector) const
		{
			return Vector2T(
				X / oVector.X,
				Y / oVector.Y);
		} 

		inline Vector2T operator / (const T Scalar) const
		{
			assert(Scalar != 0.0);

			T Inv = (T) 1.0f / Scalar;

			return Vector2T(
				X * Inv,
				Y * Inv);
		} 

		inline Vector2T operator - () const
		{
			return Vector2T( -X, -Y);
		}

		inline const T& operator + () const
		{
			return *this;
		}

		inline Vector2T &operator += (const Vector2T &oVector)
		{
			X += oVector.X;
			Y += oVector.Y;

			return *this;
		}

		inline Vector2T &operator -= (const Vector2T &oVector)
		{
			X -= oVector.X;
			Y -= oVector.Y;

			return *this;
		}

		inline Vector2T &operator *= (const Vector2T &oVector)
		{
			X *= oVector.X;
			Y *= oVector.Y;

			return *this;
		}


		inline Vector2T &operator /= (const Vector2T &oVector)
		{
			X /= oVector.X;
			Y /= oVector.Y;

			return *this;
		}

		inline Vector2T &operator /= (const T Scalar)
		{
			assert(Scalar != 0.0);

			T Inv = (T) 1.0f / Scalar;

			X /= Scalar;
			Y /= Scalar;

			return *this;
		}

		inline Vector2T &operator *= (const T Scalar)
		{
			X *= Scalar;
			Y *= Scalar;

			return *this;
		}

		inline void Zero()
		{
			X = Y = T(0);
		}

		inline bool IsZero()
		{
			return (X == T(0) && Y == T(0));
		}

		inline T Normalise()
		{
			T len = Length();

			if(len > 0.0f)
			{
				const T inv = (T) 1.0f / len;
				X *= inv;
				Y *= inv;
			}
			return len;
		}

		inline T Length () const
		{
			return ooge::math::Sqrt(SquaredLength());
		}

		inline T SquaredLength () const
		{
			return X*X + Y*Y;
		}

		inline T Distance (const Vector2T &oVector) const
		{
			return (*this - oVector).length();
		}

		inline T DistanceSquared (const Vector2T &oVector) const
		{
			return (*this - oVector).SquaredLength();
		}

		inline T CrossProduct (const Vector2T &oVector) const
		{
			return X * oVector.Y - Y * oVector.X;
		}

		inline Vector2T MidPoint(const Vector2T &oVector) const
		{
			return Vector2T((X + oVector.X) * 0.5f, (Y + oVector.Y) * 0.5f);
		}

		inline T DotProduct(const Vector2T &oVector) const
		{
			return X * oVector.X + Y * oVector.Y;
		}

		inline T Min(const T &oVector)
		{
			return ooge::math::Min(oVector.X, oVector.Y);
		}

		inline T Max(const T &oVector)
		{
			return ooge::math::Max(oVector.X, oVector.Y);
		}

		inline void Set(const T x1, const T y1)
		{
			X = x1;
			Y = y1;
		}

		inline void SetX(T x1)
		{
			X = x1;
		}

		inline void SetY(T y1)
		{
			Y = y1;
		}

		inline void Rotate(const T angle)
		{
			T tempV;

			tempV.X = ooge::math::Cos(angle) - Y * ooge::math::Sin(angle);
			tempV.Y = ooge::math::Sin(angle) + Y * ooge::math::Cos(angle);

			X = tempV.X;
			Y = tempV.Y;
		}

		inline Vector2T Rotate(const Vector2T &oVector, const T angle)
		{
			return Vector2T(oVector.X * ooge::math::Cos(angle) - oVector.Y * ooge::math::Sin(angle), oVector.X * ooge::math::Sin(angle) + oVector.Y * ooge::math::Cos(angle));
		}

		inline friend std::ostream &operator<<(std::ostream &o, const Vector2T &v)
		{
			o << v.X << " " << v.Y;
			return o;
		}

		static const Vector2T<T> ZERO;
		static const Vector2T<T> ONE;
		static const Vector2T<T> POS_X;
		static const Vector2T<T> POS_Y;
		static const Vector2T<T> NEGATIVE_POS_X;
		static const Vector2T<T> NEGATIVE_POS_Y;		
	};

	typedef Vector2T<Real>  Vector2f;
	typedef Vector2T<double> Vector2d;
	typedef Vector2T<Real>  Vector2;
}

#endif //_VECTOR2_HPP_
