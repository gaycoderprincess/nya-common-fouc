class Tire {
public:
	uint8_t _0[0x344];
	uint32_t bOnGround; // +344
	uint8_t _348[0x68];
};
static_assert(sizeof(Tire) == 0x3B0);

// todo: gear is at 65C overall, part of Gearbox

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
	uint8_t _5F4[0x43C];
	Tire aTires[4]; // +A30
	uint8_t _18F0[0x3C0];
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
	uint8_t _1F24[0x14DC];
	DevTexture* pShadow; // +3400
	uint8_t _3404[0x18C];
	int nIsRagdolled; // +3590
	uint8_t _3594[0xE6C];
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

	static inline auto CalculatePerformance = (void(*)(float* out, float torque, float torqueRPM, float power, float powerRPM, float zeroRPM, float redlineRPM))0x45C750;

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