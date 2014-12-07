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

#ifndef BML_MATRIX_H_
#define BML_MATRIX_H_

#include <Vector3.hpp>
#include <Config.hpp>

namespace ooge
{
	//Templated Matrix 3x3 Class
	template<typename T>
	class OOGE_API Matrix33T
	{
	public:
		//Defines size of matrix
		enum { rows = 3, columns = 3, size = 9};

		//Creates matrix to given value and size in memory
		T m[rows][columns];

		//Default Constructor
		inline Matrix33T()
		{
			Indentiy();
		}

		//Constructor for anytype of given 9 values
		inline Matrix33T(
			const T m11, const T m12, const T m13, 
			const T m21, const T m22, const T m23, 
			const T m31, const T m32, const T m33)
		{
			m[0][0] = m11;
			m[0][1] = m12;
			m[0][2] = m13;
			m[1][0] = m21;
			m[1][1] = m22;
			m[1][2] = m23;
			m[2][0] = m31;
			m[2][1] = m32;
			m[2][2] = m33;
		}

		//Copy constructor
		inline Matrix33T(const Matrix33T &mat)
		{
			m[0][0] = mat.m[0][0];
			m[0][1] = mat.m[0][1];
			m[0][2] = mat.m[0][2];

			m[1][0] = mat.m[1][0];
			m[1][1] = mat.m[1][1];
			m[1][2] = mat.m[1][2];

			m[2][0] = mat.m[2][0];
			m[2][1] = mat.m[2][1];
			m[2][2] = mat.m[2][2];
		}

		//Returns poInt32er to matrix
		inline T* ptr()
		{
			return (T*) m;
		}

		//Returns const poInt32er to matrix
		inline const T* ptr() const
		{
			return (T*) m;
		}

		//Return row of give matrix position
		inline T* operator[](size_t row) const
		{
			return (T*) m[row];
		}

		//Operator for adding matrix
		Matrix33T operator+(const Matrix33T &mat) const
		{
			return Matrix33T(
				m[0][0]+mat.m[0][0], m[0][1]+mat.m[0][1], m[0][2]+mat.m[0][2],
				m[1][0]+mat.m[1][0], m[1][1]+mat.m[1][1], m[1][2]+mat.m[1][2],
				m[2][0]+mat.m[2][0], m[2][1]+mat.m[2][1], m[2][2]+mat.m[2][2]);
		}

		//Operator for subtracting matrix
		Matrix33T operator-(const Matrix33T &mat) const
		{
			return Matrix33T(
				m[0][0]-mat.m[0][0], m[0][1]-mat.m[0][1], m[0][2]-mat.m[0][2],
				m[1][0]-mat.m[1][0], m[1][1]-mat.m[1][1], m[1][2]-mat.m[1][2],
				m[2][0]-mat.m[2][0], m[2][1]-mat.m[2][1], m[2][2]-mat.m[2][2]);
		}

		//Operator for multiplying matrix
		Matrix33T operator*(const Matrix33T &mat) const
		{
			return Matrix33T(
				m[0][0]*mat.m[0][0] + m[0][1]*mat.m[1][0] + m[0][2]*mat.m[2][0],
				m[0][0]*mat.m[0][1] + m[0][1]*mat.m[1][1] + m[0][2]*mat.m[2][1],
				m[0][0]*mat.m[0][2] + m[0][1]*mat.m[1][2] + m[0][2]*mat.m[2][2],
				m[1][0]*mat.m[0][0] + m[1][1]*mat.m[1][0] + m[1][2]*mat.m[2][0],
				m[1][0]*mat.m[0][1] + m[1][1]*mat.m[1][1] + m[1][2]*mat.m[2][1],
				m[1][0]*mat.m[0][2] + m[1][1]*mat.m[1][2] + m[1][2]*mat.m[2][2],
				m[2][0]*mat.m[0][0] + m[2][1]*mat.m[1][0] + m[2][2]*mat.m[2][0],
				m[2][0]*mat.m[0][1] + m[2][1]*mat.m[1][1] + m[2][2]*mat.m[2][1],
				m[2][0]*mat.m[0][2] + m[2][1]*mat.m[1][2] + m[2][2]*mat.m[2][2]);
		}

		//Operator for multiplying matrix by vector 3
		Vector3T<T> operator*(const Vector3T<T> &vec) const
		{
			return Vector3T<T>(
				(m[0][0] * vec.x + m[0][1] * vec.y + m[0][2] * vec.z), 
				(m[1][0] * vec.x + m[1][1] * vec.y + m[1][2] * vec.z), 
				(m[2][0] * vec.x + m[2][1] * vec.y + m[2][2] * vec.z));
		}

		inline Matrix33T<T> Inverse() const
		{
			//Find the Determinent of 3x3
			Real det = (((m[0][0] * m[1][1] * m[2][2]) +
						(m[0][1] * m[1][2] * m[2][0]) +
						(m[0][2] * m[1][0] * m[2][1])) -
						((m[2][0] * m[1][1] * m[0][2]) +
						(m[2][1] * m[1][2] * m[0][0]) +
						(m[2][2] * m[1][0] * m[0][1])));

			//Check if valid determinent (Not 0)
			if((det < -1E-7f) || (det > 1E-7f))
			{
				return Matrix33T<T>(
					(m[1][1] * m[2][2] - m[1][2] * m[2][1])/det,
					(m[0][2] * m[2][1] - m[0][1] * m[2][2])/det,
					(m[0][1] * m[1][2] - m[0][2] * m[1][1])/det,
					(m[1][2] * m[2][0] - m[1][0] * m[2][2])/det,
					(m[0][0] * m[2][2] - m[0][2] * m[2][0])/det,
					(m[0][2] * m[1][0] - m[0][0] * m[1][2])/det,
					(m[1][0] * m[2][1] - m[1][1] * m[2][0])/det,
					(m[0][1] * m[2][0] - m[0][0] * m[2][1])/det,
					(m[0][0] * m[1][1] - m[0][1] * m[1][0])/det);
			}
			else
			{
				return Matrix33T<T>();
			}
		}

		//returns transpose of matrix
		Matrix33T<T> Transpose()
		{
			return Matrix33T<T>(
				m[0][0],m[1][0],m[2][0],
				m[0][1],m[1][1],m[2][1],
				m[0][2],m[1][2],m[2][2]);
		}

		//Performs indentiy on matrix
		inline void Indentiy()
		{
			m[0][0] = T(1.0);
			m[0][1] = T(0.0);
			m[0][2] = T(0.0);

			m[1][0] = T(0.0);
			m[1][1] = T(1.0);
			m[1][2] = T(0.0);

			m[2][0] = T(0.0);
			m[2][1] = T(0.0);
			m[2][2] = T(1.0);
		}

		//Resets Matrix to Zero
		inline void Zero()
		{
			m[0][0] = T(0.0);
			m[0][1] = T(0.0);
			m[0][2] = T(0.0);

			m[1][0] = T(0.0);
			m[1][1] = T(0.0);
			m[1][2] = T(0.0);

			m[2][0] = T(0.0);
			m[2][1] = T(0.0);
			m[2][2] = T(0.0);
		}
	};

	//Useful typedefs
	typedef Matrix33T<Real> Matrix33;
	typedef Matrix33T<double> Matrix33D;
};

#endif //BML_MATRIX_H_