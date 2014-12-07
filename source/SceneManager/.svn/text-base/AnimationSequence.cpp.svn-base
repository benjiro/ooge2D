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

#include <AnimationSequence.hpp>
#include <SpriteAnimation.hpp>

using namespace ooge;

AnimationSequence::AnimationSequence(const std::string &sequenceName, UInt32 startX, UInt32 startY, UInt32 numberOfFrames, const AnimationMode type)
: mName(sequenceName), mStartX(startX), mStartY(startY), mFrames(numberOfFrames), mType(type), mSpeed(150), mPlaying(false)
{
}

AnimationSequence::~AnimationSequence()
{

}

void AnimationSequence::Play()
{
	mPlaying = true;
}

void AnimationSequence::Stop()
{
	mPlaying = false;
}

const bool AnimationSequence::IsPlaying() const
{
	return mPlaying;
}

void AnimationSequence::SetStartX(UInt32 x)
{
	mStartX = x;
}

const UInt32 AnimationSequence::GetStartX() const
{
	return mStartX;
}

void AnimationSequence::SetStartY(UInt32 y)
{
	mStartY = y;
}

const UInt32 AnimationSequence::GetStartY() const
{
	return mStartY;
}

void AnimationSequence::SetFrames(UInt32 frames)
{
	mFrames = frames;
}

const UInt32 AnimationSequence::GetFrames() const
{
	return mFrames;
}

void AnimationSequence::SetSpeed(Real speed)
{
	mSpeed = speed;
}

const Real AnimationSequence::GetSpeed() const
{
	return mSpeed;
}

void AnimationSequence::SetAnimationMode(AnimationMode type)
{
	mType = type;
}
const AnimationMode AnimationSequence::GetAnimationMode() const
{
	return mType;
}

void AnimationSequence::SetSequenceName(const std::string &name)
{
	mName = name;
}
const std::string &AnimationSequence::GetSequenceName() const
{
	return mName;
}