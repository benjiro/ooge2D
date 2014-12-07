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

#ifndef _VECTOR3_HPP_
#define _VECTOR3_HPP_

#include <Math.hpp>
#include <Config.hpp>
#include <iostream>

namespace ooge
{
	template<typename T>
	class OOGE_API Vector3T
	{
	public:
		T X, Y, Z;

		inline Vector3T()
		{
			Set(0,0,0);
		}

		inline Vector3T(const T X1, const T Y1, const T Z1) :	
			X(X1),
			Y(Y1),
			Z(Z1)
		{
		}

		template<typename Vector3T_class>
		explicit Vector3T(const Vector3T_class *p) :	
			X(p[0]),
			Y(p[1]),
			Z(p[2])
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

		inline Vector3T &operator = (const Vector3T &oVector)
		{
			X = oVector.X;
			Y = oVector.Y;
			Z = oVector.Z;

			return *this;
		}

		inline bool operator < (const Vector3T &oVector) const
		{
			return (X < oVector.X && Y < oVector.Y && Z < oVector.Z);
		}

		inline bool operator > (const Vector3T &oVector) const
		{
			return (X > oVector.X && Y > oVector.Y && Z > oVector.Z);
		}

		inline bool operator >= (const Vector3T &oVector) const
		{
			return (X >= oVector.X && Y >= oVector.Y && Z >= oVector.Z);
		}

		inline bool operator <= (const Vector3T &oVector) const
		{
			return (X <= oVector.X && Y <= oVector.Y && Z <= oVector.Z);
		}

		inline bool operator == (const Vector3T &oVector) const
		{
			return(X == oVector.X && Y == oVector.Y && Z == oVector.Z);
		}

		inline bool operator != (const Vector3T &oVector) const
		{
			return(X != oVector.X || Y != oVector.Y || Z != oVector.Z);
		}

		inline Vector3T operator + (const Vector3T &oVector) const
		{
			return Vector3T(
				X + oVector.X,
				Y + oVector.Y,
				Z + oVector.Z);
		}

		inline Vector3T operator - (const Vector3T &oVector) const
		{
			return Vector3T(
				X - oVector.X,
				Y - oVector.Y,
				Z - oVector.Z);
		}


		inline Vector3T operator * (const Vector3T &oVector) const
		{
			return Vector3T(
				X * oVector.X,
				Y * oVector.Y,
				Z * oVector.Z);
		} 

		inline Vector3T operator * (const T Scalar) const
		{
			return Vector3T(
				X * Scalar,
				Y * Scalar
				Z * Scalar);
		} 

		inline Vector3T operator / (const Vector3T &oVector) const
		{
			return Vector3T(
				X / oVector.X,
				Y / oVector.Y,
				Z / oVector.Z);
		} 

		inline Vector3T operator / (const T Scalar) const
		{
			assert(Scalar != 0.0);

			T Inv = (T) 1.0f / Scalar;

			return Vector3T(
				X * Inv,
				Y * Inv,
				Z * Inv);
		} 

		inline Vector3T operator - () const
		{
			return Vector3T( -X, -Y, -Z);
		}

		inline const Vector3T& operator + () const
		{
			return *this;
		}

		inline Vector3T& operator += (const Vector3T &oVector)
		{
			X += oVector.X;
			Y += oVector.Y;
			Z += oVector.Z

			return *this;
		}

		inline Vector3T& operator -= (const Vector3T &oVector)
		{
			X -= oVector.X;
			Y -= oVector.Y;
			Z -= oVector.Z;

			return *this;
		}

		inline Vector3T& operator *= (const Vector3T &oVector)
		{
			X *= oVector.X;
			Y *= oVector.Y;
			Z *= oVector.Z;

			return *this;
		}


		inline Vector3T& operator /= (const Vector3T &oVector)
		{
			X /= oVector.X;
			Y /= oVector.Y;
			Z /= oVector.Z;

			return *this;
		}

		inline Vector3T& operator /= (const T Scalar)
		{
			assert(Scalar != 0.0);

			T Inv = (T) 1.0f / Scalar;

			X /= Scalar;
			Y /= Scalar;
			Z /= Scalar;

			return *this;
		}

		inline Vector3T& operator *= (const T Scalar)
		{
			X *= Scalar;
			Y *= Scalar;
			Z *= Scalar;

			return *this;
		}

		inline void Zero()
		{
			X = Y = Z = T(0);
		}

		inline bool IsZero()
		{
			return (X == T(0) && Y == T(0) && Z == T(0));
		}

		inline T Normalise()
		{
			T len = Length();

			if(len > 0.0f)
			{
				const T inv = (T) 1.0f / len;
				X *= inv;
				Y *= inv;
				Z *= inv;
			}
			return len;
		}

		inline T Length () const
		{
			return ooge::math::Sqrt(SquaredLength());
		}

		inline T SquaredLength () const
		{
			return X*X + Y*Y + Z*Z;
		}

		inline T Distance (const Vector3T &oVector) const
		{
			return (*this - oVector).length();
		}

		inline T DistanceSquared (const Vector3T &oVector) const
		{
			return (*this - oVector).SquaredLength();
		}

		inline Vector3T CrossProduct (const Vector3T &oVector) const
		{
			return Vector3(Y * oVector.Z - Z * oVector.Y, Z * oVector.X - X * oVector.Z, X * oVector.Y - Y * oVector.X);
		}

		inline Vector3T Midpoint(const Vector3T &oVector) const
		{
			return Vector3((X + oVector.X) * 0.5f, (Y + oVector.Y) * 0.5f, (Z + oVector.Z) * 0.5f);
		}

		inline T DotProduct(const Vector3T &oVector) const
		{
			return X*oVector.X + Y*oVector.Y + Z*oVector.Z;
		}

		inline T Min(const Vector3T &oVector)
		{
			return ooge::math::Min(oVector.X, oVector.Y);
		}

		inline T Max(const Vector3T &oVector)
		{
			return ooge::math::MaX(oVector.X,oVector.Y);
		}

		inline void Set(const T X1, const T Y1, const T Z1)
		{
			X = X1;
			Y = Y1;
			Z = Z1;
		}

		inline void SetX(T X1)
		{
			X = X1;
		}

		inline void SetY(T Y1)
		{
			Y = Y1;
		}

		inline void SetZ(T Z1)
		{
			Z = Z1;
		}

		inline friend std::ostream &operator<<(std::ostream &o, const Vector3T &v)
		{
			o << v.X << " " << v.Y << " " << v.Z;
			return o;
		}

		static const Vector3T<T> ZERO;
		static const Vector3T<T> ONE;
		static const Vector3T<T> POS_X;
		static const Vector3T<T> POS_Y;
		static const Vector3T<T> POS_Z;
		static const Vector3T<T> NEGATIVE_POS_X;
		static const Vector3T<T> NEGATIVE_POS_Y;	
		static const Vector3T<T> NEGATIVE_POS_Z;
	};

	typedef Vector3T<Real>  Vector3f;
	typedef Vector3T<double> Vector3d;
	typedef Vector3T<Real>  Vector3;
}

#endif //_VECTOR3_HPP_
