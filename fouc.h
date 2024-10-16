#include "scriptenums.h"
#include "languages.h"
#include "fo2math.h"
#include "types/GameController.h"
#include "types/LiteDb.h"
#include "types/Car.h"
#include "types/ScoreManager.h"
#include "types/PlayerProfile.h"
#include "types/GameFlow.h"
#include "types/EventManager.h"
#include "types/Player.h"
#include "types/Garage.h"
#include "types/CameraManager.h"
#include "types/DeviceD3d.h"
#include "types/GameSettings.h"
#ifndef NYA_COMMON_NO_D3D
#include "types/Font.h"
#endif
#include "types/HUD.h"
#include "types/LUA.h"
#include "types/LoadingScreen.h"
#include "fo2helpers.h"
#include "fo2hooks.h"

uintptr_t SetTextureFolder_call = 0x5A6E20;
void __attribute__((naked)) __fastcall SetTextureFolder(const char* path) {
	__asm__ (
		"mov eax, ecx\n\t"
		"jmp %0\n\t"
			:
			: "m" (SetTextureFolder_call)
	);
}

uintptr_t SetSharedTextureFolder_call = 0x5A6E90;
void __attribute__((naked)) __fastcall SetSharedTextureFolder(const char* path) {
	__asm__ (
		"mov eax, ecx\n\t"
		"jmp %0\n\t"
			:
			: "m" (SetSharedTextureFolder_call)
	);
}

uintptr_t CheckFileIntegrity_call = 0x5DAF00;
void __attribute__((naked)) __fastcall CheckFileIntegrity(void* a1, const char* a2) {
	__asm__ (
		"push edx\n\t"
		"call %0\n\t"
		"add esp, 4\n\t"
		"ret\n\t"
			:
			: "m" (CheckFileIntegrity_call)
	);
}

auto sTextureFolder = (const char*)0x845B78;
auto sSharedTextureFolder = (const char*)0x845C80;

auto BFSManager_DoesFileExist = (bool(__stdcall*)(void*, const char*, int*))0x5B7170;

auto& pGameFilesChecksum1 = *(uint8_t**)0x825520; // uint8_t[20]
auto& pGameFilesChecksum2 = *(uint8_t**)0x82551C; // uint8_t[41]

class Environment {
public:
	uint8_t _0[0x22F4];
	bool bWaterPlane; // +22F4
};
auto& pEnvironment = *(Environment**)0x8465F0;

class Model {
public:
	uint8_t _0[0x8];
	NyaVec3 vBBoxMin; // +8
	NyaVec3 vBBoxMax; // +14
	NyaVec3 vRadius; // +20
	float fRadius; // +2C
};

class CompactMesh {
public:
	struct tSomeStruct {
		uint8_t _0[0x10];
		struct {
			Model* pModel;
			uint8_t _4[0x4];
		} aModels[0]; // +10
	};

	uint8_t _0[0x1C];
	tSomeStruct* pSomeStruct; // +1C
};

class DynamicObject {
public:
	uint8_t _0[0x2C];
	CompactMesh* pMesh; // +2C
	float mMatrix[4*4]; // +30
	uint8_t _70[0x80];
	float qQuaternion[4]; // +F0
	float vVelocity[3]; // +100
	uint8_t _10C[0x4];
	float vAngVelocity[3]; // +110
	uint8_t _11C[0x20];
	float fMass; // +13C

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