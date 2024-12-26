class PlayerHost {
public:
	uint8_t _0[0x14];
	FO2Vector<Player*> aPlayers; // +14
	uint8_t _20[0xF798];
	void* pUnkForLOS; // +F7B8
	uint8_t _F7BC[0x111E0];
	uint32_t nRaceTime; // +2099C

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
	RACE_STATE_QUITTING = 9,
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
		int nUpgradeLevel; // +4F4
		int nNitroMultiplier; // +4F8
		int nDamageMultiplier; // +4FC
		uint8_t _500[0x4];
		int nWrongWayGhost; // +504
		int nNitroRegenType; // +508
		int nHandlingDamage; // +50C
		int nReversed; // +510
	};
	static_assert(sizeof(tPreRace) == 0x514-0x4B0);

	uint8_t _0[0x4A4];
	int nGameState;
	uint8_t _4A8[0x8];
	tPreRace PreRace; // +4B0
	int nGameRulesIngame; // +514
	int nStuntType; // +518
	int nDerbyType; // +51C
	uint8_t _520[0x14];
	uint32_t nPlayerIdByPosition[32]; // +534
	uint8_t _5B4[0x534];
	PlayerInfo aPlayerInfos[32]; // +AE8
	uint8_t _14E8[0x4];
	uint32_t NumUnlockCar; // +14EC
	uint32_t UnlockCar[16]; // +14F0
	uint8_t _1530[0x1108];
	uint32_t nArcadeTargets[3]; // +2638
	uint8_t _2644[0x78];
	uint32_t nArcadeRewardSuperFlip; // +26BC
	uint32_t nArcadeRewardWhammo; // +26C0
	uint32_t nArcadeRewardPowerHit; // +26C4
	uint32_t nArcadeRewardBlastOut; // +26C8
	uint32_t nArcadeRewardWrecked; // +26CC
	uint32_t nArcadeRewardRagdolled; // +26D0
	uint32_t nArcadeRewardBigAir; // +26D4
	uint8_t _26D8[0x60];
	uint32_t nRaceState; // +2738
	uint8_t _273C[0xE4];
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