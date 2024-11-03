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
#include "types/Player.h"
#include "types/GameFlow.h"
#include "types/EventManager.h"
#include "types/Garage.h"
#include "types/CameraManager.h"
#include "types/GameSettings.h"
#ifndef NYA_COMMON_NO_D3D
#include "types/DeviceD3d.h"
#include "types/Font.h"
#endif
#include "types/HUD.h"
#include "types/LUA.h"
#include "types/LoadingScreen.h"
#include "types/Environment.h"
#include "types/DynamicObject.h"
#include "types/Track.h"
#include "types/MusicInterface.h"
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

auto& gGameRegion = *(int*)0x849314;