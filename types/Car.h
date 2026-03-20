class TireDynamics {
public:
	uint8_t _0[0x58];
};
static_assert(sizeof(TireDynamics) == 0x58);

class Object {
public:
	uint8_t _0[0x40];
	float mMatrix[4*4]; // +40
	uint8_t _80[0x4C];
	FO2String sName; // +CC
	uint8_t _E8[0x8];

#ifdef NYA_MATH_H
	inline NyaMat4x4* GetMatrix() {
		return (NyaMat4x4*)mMatrix;
	}
#endif
};
static_assert(sizeof(Object) == 0xF0);

class Tire : public Object {
public:
	// +0 vtable
	// +4 some ptr
	// +18 some float related to wheel speed decay, 0.5
	// +2C wheel speed!!
	// +30 some float related to wheel speed decay
	// +3C some float related to wheel speed decay, -2000
	// +1DC wheel radius
	// +210 might be useful, its checked against at 0042A9E7
	// +224 some ptr
	// +228 slidecontrol related, 0.1971743107
	// +240 brake torque
	// +244 tire smoke rear
	// +248 tire smoke side, 100 seems to be a reasonable value (to the left)
	// +24C wheel rotation!!
	// +25C steer angle offset
	// +2AC
	// +2B0 skid sound scale!! 10 is still off, 11 is where it begins, 15 is around max
	// +2B4 skid sound scale!! 0-50 or so

	uint8_t _F0[0x2C];
	float fTurnSpeed; // +11C
	uint8_t _120[0x1AC];
	float fRadius; // +2CC
	uint8_t _2D0[0x60];
	float fBrakeTorque; // +330
	float fTireSmokeZ; // +334
	float fTireSmokeX; // +338
	float fWheelAngle; // +33C
	uint8_t _340[0x4];
	uint32_t bOnGround; // +344
	uint8_t _348[0x4];
	float fDamagedSteer; // +34C
	uint8_t _350[0x8];
	TireDynamics* pGroundSurface; // +358
	uint8_t _35C[0x44];
	float fSkidSound1; // +3A0
	float fSkidSound2; // +3A4
	uint8_t _3A8[0x8];
};
static_assert(sizeof(Tire) == 0x3B0);
static_assert(offsetof(Tire, fTurnSpeed) == 0xF0+0x2C);
static_assert(offsetof(Tire, fRadius) == 0xF0+0x1DC);
static_assert(offsetof(Tire, fBrakeTorque) == 0xF0+0x240);
static_assert(offsetof(Tire, fTireSmokeZ) == 0xF0+0x244);
static_assert(offsetof(Tire, fTireSmokeX) == 0xF0+0x248);
static_assert(offsetof(Tire, fDamagedSteer) == 0xF0+0x25C);
static_assert(offsetof(Tire, fSkidSound1) == 0xF0+0x2B0);
static_assert(offsetof(Tire, fSkidSound2) == 0xF0+0x2B4);
static_assert(offsetof(Tire, pGroundSurface) == 0x358);

class Gearbox {
public:
	uint8_t _0[0x48];
	int8_t nGear; // +48
	uint8_t _49[0x7B];
};
static_assert(sizeof(Gearbox) == 0xC4);

