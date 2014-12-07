#ifndef _CONTROLLER_LISTENER_HPP_
#define _CONTROLLER_LISTENER_HPP_

#include <Config.hpp>
#include <InputListener.hpp>
#include <vector>

namespace ooge
{
	class Controller;

	class OOGE_API ControllerListener : public InputListener
	{
	public:
		ControllerListener();
		~ControllerListener();

		Controller *GetControl(UInt8 id);

		virtual void Update();
	protected:
		void _ClearAll();
	private:
		Controller *mActiveControllers[4];
	};
}

#endif //_CONTROLLER_LISTENER_HPP_