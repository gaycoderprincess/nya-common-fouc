class Tire {
public:
	uint8_t _0[0x344];
	uint32_t bOnGround; // +344
	uint8_t _348[0x68];
};
static_assert(sizeof(Tire) == 0x3B0);

class Player;
class Car {
public:
	uint8_t _0[0x170];
	NyaVec3 vCollisionFullMin; // +170
	NyaVec3 vCollisionFullMax; // +17C
	NyaVec3 vCollisionBottomMin; // +188
	NyaVec3 vCollisionBottomMax; // +194
	NyaVec3 vCollisionTopMin; // +1A0
	NyaVec3 vCollisionTopMax; // +1AC
	uint8_t _1B8[0x8];
	float mMatrix[4*4]; // +1C0
	uint8_t _200[0x80];
	float qQuaternion[4]; // +280
	float vVelocity[3]; // +290
	uint8_t _29C[0x4];
	float vAngVelocity[3]; // +2A0
	uint8_t _2AC[0x4];
	float vVelocityGravity[3]; // +2B0
	uint8_t _2BC[0x330];
	float fNitro; // +5EC
	uint8_t _5F0[0x440];
	Tire aTires[4]; // +A30
	uint8_t _18F0[0x3D8];
	uint32_t nIsSkinCharred; // +1CC8
	uint8_t _1CCC[0x74];
	float fMass; // +1D40
	uint8_t _1D44[0x54];
	float vDriverLoc[3]; // +1D98
	uint8_t _1DA4[0x16C];
	float fGasPedal; // +1F10
	float fBrakePedal; // +1F14
	float fNitroButton; // +1F18
	float fHandbrake; // +1F1C
	float fSteerAngle; // +1F20
	uint8_t _1F24[0x166C];
	int nIsRagdolled; // +3590
	uint8_t _3594[0x1108];
	Player* pPlayer; // +469C
	uint8_t _46A0[0x3418];
	float fDamage; // +7AB8
	uint8_t _7ABC[0xC];
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
	inline NyaVec3* GetVelocityGravity() {
		return (NyaVec3*)vVelocityGravity;
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