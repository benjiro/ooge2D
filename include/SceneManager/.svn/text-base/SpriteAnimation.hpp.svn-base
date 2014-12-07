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

#ifndef _SPRITEANIMATION_HPP_
#define _SPRITEANIMATION_HPP_

#include <Sprite.hpp>
#include <Config.hpp>
#include <map>

namespace ooge
{
	enum AnimationMode
	{
		FORWARD = 0,
		REVERSE = 1,
		LOOP = 2,
		BACKFORTH = 3
	};
	
	//forward
	class Image;
	class AnimationSequence;
	
	class OOGE_API SpriteAnimation : public Sprite
	{
		public:
			SpriteAnimation(const Sprite *sprite, UInt32 frameWidth, UInt32 frameHeight, UInt32 columns, UInt32 rows);
			SpriteAnimation(Image *image, const std::string &name, UInt32 frameWidth, UInt32 frameHeight, UInt32 columns, UInt32 rows);
			SpriteAnimation(const std::string &imageName, const std::string &name, UInt32 frameWidth, UInt32 frameHeight, UInt32 columns, UInt32 rows);
				
			void SetFrame(Int32 frame);
			Int32 GetFrame();

			void AddSequence(AnimationSequence *sequence);
			void AddSequence(const std::string &sequenceName, UInt32 startX, UInt32 startY, UInt32 numberofFrames, const AnimationMode mode = LOOP);
			AnimationSequence *GetSequence(const std::string &sequenceName) const;

			void RemoveSequence(const std::string &name);
			void RemoveSequence(AnimationSequence *sequence);
			
			void PlaySequence(AnimationSequence *sequence);
			void PlaySequence(const std::string &name);

			virtual void Render();
			virtual void Update(Real deltaT);
		private:
			Int32 mCurrentFrame;
			UInt32 mCols, mRows;
			UInt32 mCurrentRow;
			UInt32 mFrameWidth, mFrameHeight;
			UInt32 mStartX, mStartY;
			Real mTimeSinceLastFrame;
			Rect mTextureCoords;

			AnimationSequence *mCurrentAnimation;
			std::map<std::string, AnimationSequence*> mSequences;
			typedef std::map<std::string, AnimationSequence*>::iterator ItSequence;
			typedef std::map<std::string, AnimationSequence*>::const_iterator ConstItSequence;
	};
}

#endif //_SPRITEANIMATION_HPP_