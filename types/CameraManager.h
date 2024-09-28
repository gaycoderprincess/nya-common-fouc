class Body {
public:
	float mMatrix[4*4]; // +1C0
	uint8_t _200[0x80];
	float qQuaternion[4]; // +280
	float vVelocity[3]; // +290
	uint8_t _29C[0x4];
	float vAngVelocity[3]; // +2A0
};

class Camera {
public:
	uint8_t _0[0xF0];
	float fLeft;
	float fRight;
	float fTop;
	float fBottom;
	uint8_t _100[0xC];
	float fNearZ;
	float fFarZ;
	float fFOV;
};

class CameraManager {
public:
	uint8_t _0[0x5C];
	Body* pTarget;
};
auto& pCameraManager = *(CameraManager**)0x9298FC0;