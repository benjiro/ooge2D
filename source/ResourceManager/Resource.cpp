#include <Resource.hpp>

using namespace ooge;

Resource::Resource(const unsigned int resourceNumber, const std::string &name, const std::string &path, const std::string &filename) :
	mName(name),
	mPath(path),
	mFilename(filename),
	mResourceNumber(resourceNumber)
{
}

Resource::~Resource()
{
}

std::string &Resource::GetName()
{ 
	return mName; 
}

std::string &Resource::GetPath() 
{ 
	return mPath; 
}

std::string &Resource::GetFilename() 
{ 
	return mFilename; 
}

unsigned int Resource::GetResourceNumber()
{
	return mResourceNumber;
}

void Resource::SetResourceNumber(unsigned int resourceNum)
{
	mResourceNumber = resourceNum;
}