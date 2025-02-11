#include <d3d9.h>

#include "scriptenums.h"
#include "languages.h"
#include "fo2math.h"

#include "types/FO2String.h"
#include "types/FO2Vector.h"
#include "types/GameController.h"
#include "types/LiteDb.h"
#include "types/Car.h"
#include "types/ScoreManager.h"
#include "types/PlayerProfile.h"
#include "types/Controller.h"
#include "types/Player.h"
#include "types/CameraManager.h"
#include "types/MenuInterface.h"
#include "types/GameFlow.h"
#include "types/EventManager.h"
#include "types/Garage.h"
#include "types/GameSettings.h"
#include "types/DeviceD3d.h"
#ifndef NYA_COMMON_NO_D3D
#include "types/Font.h"
#endif
#include "types/HUD.h"
#include "types/LUA.h"
#include "types/LoadingScreen.h"
#include "types/DynamicObject.h"
#include "types/Track.h"
#include "types/MusicInterface.h"
#include "types/CupManager.h"
#include "types/Explosion.h"

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

class BFSManager {
public:

	static inline auto DoesFileExist = (bool(__stdcall*)(BFSManager*, const char*, int*))0x5B7170;
};
auto& pBFSManager = *(BFSManager**)0x846688;
auto DoesFileExist = (bool(__cdecl*)(const char*, char))0x5A5B80;

class FileCodec {
public:
	uint32_t _4[0];

	virtual void _vf0() = 0;
	virtual void _vf1() = 0;
	virtual void _vf2() = 0;
	virtual void _vf3() = 0;
	virtual void _vf4() = 0;
	virtual void _vf5() = 0;
	virtual void _vf6() = 0;
	virtual void _vf7() = 0;
	virtual size_t GetFileSize() = 0;
	virtual uint32_t GetFlags() = 0;
	virtual void _vf10() = 0;
	virtual void _vf11() = 0;
	virtual void _vf12() = 0;
	virtual void _vf13() = 0;
	virtual void _vf14() = 0;
	virtual void _vf15() = 0;
};

class File {
public:
	uint8_t _0[0x20];
	FileCodec* pFileCodec;

	static inline auto ReadBytes = (int(__thiscall*)(File*, void* out, int numBytes, int))0x5A5980;
};

auto ParseGameDDS = (bool(__thiscall*)(DevTexture* pThis, File* pFile, uint8_t* header))0x625AF0;

auto& pGameFilesChecksum1 = *(uint8_t**)0x825520; // uint8_t[20]
auto& pGameFilesChecksum2 = *(uint8_t**)0x82551C; // uint8_t[41]

auto& gGameRegion = *(int*)0x849314;

struct tLineOfSightIn {
	float fMaxDistance = 100.0;
	float* fUnk4 = nullptr;
	bool bGetClosestHit = false; // returns first match if false
	bool bIgnoreBackfaces = true;
	bool bSave4and8 = false;
	bool bSaveHitNormal = true;
	bool bSaveLast3Vectors = false;

	tLineOfSightIn() {
		if (auto env = pEnvironment) {
			fUnk4 = &env->fUnkForLOS;
		}
	}
};

struct tLineOfSightOut {
	float fHitDistance;
	float fUnk4;
	float fUnk8;
	uint32_t nSurfaceId; // surfaces.bed ID - 1
#ifdef NYA_MATH_H
	NyaVec3 vHitNormal;
	NyaVec3 vUnk[3];
#else
	float vHitNormal[3];
	float vUnk[3][3];
#endif
};

#ifdef NYA_MATH_H
auto CheckLineOfSight = (bool(__stdcall*)(tLineOfSightIn* prop, void* pUnkFromPlayerHost, NyaVec3* start, NyaVec3* dir, tLineOfSightOut* out))0x5CB8E0;
#else
auto CheckLineOfSight = (bool(__stdcall*)(tLineOfSightIn* prop, void* pUnkFromPlayerHost, float* start, float* dir, tLineOfSightOut* out))0x5CB8E0;
#endif