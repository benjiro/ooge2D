#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_

#include <Config.hpp>
#include <windows.h>
#include <Xinput.h>
#include <Vector2.hpp>

namespace ooge
{
	struct ControllerState
	{
		Int32 LeftThumbstickX;
		Int32 LeftThumbstickY;
		Int32 RightThumbstickX;
		Int32 RightThumbstickY;
		Int32 LeftTrigger;
		Int32 RightTrigger;
		UInt32 Buttons;
	};

	class OOGE_API Controller
	{
	public:
		Controller(const UInt8 controllerID);
		~Controller();

		void Update();

		const bool IsButtonDown(Int32 buttonmask);
		
		void SetVibrationLeft(UInt32 left);
		void SetVibrationRight(UInt32 right);

		UInt32 GetLeftVibration() const;
		UInt32 GetRightVibration() const;

		Int32 GetLeftTriggerValue() const;
		Int32 GetRightTriggerValue() const;

		Vector2 GetLeftStickValue() const;
		Vector2 GetRightStickValue() const;

		const bool IsDpadUpDown() const;
		const bool IsDpadRightDown() const;
		const bool IsDpadDownDown() const;
		const bool IsDpadLeftDown() const;
		const bool IsADown() const;
		const bool IsBDown() const;
		const bool IsXDown() const;
		const bool IsYDown() const;
		const bool IsLeftTriggerDown() const;
		const bool IsRightTriggerDown() const;
		const bool IsLeftShoulderDown() const;
		const bool IsRightShoulderDown() const;
		const bool IsRightThumbstickButtonDown() const;
		const bool IsLeftThumbstickButtonDown() const;
		const bool IsBackButtonDown() const;
		const bool IsStartButtonDown() const;

		const bool IsConnected();
		UInt8 GetControllerID() const;
	private:
		void ResetInput();

		UInt8 mControllerId;
		bool mIsConntected;
		UInt32 mLeftVibration;
		UInt32 mRightVibration;

		ControllerState mControllerState;

		XINPUT_STATE mRawState;
		DWORD mResult;
	};
}

#endif //_CONTROLLER_HPP_