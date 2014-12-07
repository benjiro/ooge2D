#include <ControllerListener.hpp>
#include <Controller.hpp>
#include <Math.hpp>

using namespace ooge;

ControllerListener::ControllerListener()
{
	for(int i = 0; i < 4; ++i)
		mActiveControllers[i] = new Controller(i);
}

ControllerListener::~ControllerListener()
{
	_ClearAll();
}

Controller *ControllerListener::GetControl(UInt8 id)
{
	id = math::Clamp(id, (UInt8)1, (UInt8)4);
	return mActiveControllers[id - 1];
}

void ControllerListener::Update()
{
	for(int i = 0; i < 4; ++i)
		mActiveControllers[i]->Update();
}

void ControllerListener::_ClearAll()
{
	for(int i = 0; i < 4; ++i)
		delete mActiveControllers[i];
}
