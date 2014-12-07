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

#include <SpriteAnimation.hpp>
#include <Image.hpp>
#include <AnimationSequence.hpp>
#include <Common.hpp>

using namespace ooge;

SpriteAnimation::SpriteAnimation(const Sprite *sprite, UInt32 frameWidth, UInt32 frameHeight, UInt32 columns, UInt32 rows)
: mFrameWidth(frameWidth), mFrameHeight(frameHeight), mCols(columns), mRows(rows), mCurrentAnimation(0),
Sprite(*sprite)
{
	SetFrame(0);
}

SpriteAnimation::SpriteAnimation(Image *image, const std::string &name, UInt32 frameWidth, UInt32 frameHeight, UInt32 columns, UInt32 rows)
: mFrameWidth(frameWidth), mFrameHeight(frameHeight), mCols(columns), mRows(rows), mCurrentAnimation(0),
Sprite(image, name)
{
	SetFrame(0);
}

SpriteAnimation::SpriteAnimation(const std::string &imageName, const std::string &name, UInt32 frameWidth, UInt32 frameHeight, UInt32 columns, UInt32 rows)
: mFrameWidth(frameWidth), mFrameHeight(frameHeight), mCols(columns), mRows(rows), mCurrentAnimation(0),
Sprite(imageName, name)
{
	SetFrame(0);
}

void SpriteAnimation::SetFrame(Int32 frame)
{

	//TODO: add proper row support fix this crap
	Real frameRangeCols = ((mFrameWidth * 1.0f) / GetImage()->GetWidth());
	Real frameRangeRows = ((mFrameHeight * 1.0f) / GetImage()->GetHeight());

	Real offsetX = 0;
	Real offsetY = 0;
	if(mCurrentAnimation)
	{
		if(mCurrentAnimation->GetStartX() > 0)
			offsetX = (mCurrentAnimation->GetStartX() * 1.0f) / GetImage()->GetWidth();
	}

	mTextureCoords.Left = (frameRangeCols * frame) + offsetX;
	mTextureCoords.Right = (frameRangeCols * (frame + 1)) + offsetX;
	mTextureCoords.Top =  0;
	mTextureCoords.Bottom = 1;

	if(mCurrentAnimation)
	{
		if(mCurrentAnimation->GetStartY() > 0)
		{
			offsetY = (mStartY * 1.0f) / GetImage()->GetHeight();
			mTextureCoords.Top =  offsetY;
			mTextureCoords.Bottom = offsetY;
		}
	}


	if(mCurrentRow < 0)
	{
		mTextureCoords.Top = (frameRangeRows * frame) + offsetY;
		mTextureCoords.Bottom = (frameRangeRows * (frame + 1)) + offsetY;
	}
}

Int32 SpriteAnimation::GetFrame()
{
	return mCurrentFrame;
}

void SpriteAnimation::AddSequence(AnimationSequence *sequence)
{
	ConstItSequence it = mSequences.find(sequence->GetSequenceName());
	if(it == mSequences.end())
	{
		mSequences.insert(std::pair<std::string, AnimationSequence*>(sequence->GetSequenceName(), sequence));
		mCurrentAnimation = sequence;
	}
}

void SpriteAnimation::AddSequence(const std::string &sequenceName, UInt32 startX, UInt32 startY, UInt32 numberofFrames, const AnimationMode mode)
{
	ConstItSequence it = mSequences.find(sequenceName);
	if(it == mSequences.end())
	{
		mSequences.insert(std::pair<std::string, AnimationSequence*>(sequenceName, 
			new AnimationSequence(sequenceName,startX, startY, numberofFrames, mode)));
		mCurrentAnimation = GetSequence(sequenceName);
	}
}

AnimationSequence *SpriteAnimation::GetSequence(const std::string &sequenceName) const
{
	ConstItSequence it = mSequences.find(sequenceName);
	return it != mSequences.end() ? (*it).second : NULL;
}

void SpriteAnimation::RemoveSequence(ooge::AnimationSequence *sequence)
{
	ItSequence it = mSequences.find(sequence->GetSequenceName());
	if(it != mSequences.end())
	{
		delete (*it).second;
		mSequences.erase(it);
		mCurrentAnimation = 0;
	}
}

