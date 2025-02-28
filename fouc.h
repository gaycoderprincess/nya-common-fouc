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
#include "types/FileManager.h"

#include "fo2helpers.h"
#include "fo2hooks.h"

auto& gGameRegion = *(int*)0x849314;

struct tLineOfSightIn {
	float fMaxDistance = 100.0;
	SurfacePhysics* pSurfacePhysics = nullptr;
	bool bGetClosestHit = false; // returns first match if false
	bool bIgnoreBackfaces = true;
	bool bSave4and8 = false;
	bool bSaveHitNormal = true;
	bool bSaveLast3Vectors = false;

	tLineOfSightIn() {
		if (auto env = pEnvironment) {
			pSurfacePhysics = env->aSurfacePhysics;
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