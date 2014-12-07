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

#ifndef _ANIMATIONSEQUENCE_HPP_
#define _ANIMATIONSEQUENCE_HPP_

#include <Config.hpp>
#include <string>

namespace ooge
{
	enum AnimationMode;

	class OOGE_API AnimationSequence
	{
	public:
		AnimationSequence(const std::string &sequenceName, UInt32 startX, UInt32 startY, UInt32 numberOfFrames, 
			const AnimationMode type);
		~AnimationSequence();

		void Play();
		void Stop();
		const bool IsPlaying() const;

		void SetStartX(UInt32 x);
		const UInt32 GetStartX() const;

		void SetStartY(UInt32 y);
		const UInt32 GetStartY() const;

		void SetFrames(UInt32 frames);
		const UInt32 GetFrames() const;

		void SetSpeed(Real speed);
		const Real GetSpeed() const;

		void SetAnimationMode(AnimationMode type);
		const AnimationMode GetAnimationMode() const;

		void SetSequenceName(const std::string &name);
		const std::string &GetSequenceName() const;
	private:
		bool mPlaying;
		UInt32 mStartX;
		UInt32 mStartY;
		UInt32 mFrames;
		UInt32 mCurrentFrame;
		Real mSpeed;
		AnimationMode mType;
		std::string mName;
	};
}

#endif //_ANIMATIONSEQUENCE_HPP_