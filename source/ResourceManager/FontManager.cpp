///*
//This file is apart of ooge(object-oriented 2D game engine)
//
//-------------------------------------------------------------------
//Copyright (c) 2010 Benjamin Evenson
//
//Permission is hereby granted, free of charge, to any person
//obtaining a copy of this software and associated documentation
//files (the "Software"), to deal in the Software without
//restriction, including without limitation the rights to use,
//copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the
//Software is furnished to do so, subject to the following
//conditions:
//
//The above copyright notice and this permission notice shall be
//included in all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//OTHER DEALINGS IN THE SOFTWARE.
//-------------------------------------------------------------------
//*/
//
//#include <FontManager.hpp>
//#include <iostream>
//#include <FTGL/ftgl.h>
//
//using namespace ooge;
//
//template<> FontManager *Singleton<FontManager>::ms_Singleton = 0;
//
//FontManager::FontManager()
//{
//}
//
//FontManager::~FontManager()
//{
//	ClearList();
//}
//
//void FontManager::AddFont(const std::string &fileName, FontType type)
//{
//	ConstFLItr result = mFontList.find(fileName);
//	if(result == mFontList.end())
//	{
//		FTFont *font = 0;
//		switch(type)
//		{
//		case BITMAP:
//			font = dynamic_cast<FTFont*>(new FTBitmapFont(fileName.c_str()));
//			break;
//		case PIXMAP:
//			font = new FTPixmapFont(fileName.c_str());
//			break;
//		case TEXTURE:
//			font = new FTTextureFont(fileName.c_str());
//			break;
//		case BUFFERTEXTURE:
//			font = new FTBufferFont(fileName.c_str());
//			break;
//		};
//	
//		Font *addFont = new Font(fileName);
//		addFont->SetFontType(type);
//
//		size_t pos = fileName.find_last_of(".");
//		std::string name = fileName.substr(0,pos);
//		mFontList.insert(std::pair<std::string, Font*>(name, addFont)); 
//	}
//	else
//	{
//		std::cout << "Font: " << fileName << " is already in manager." << std::endl;
//	}
//}
//
//void FontManager::AddFont(Font &font)
//{
//	ConstFLItr it = mFontList.begin();
//	for(; it != mFontList.end(); ++it)
//	{
//		if(it->second != &font)
//		{
//			mFontList.insert(std::pair<std::string, Font*>(font.GetFileName(), &font));
//		}
//	}
//}
//
//void FontManager::RemoveFont(const std::string &name)
//{
//	FLItr it = mFontList.find(name);
//	if(it != mFontList.end())
//	{
//		delete it->second;
//		mFontList.erase(it);
//	}
//	else
//	{
//		std::cout << "Failed to delete: " << name << std::endl;
//	}
//}
//
//void FontManager::RemoveFont(Font &font)
//{
//	FLItr it = mFontList.begin();
//	for(; it != mFontList.end(); ++it)
//	{
//		if(it->second == &font)
//		{
//			delete it->second;
//			mFontList.erase(it);
//		}
//	}
//}
//
//Font *FontManager::GetFontByName(const std::string &name)
//{
//	ConstFLItr it = mFontList.find(name);
//	if(it != mFontList.end())
//	{
//		return it->second;
//	}
//	else
//	{
//		std::cout << "Failed to find: " << name << std::endl;
//		return 0;
//	}
//}
//
//void FontManager::ClearList()
//{
//	if(!mFontList.empty())
//	{
//		FLItr it = mFontList.begin();
//		for(; it == mFontList.end(); ++it)
//		{
//			delete (*it).second;
//		}
//		mFontList.clear();
//	}
//}
//
//FontManager &FontManager::GetSingleton()
//{
//	assert(ms_Singleton);
//	return (*ms_Singleton);
//}
//
//FontManager *FontManager::GetSingletonPtr()
//{
//	return ms_Singleton;
//}
//
//
//
