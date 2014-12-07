#include <Controller.hpp>
#include <Math.hpp>

using namespace ooge;

Controller::Controller(const UInt8 controllerID)
: mControllerId(controllerID)
{
	ResetInput();
	ZeroMemory(&mRawState, sizeof(XINPUT_STATE));
	mResult = XInputGetState(mControllerId, &mRawState);
	(mResult == ERROR_SUCCESS) ? mIsConntected = true : mIsConntected = false;
}

Controller::~Controller()
{
}

void Controller::ResetInput()
{
	ZeroMemory(&mRawState, sizeof(XINPUT_STATE));
	mControllerState.LeftThumbstickX =
		mControllerState.LeftThumbstickY =
		mControllerState.LeftTrigger =
		mControllerState.RightThumbstickX =
		mControllerState.RightThumbstickY =
		mControllerState.RightTrigger =
		mControllerState.Buttons = 0;
}

void Controller::Update()
{
	//check if controller is active
	if(!IsConnected())
	{
		ZeroMemory(&mRawState, sizeof(XINPUT_STATE));
		mControllerState.LeftThumbstickX =
		mControllerState.LeftThumbstickY =
		mControllerState.LeftTrigger =
		mControllerState.RightThumbstickX =
		mControllerState.RightThumbstickY =
		mControllerState.RightTrigger =
		mControllerState.Buttons = 0;
		return;
	}

	//fill struct information
	mControllerState.Buttons = mRawState.Gamepad.wButtons;
	mControllerState.LeftThumbstickX = mRawState.Gamepad.sThumbLX;
	mControllerState.LeftThumbstickY = mRawState.Gamepad.sThumbLY;
	mControllerState.LeftTrigger = static_cast<Int32>(mRawState.Gamepad.bLeftTrigger);
	mControllerState.RightThumbstickX = mRawState.Gamepad.sThumbRX;
	mControllerState.RightThumbstickY = mRawState.Gamepad.sThumbRY;
	mControllerState.RightTrigger = static_cast<Int32>(mRawState.Gamepad.bRightTrigger);

	//check deadzones
	if(mControllerState.LeftThumbstickX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
		mControllerState.LeftThumbstickX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
		mControllerState.LeftThumbstickY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
		mControllerState.LeftThumbstickY > - XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		mControllerState.LeftThumbstickX = mControllerState.LeftThumbstickY = 0;
	}

	if(mControllerState.RightThumbstickX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE &&
		mControllerState.RightThumbstickX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE &&
		mControllerState.RightThumbstickY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE &&
		mControllerState.RightThumbstickY > - XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
	{
		mControllerState.RightThumbstickX = mControllerState.RightThumbstickY = 0;
	}
	
}

const bool Controller::IsButtonDown(Int32 buttonmask)
{
	return (mControllerState.Buttons & buttonmask) ? true : false;
}

Int32 Controller::GetLeftTriggerValue() const
{
	return mControllerState.LeftTrigger;
}

Int32 Controller::GetRightTriggerValue() const
{
	return mControllerState.RightTrigger;
}

Vector2 Controller::GetLeftStickValue() const
{
	return Vector2(static_cast<float>(mControllerState.LeftThumbstickX / 32767.0f), 
		static_cast<float>(mControllerState.LeftThumbstickY / 32767.0f));
}

Vector2 Controller::GetRightStickValue() const
{
	return Vector2(static_cast<float>(mControllerState.RightThumbstickX / 32767.0f), 
		static_cast<float>(mControllerState.RightThumbstickY / 32767.0f));
}

void Controller::SetVibrationLeft(UInt32 left)
{
	left = math::Clamp(left, (UInt32)0, (UInt32)255);
	(left > 255) ? 65535 : (left << 8);

	XINPUT_VIBRATION vib;
	ZeroMemory(&vib, sizeof(XINPUT_VIBRATION));
	
	vib.wLeftMotorSpeed = mLeftVibration = left;
	vib.wRightMotorSpeed = mRightVibration;

	XInputSetState(mControllerId, &vib);
}

void Controller::SetVibrationRight(UInt32 right)
{
	right = math::Clamp(right, (UInt32)0, (UInt32)255);
	(right > 255) ? 65535 : (right << 8);

	XINPUT_VIBRATION vib;
	ZeroMemory(&vib, sizeof(XINPUT_VIBRATION));

	vib.wLeftMotorSpeed = mLeftVibration;
	vib.wRightMotorSpeed = mRightVibration = right;
}

UInt32 Controller::GetLeftVibration() const
{
	return mLeftVibration;
}

UInt32 Controller::GetRightVibration() const
{
	return mRightVibration;
}

const bool Controller::IsDpadUpDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_DPAD_UP) ? true : false;
}

const bool Controller::IsDpadRightDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_DPAD_RIGHT) ? true : false;
}

const bool Controller::IsDpadDownDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_DPAD_DOWN) ? true : false;
}

const bool Controller::IsDpadLeftDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_DPAD_LEFT) ? true : false;
}

const bool Controller::IsADown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_A) ? true : false;
}

const bool Controller::IsBDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_B) ? true : false;
}

const bool Controller::IsXDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_X) ? true : false;
}

const bool Controller::IsYDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_Y) ? true : false;
}

const bool Controller::IsLeftTriggerDown() const
{
	return (mControllerState.LeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD) ? true : false;
}

const bool Controller::IsRightTriggerDown() const
{
	return (mControllerState.RightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD) ? true: false;
}

const bool Controller::IsLeftShoulderDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_LEFT_SHOULDER) ? true : false;
}

const bool Controller::IsRightShoulderDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_RIGHT_SHOULDER) ? true : false;
}

const bool Controller::IsConnected()
{
	ZeroMemory(&mRawState, sizeof(XINPUT_STATE));
	mResult = XInputGetState(0, &mRawState);
	
	return (mIsConntected == ERROR_SUCCESS) ? mIsConntected = true : mIsConntected = false;
}

UInt8 Controller::GetControllerID() const
{
	return mControllerId;
}

const bool Controller::IsRightThumbstickButtonDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_RIGHT_THUMB) ? true : false;
}

const bool Controller::IsLeftThumbstickButtonDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_LEFT_THUMB) ? true : false;
}

const bool Controller::IsBackButtonDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_BACK) ? true : false;
}

const bool Controller::IsStartButtonDown() const
{
	return (mControllerState.Buttons & XINPUT_GAMEPAD_START) ? true : false;
}
