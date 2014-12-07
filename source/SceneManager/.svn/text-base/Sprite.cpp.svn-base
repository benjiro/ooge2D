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

#include <Sprite.hpp>
#include <Image.hpp>
#include <Common.hpp>

using namespace ooge;

Sprite::Sprite(Image *image, const std::string &name, const Vector2 &position, const Vector2 &scale)
	: Renderable(name, position, scale),
	mIsFlippedX(false), mIsFlippedY(false), mImage(image)
{
}

Sprite::Sprite(const std::string &imageName, const std::string &name, const Vector2 &position, const Vector2 &scale)
	: Renderable(name, position, scale),
	mIsFlippedX(false), mIsFlippedY(false), mImage(new Image(imageName))
{
}

Sprite::Sprite(const Sprite &copy)
	: Renderable(copy.GetName(), copy.GetPosition(), copy.GetScale(), copy.GetRotation(), copy.GetColour()),
	mIsFlippedX(copy.GetFlipX()), mIsFlippedY(copy.GetFlipY()), mImage(copy.GetImage())
{
}

Sprite::~Sprite()
{
	delete mImage;
}


void Sprite::SetImage(Image *image)
{
	mImage = image;
}

Image *Sprite::GetImage() const
{
	return mImage;
}

void Sprite::FlipX(bool flip)
{
	mIsFlippedX = flip;
}

void Sprite::FlipY(bool flip)
{
	mIsFlippedY = flip;
}

const bool Sprite::GetFlipX() const
{
	return mIsFlippedX;
}

const bool Sprite::GetFlipY() const
{
	return mIsFlippedX;
}

void Sprite::Render()
{	
	glLoadIdentity();
	glTranslatef(GetPosition().X, GetPosition().Y, 0.0f);
	glRotatef(GetRotation(), 0, 0, 1);
	glScalef(GetScale().X, GetScale().Y, 1.0f);

	Real width = (mImage->GetWidth() / 2.0f);
	Real height = (mImage->GetHeight() / 2.0f);

	width = (static_cast<Int32>(width) ^ -mIsFlippedX) + mIsFlippedX;

	glEnable(GL_TEXTURE_2D);
	glBindTexture (GL_TEXTURE_2D, mImage->GetTexture());

	glBegin (GL_QUADS);

	glTexCoord2f(mImage->GetTextureCoords().Bottom, mImage->GetTextureCoords().Left); 
	glVertex2f(width, -height); //(1,0)

	glTexCoord2f(mImage->GetTextureCoords().Top, mImage->GetTextureCoords().Left); 
	glVertex2f(-width, -height); //(0,0)

	glTexCoord2f(mImage->GetTextureCoords().Top, mImage->GetTextureCoords().Right); 
	glVertex2f(-width, height); //(0,1)

	glTexCoord2f(mImage->GetTextureCoords().Bottom, mImage->GetTextureCoords().Right); 
	glVertex2f(width, height); //(1,1)

	glEnd ();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::Update(Real deltaT)
{
	SetRect(Rect(GetPosition().Y - (GetImage()->GetHeight()/2), GetPosition().X - (GetImage()->GetWidth()/2), 
		GetPosition().Y + (GetImage()->GetHeight()/2), GetPosition().X + (GetImage()->GetWidth()/2)));
}