class Player;
class DevTexture;
class Car {
public:
	uint8_t _0[0x170];
#ifdef NYA_MATH_H
	NyaVec3 vCollisionFullMin; // +170
	NyaVec3 vCollisionFullMax; // +17C
	NyaVec3 vCollisionBottomMin; // +188
	NyaVec3 vCollisionBottomMax; // +194
	NyaVec3 vCollisionTopMin; // +1A0
	NyaVec3 vCollisionTopMax; // +1AC
#else
	float vCollisionFullMin[3]; // +170
	float vCollisionFullMax[3]; // +17C
	float vCollisionBottomMin[3]; // +188
	float vCollisionBottomMax[3]; // +194
	float vCollisionTopMin[3]; // +1A0
	float vCollisionTopMax[3]; // +1AC
#endif
	uint8_t _1B8[0x8];
	float mMatrix[4*4]; // +1C0
	uint8_t _200[0x80];
	float qQuaternion[4]; // +280
	float vVelocity[3]; // +290
	uint8_t _29C[0x4];
	float vAngVelocity[3]; // +2A0
	uint8_t _2AC[0x4];
	float vImpulse[3]; // +2B0
	uint8_t _2BC[0x4];
	float vAngImpulse[3]; // +2C0
	uint8_t _2CC[0x68];
	float fGlobalMassFudge; // +334
	float fBumpMassFudge; // +338
	uint8_t _33C[0x2B0];
	float fNitro; // +5EC
	float fMaxNitro; // +5F0
	uint8_t _5F4[0x4];
	float fRPM; // +5F8
	uint8_t _5FC[0x18];
	Gearbox mGearbox; // +614
	uint8_t _6D8[0x358];
	Tire aTires[4]; // +A30
	uint8_t _18F0[0x390];
	FO2Vector<Object*> aObjects; // +1C80
	uint8_t _1C8C[0x24];
	FO2Vector<DevTexture*> aTextureNodes; // +1CB0
	uint8_t _1CBC[0xC];
	uint32_t nIsSkinCharred; // +1CC8
	uint8_t _1CCC[0x74];
	float fMass; // +1D40
	uint8_t _1D44[0x10];
	float vCenterOfMassAbsolute[3]; // +1D54
	uint8_t _1D60[0xC];
	float vDriverLocAbsolute[3]; // +1D6C with center of mass
	uint8_t _1D78[0x20];
	float vDriverLoc[3]; // +1D98
	float vCenterOfMass[3]; // +1DA4
	uint8_t _1DB0[0x160];
	float fGasPedal; // +1F10
	float fBrakePedal; // +1F14
	float fNitroButton; // +1F18
	float fHandbrake; // +1F1C
	float fSteerAngle; // +1F20
	uint8_t _1F24[0x54];
	TireDynamics TireDynamics[8]; // +1F78
	uint8_t _2238[0x790];
	int nGroundSurfaces[4]; // +29C8
	uint8_t _29CC[0xA28];
	DevTexture* pShadow; // +3400
	uint8_t _3404[0x18C];
	int nIsRagdolled; // +3590
	uint8_t _3594[0xBD4];
	float vEngineFirePosition[3]; // +4168
	float vEngineSmokePosition[3]; // +4174
	uint8_t _4180[0x280];
	DevTexture* pSkinBurned; // +4400
	DevTexture* pTireBurned; // +4404
	DevTexture* pSkin; // +4408
	DevTexture* pSkinDamaged; // +440C
	uint8_t _4410[0x8];
	DevTexture* pSkinSpecular; // +4418
	DevTexture* pLightsDamaged; // +441C
	DevTexture* pLightsGlow; // +4420
	DevTexture* pLightsGlowLit; // +4424
	DevTexture* pLightsDamagedGlow; // +4428
	uint8_t _442C[0x270];
	Player* pPlayer; // +469C
	uint8_t _46A0[0x3418];
	float fDamage; // +7AB8
	uint8_t _7ABC[0x8];
	uint32_t nShouldExplode; // +7AC4
	uint32_t nIsWrecked; // +7AC8

#ifdef NYA_MATH_H
	inline NyaMat4x4* GetMatrix() {
		return (NyaMat4x4*)mMatrix;
	}
	inline NyaVec4* GetQuaternion() {
		return (NyaVec4*)qQuaternion;
	}
	inline NyaVec3* GetVelocity() {
		return (NyaVec3*)vVelocity;
	}
	inline NyaVec3* GetAngVelocity() {
		return (NyaVec3*)vAngVelocity;
	}
	inline NyaVec3* GetImpulse() {
		return (NyaVec3*)vImpulse;
	}
	inline NyaVec3* GetAngImpulse() {
		return (NyaVec3*)vAngImpulse;
	}
#endif

	// 4403C0
	Object* GetObjectByName(const std::string& name) {
		for (int i = 0; i < aObjects.GetSize(); i++) {
			if (aObjects[i]->sName.Get() == name) return aObjects[i];
		}
		return nullptr;
	}

	static inline auto CalculatePerformance = (void(*)(float* out, float torque, float torqueRPM, float power, float powerRPM, float zeroRPM, float redlineRPM))0x45C750;
	static inline auto LoadDriveLights = (void(__stdcall*)(Car*, const char* dataPath))0x433420;

	static inline uintptr_t Fix_call = 0x4287A0;
	int __attribute__((naked)) __fastcall Fix(bool resetSomeValue) {
		__asm__ (
			"mov eax, ecx\n\t"
			"push edx\n\t"
			"call %0\n\t"
			"ret\n\t"
				:
				:  "m" (Fix_call)
		);
	}
};
static_assert(offsetof(Car, fRPM) == 0x5F8);
static_assert(offsetof(Car, mGearbox.nGear) == 0x65C);
static_assert(offsetof(Car, fSteerAngle) == 0x1F20);
static_assert(offsetof(Car, nGroundSurfaces) == 0x29C8);
static_assert(offsetof(Car, aTires[0].bOnGround) == 0xD74);
static_assert(offsetof(Car, aTires[0].pGroundSurface) == 0xD88);
static_assert(offsetof(Car, pShadow) == 0x3400);

uintptr_t GetCarDataPath_call = 0x4C6340;
int __attribute__((naked)) __fastcall GetCarDataPath(int dbCar, bool isMenuCar) {
	__asm__ (
		"mov eax, ecx\n\t"
		"push edx\n\t"
		"call %0\n\t"
		"pop edx\n\t"
		"ret\n\t"
			:
			:  "m" (GetCarDataPath_call)
	);
}