void SpriteAnimation::RemoveSequence(const std::string &name)
{
	ItSequence it = mSequences.find(name);
	if(it != mSequences.end())
	{
		delete (*it).second;
		mSequences.erase(it);
		mCurrentAnimation = 0;
	}
}

void SpriteAnimation::PlaySequence(ooge::AnimationSequence *sequence)
{
	mCurrentAnimation = sequence;
	mCurrentAnimation->Play();
	mStartX = mCurrentAnimation->GetStartX();
	mStartY = mCurrentAnimation->GetStartY();
	mCurrentFrame = 0;
	if(sequence->GetAnimationMode() == REVERSE)
		mCurrentFrame = sequence->GetFrames() - 1;
}

void SpriteAnimation::PlaySequence(const std::string &name)
{
	ConstItSequence it = mSequences.find(name);
	mCurrentAnimation = (*it).second;
	mCurrentAnimation->Play();
	mStartX = mCurrentAnimation->GetStartX();
	mStartY = mCurrentAnimation->GetStartY();
	mCurrentFrame = 0;
	if((*it).second->GetAnimationMode() == REVERSE)
		mCurrentFrame = (*it).second->GetFrames() - 1;
}

void SpriteAnimation::Render()
{
	glLoadIdentity();
	glTranslatef(GetPosition().X, GetPosition().Y, 0.0f);
	glRotatef(GetRotation(), 0, 0, 1);
	glScalef(GetScale().X, GetScale().Y, 0.0f);

	Real width = (mFrameWidth / 2.0f);
	Real height = (mFrameHeight / 2.0f);


	width = ((Int32)width ^ -GetFlipX()) + GetFlipX();

	glEnable(GL_TEXTURE_2D);
	glBindTexture (GL_TEXTURE_2D, GetImage()->GetTexture());

	glBegin (GL_QUADS);

	glTexCoord2f(mTextureCoords.Right, mTextureCoords.Top); 
	glVertex2f(width, -height); //(1,0)

	glTexCoord2f(mTextureCoords.Left, mTextureCoords.Top); 
	glVertex2f(-width, -height); //(0,0)

	glTexCoord2f(mTextureCoords.Left, mTextureCoords.Bottom); 
	glVertex2f(-width, height); //(0,1)

	glTexCoord2f(mTextureCoords.Right, mTextureCoords.Bottom); 
	glVertex2f(width, height); //(1,1)

	glEnd ();

	glDisable(GL_TEXTURE_2D);

	//glPopMatrix();
}

void SpriteAnimation::Update(Real deltaT)
{
	SetRect(Rect(GetPosition().Y - (GetImage()->GetHeight()/2), GetPosition().X - (GetImage()->GetWidth()/2), 
		GetPosition().Y + (GetImage()->GetHeight()/2), GetPosition().X + (GetImage()->GetWidth()/2)));

	SetDirty(true);

	if(!mCurrentAnimation || !mCurrentAnimation->IsPlaying())
		return;

	static Real mTimer;

	if(mTimer >= mCurrentAnimation->GetSpeed())
	{
		if(mCurrentFrame == mCols && mRows >= 1)
		{
			mCurrentRow++;
		}

		switch(mCurrentAnimation->GetAnimationMode())
		{
		case LOOP:
			{
				if(mCurrentFrame == mCurrentAnimation->GetFrames())
				{
					mCurrentFrame = 0;
					return;
				}
				SetFrame(mCurrentFrame);
				mCurrentFrame++;
				break;
			};
		case FORWARD:
			{
				if(mCurrentFrame == mCurrentAnimation->GetFrames())
				{
					mCurrentAnimation->Stop();
					return;
				}
				SetFrame(mCurrentFrame);
				mCurrentFrame++;
				break;
			};
		case REVERSE:
			{
				if(mCurrentFrame == -1)
				{
					mCurrentFrame = mCurrentAnimation->GetFrames() - 1;
					return;
				}
				SetFrame(mCurrentFrame);
				mCurrentFrame--;
				break;
			};
		case BACKFORTH:
			{
				static bool flip = false;
				if(mCurrentFrame == mCurrentAnimation->GetFrames() - 1)
					flip = true;
				else if(mCurrentFrame == 0)
					flip = false;

				if(flip)
					mCurrentFrame--;
				else
					mCurrentFrame++;

				SetFrame(mCurrentFrame);
				break;
			};
		}
		mTimer = 0;
	}
	else
	{
		mTimer += deltaT;
	}
}