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
	float fUnk100; // +100
	float fUnk104; // +104
	int nUnk108; // +108
	float fNearZ; // +10C
	float fFarZ; // +110
	float fFOV; // +114

#ifdef NYA_MATH_H
	inline NyaMat4x4* GetMatrix() {
		return (NyaMat4x4*)mMatrix;
	}
#endif

	NyaMat4x4 BuildProjectionMatrix() {
		NyaMat4x4 f;
		if (nUnk108) {
			f[0] = 2.0 / (fRight - fLeft);
			f[1] = 0.0;
			f[2] = 0.0;
			f[3] = 0.0;
			f[4] = 0.0;
			f[5] = 2.0 / (fBottom - fTop);
			f[6] = 0.0;
			f[7] = 0.0;
			f[8] = 0.0;
			f[9] = 0.0;
			f[10] = 1.0 / (fUnk104 - fUnk100);
			f[11] = 0.0;
			f[12] = (fRight + fLeft) / (fLeft - fRight);
			f[13] = (fBottom + fTop) / (fTop - fBottom);
			f[14] = fUnk100 / (fUnk100 - fUnk104);
			f[15] = 1.0;
		}
		else {
			f[0] = fUnk100 * 2.0 / (fRight - fLeft);
			f[1] = 0.0;
			f[2] = 0.0;
			f[3] = 0.0;
			f[4] = 0.0;
			f[5] = 2.0 * fUnk100 / (fBottom - fTop);
			f[6] = 0.0;
			f[7] = 0.0;
			f[8] = (fRight + fLeft) / (fLeft - fRight);
			f[9] = (fBottom + fTop) / (fTop - fBottom);
			f[10] = fUnk104 / (fUnk104 - fUnk100);
			f[11] = 1.0;
			f[12] = 0.0;
			f[13] = 0.0;
			f[14] = fUnk104 * fUnk100 / (fUnk100 - fUnk104);
			f[15] = 0.0;
		}
		return f;
	}
};

class CameraDirector {
public:
	uint8_t _0[0x20];
	Camera Camera; // +20
};

class PlayerCamera {
public:
	uint8_t _0[0x4];
	CameraDirector* pCameraDirector; // +4
};

class CameraManager {
public:
	uint8_t _0[0x4];
	FO2Vector<PlayerCamera*> aPlayerCameras; // +4
	uint8_t _10[0x40];
	Camera* pCamera; // +50
	uint8_t _54[0x8];
	Body* pTarget; // +5C
};
auto& pCameraManager = *(CameraManager**)0x9298FC0;