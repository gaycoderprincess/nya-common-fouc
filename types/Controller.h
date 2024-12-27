enum eControllerInput {
	INPUT_HANDBRAKE = 0,
	INPUT_NITRO = 1,
	INPUT_CAMERA = 3,
	INPUT_LOOK_BEHIND = 4,
	INPUT_RESET = 5,
	INPUT_PLAYERLIST = 7,
	INPUT_MENU_ACCEPT = 8,
	INPUT_PAUSE = 9,
	INPUT_ACCELERATE = 10,
	INPUT_BRAKE = 11,
	INPUT_STEER_LEFT = 12,
	INPUT_STEER_RIGHT = 13,
	INPUT_GEAR_DOWN = 18,
	INPUT_GEAR_UP = 19,
};

class Controller {
public:
	uint32_t _4[1];

	virtual void _vf0() = 0;
	virtual void Initialize() = 0;
	virtual void InitForceFeedback() = 0;
	virtual void _vf3() = 0;
	virtual void _vf4() = 0;
	virtual void _vf5() = 0;
	virtual void _vf6() = 0;
	virtual void _vf7() = 0;
	virtual void _vf8() = 0;
	virtual void _vf9() = 0;
	virtual void _vf10() = 0;
	virtual int GetInputValue(int input) = 0;
	virtual void _vf12() = 0;
	virtual void SetControlLayout(int id) = 0;
	virtual void _vf14() = 0;
	virtual void _vf15() = 0;
	virtual int GetInputValueAnalog(int input, float* out) = 0;
	virtual float GetLeftTrigger() = 0;
	virtual float GetRightTrigger() = 0;
	virtual float GetLeftStickX() = 0;
	virtual float GetLeftStickY() = 0;
	virtual float GetRightStickX() = 0;
	virtual float GetRightStickY() = 0;
};

class XInputController : public Controller {
public:
	uint8_t _8[0x814];
	float fLeftStickX; // +81C
	float fLeftStickY; // +81C
	float fRightStickX; // +820
	float fRightStickY; // +824
	float fLeftTrigger; // +828
	float fRightTrigger; // +82C
};