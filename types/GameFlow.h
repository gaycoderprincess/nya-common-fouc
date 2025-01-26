class PlayerHost {
public:
	uint8_t _0[0x14];
	FO2Vector<Player*> aPlayers; // +14
	uint8_t _20[0x990];
	float fPlayerVsAIFudgeFactor; // +9B0
	uint8_t _9B4[0xEE04];
	void* pUnkForLOS; // +F7B8
	uint8_t _F7BC[0x111E0];
	int32_t nRaceTime; // +2099C

	int GetNumPlayers() {
		return aPlayers.GetSize();
	}
};
auto& pPlayerHost = *(PlayerHost**)0x715E68;

enum eGameState {
	GAME_STATE_NONE,
	GAME_STATE_MENU,
	GAME_STATE_RACE
};

enum eRaceState {
	RACE_STATE_TRACKINTRO = 2,
	RACE_STATE_COUNTDOWN = 7,
	RACE_STATE_RACING = 8,
	RACE_STATE_FINISHED = 9,
	RACE_STATE_WANTSTOQUIT = 11,
};

class GameFlow {
public:
	struct tPreRace {
		int nMode; // +4B0
		int nRules; // +4B4
		int nDerbyType; // +4B8
		int nClass; // +4BC
		int nCup; // +4C0
		int nEvent; // +4C4
		int nCupChoice; // +4C8
		int nLevel; // +4CC
		int nWeather; // +4D0
		int nLaps; // +4D4
		int nCar; // +4D8
		int nCarSkin; // +4DC
		int nNumPlayers; // +4E0
		int nNumHunters; // +4E4
		int nUploadResults; // +4E8
		int nMenuData; // +4EC
		int nMenuData2; // +4F0
		float fUpgradeLevel; // +4F4
		float fNitroMultiplier; // +4F8
		float fDamageMultiplier; // +4FC
		float fScoreMultiplier; // +500 for arcade stunts
		int nWrongWayGhost; // +504
		int nNitroRegenType; // +508
		int nHandlingDamage; // +50C
		int nReversed; // +510
	};
	static_assert(sizeof(tPreRace) == 0x514-0x4B0);

	struct tPostRace {
		int nResult; // +530
		uint32_t nPlayerPosition[32]; // +534
		uint32_t nPlayerVisualPosition[32]; // +5B4
		uint32_t nRacePoints[32]; // +634
		uint32_t nFinishTime[32]; // +6B4
		uint32_t nFastestLapTime[32]; // +734
		uint32_t nArcadeScore[32]; // +7B4
		uint32_t nArcadeAward; // +834
		uint32_t nHighScorePos; // +838
		uint32_t nPreviousHighScore; // +83C
		uint32_t nBestWreckerId; // +840
		uint32_t nBlastMasterId; // +844
		uint32_t nFastestLapId; // +848
		uint32_t nDareDevilId; // +84C
		uint32_t nFragDerbyStreakerId; // +850
		uint32_t nFragDerbyStreakerCount; // +854
		uint32_t nFragDerbyVictimId; // +858
		uint32_t nFragDerbyVictimCount; // +85C
		uint32_t nFragDerbySurvivorId; // +860
		uint32_t nFragDerbySurvivorCount; // +864
		uint32_t nDerbyDamagePoints[32]; // +868
		uint32_t nDerbyWreckPoints[32]; // +8E8
		uint32_t nDerbyRankPoints[32]; // +968
		uint32_t nDerbyKills[32]; // +9E8
		uint32_t nStuntFinalScore[32]; // +A68
	};
	static_assert(sizeof(tPostRace) == 0xAE8-0x530);

