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

#ifndef _COLOUR_HPP_
#define _COLOUR_HPP_

#include <Math.hpp>
#include <Config.hpp>


namespace ooge
{	
	template<class T>
	class OOGE_API ColourT
	{
	public:
		T R;
		T G;
		T B;
		T A;

		ColourT() 
			: R(0), G(0), B(0), A(0)
		{
		}

		ColourT(const ColourT &colour)
			: R(colour.R), G(colour.G), B(colour.B), A(colour.A)
		{
		}

		ColourT(const T r, const T g, const T b, const T a = 1)
			: R(r), G(g), B(b), A(a)
		{
		}

		T &operator +=(const T &oColour)
		{
			R = math::Min(R + oColour.R, (T)255);
			G = math::Min(G + oColour.G, (T)255);
			B = math::Min(B + oColour.B, (T)255);
			A = math::Min(A + oColour.A, (T)255);

			return *this;
		}

		T &operator -=(const T &oColour)
		{
			R = math::Min(R - oColour.R, (T)255);
			G = math::Min(G - oColour.G, (T)255);
			B = math::Min(B - oColour.B, (T)255);
			A = math::Min(A - oColour.A, (T)255);

			return *this;
		}

		T operator +(const T &oColour)
		{
			return Colour(R + oColour.R, G + oColour.G, B + oColour.B, A + oColour.A);
		}

		T operator -(const T &oColour)
		{
			return Colour(R - oColour.R, G - oColour.G, B - oColour.B, A - oColour.A);
		}

		T operator *(const T scalar)
		{
			return Colour(R * scalar, G * scalar, B * scalar, A * scalar);
		}

		T operator /(const T divider)
		{
			return Colour(R / divider, G / divider, B / divider, A / divider);
		}

		bool operator ==(const T &oColour) const
		{
			return (R == oColour.R) && (G == oColour.G) && (B == oColour.B) && (A == oColour.A);
		}

		bool operator !=(const T &oColour) const
		{
			return !(*this == oColour);
		}
	};

	typedef ColourT<UInt8> ColourUInt8;
	typedef ColourT<Real> Colour;
	typedef ColourT<Int32> ColourI;
	typedef ColourT<double> ColourD;

	static const Colour Black = Colour(0.f,0.f,0.f);
	static const Colour White = Colour(255.f,255.f,255.f);
	static const Colour Red = Colour(255.f,0.f,0.f);
	static const Colour Blue = Colour(0.f,0.f,255.f);
	static const Colour Green = Colour(0.f,255.f,0.f);

}

#endif //_COLOUR_HPP_