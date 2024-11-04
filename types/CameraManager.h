class Body {
public:
	float mMatrix[4*4]; // +1C0
	uint8_t _200[0x80];
	float qQuaternion[4]; // +280
	float vVelocity[3]; // +290
	uint8_t _29C[0x4];
	float vAngVelocity[3]; // +2A0

#ifdef NYA_MATH_H
	inline NyaMat4x4* GetMatrix() {
		return (NyaMat4x4*)mMatrix;
	}
	inline NyaVec3* GetVelocity() {
		return (NyaVec3*)vVelocity;
	}
	inline NyaVec3* GetAngVelocity() {
		return (NyaVec3*)vAngVelocity;
	}
#endif
};

class Camera {
public:
	uint8_t _0[0x40];
	float mMatrix[4*4]; // +40
	uint8_t _80[0x70];
	float fLeft; // +F0
	float fRight; // +F4
	float fTop; // +F8
	float fBottom; // +FC
	uint8_t _100[0xC];
	float fNearZ; // +10C
	float fFarZ; // +110
	float fFOV; // +114

#ifdef NYA_MATH_H
	inline NyaMat4x4* GetMatrix() {
		return (NyaMat4x4*)mMatrix;
	}
#endif
};

class CameraManager {
public:
	uint8_t _0[0x50];
	Camera* pCamera; // +50
	uint8_t _54[0x8];
	Body* pTarget; // +5C
};
auto& pCameraManager = *(CameraManager**)0x9298FC0;