	struct tAwards {
		int nAwardCar; // +14E8
		int nNumUnlockCar; // +14E8
		int aUnlockCar[256]; // +14F0
		int nNumUnlockSingleRace; // +18F0
		int aUnlockSingleRace[256]; // +18F4
		int NumUnlockArcadeRace; // +1CF4
		int aUnlockArcadeRaceClass[256]; // +1CF8
		int aUnlockArcadeRaceEvent[256]; // +20F8
		int nUnlockClass; // +24F8
		int nUnlockSubClass; // +24FC
		int nUnlockEvent; // +2500
		int nUnlockProfile; // +2504
		int nUnlockFinals; // +2508
		int nFinalCompleted; // +250C
		int nOMGGameCompletedGratzDING; // +2510
		int nArcadeCareerCompleted; // +2514
		int nArcadeCarCrashes; // +2518
		int nArcadeSceneryCrashes; // +251C
		int nArcadeAirtime; // +2520
		int nArcadePlaceBonus; // +2524
		int nArcadeTimeBonus; // +2528
		int nRaceWinnings[32]; // +252C
		int nCupWinnings[32]; // +25AC
		int nClassWinnings; // +262C
		int nSubClassWinnings; // +2630
		int nCrashWinnings; // +2634
		int nArcadeGoalScores[3]; // +2638
		uint8_t _2644[0x78];
		int nSuperFlip; // +26BC
		int nWhammo; // +26C0
		int nPowerHit; // +26C4
		int nBlastOut; // +26C8
		int nWrecked; // +26CC
		int nRagdolled; // +26D0
		int nBigAir; // +26D4
		int nNumSuperFlip; // +26D8
		int nNumWhammo; // +26DC
		int nNumPowerHit; // +26E0
		int nNumBlastOut; // +26E4
		int nNumWrecked; // +26E8
		int nNumRagdolled; // +26EC
		int nNumBigAir; // +26F0
		int nBestWrecker; // +26F4
		int nBlastMaster; // +26F8
		int nFastestLap; // +26FC
		int nDareDevil; // +2700
		int nTotalCashAwarded; // +2704
	};
	static_assert(sizeof(tAwards) == 0x2708-0x14E8);

	uint8_t _0[0x4A4];
	int nGameState;
	uint8_t _4A8[0x8];
	tPreRace PreRace; // +4B0
	int nGameRules; // +514
	int nStuntType; // +518
	int nDerbyType; // +51C
	int nStuntStartPosition; // +520
	int nNitroRegen; // +524
	int nIsEventTrack; // +528
	int nIsDerbyTrack; // +52C
	tPostRace PostRace; // +530
	PlayerInfo aPlayerInfos[32]; // +AE8
	tAwards Awards; // +14E8
	uint8_t _2708[0x30];
	uint32_t nRaceState; // +2738
	uint8_t _273C[0x18];
	uint32_t nIsPauseMenuUp; // +2754
	uint8_t _2758[0x4];
	uint32_t nIsInReplay; // +275C
	uint8_t _2760[0xC0];
	PlayerHost* pHost; // +2820
	uint8_t _2824[0xC];
	MenuInterface* pMenuInterface; // +2830
	uint8_t _2834[0x61C];
	PlayerProfile Profile; // +2E50

	static inline auto& fArcadeRewardWhammo = *(float*)0x765080;
	static inline auto& fArcadeRewardPowerHit = *(float*)0x765084;
	static inline auto& fArcadeRewardSuperFlip = *(float*)0x76508C;
	static inline auto& fArcadeRewardBigAir = *(float*)0x765098;
	static inline auto& fArcadeRewardWrecked = *(float*)0x765094;
	static inline auto& fArcadeRewardRagdolled = *(float*)0x765090;
	static inline auto& fArcadeRewardBlastOut = *(float*)0x765088;
	static inline auto& fArcadeRacePositionBonus = *(float*)0x765038;
	static inline auto& fFragDerbyBombMaxDistance = *(float*)0x76510C;

	static inline uintptr_t AddArcadeRaceScore_call = 0x46F300;
	static void __attribute__((naked)) __fastcall AddArcadeRaceScore(const wchar_t* name, int category, GameFlow* game, float score, int position) {
		__asm__ (
			"mov eax, ecx\n\t"
			"mov ecx, edx\n\t"
			"jmp %0\n\t"
				:
				:  "m" (AddArcadeRaceScore_call)
		);
	}

	static inline auto InitializeAI = (void(__stdcall*)(GameFlow* pThis, int count))0x4693F0;

	static GameFlow* GetInstance() {
		return *(GameFlow**)0x9298FAC;
	}
};
auto& pGameFlow = *(GameFlow**)0x9298FAC;

Player* GetPlayer(int id) {
	auto host = pGameFlow->pHost;
	if (!host) return nullptr;
	if (id < 0 || id >= host->aPlayers.GetSize()) return nullptr;
	auto ply = host->aPlayers[id];
	if (!ply || !ply->pCar) return nullptr;
	return ply;
}