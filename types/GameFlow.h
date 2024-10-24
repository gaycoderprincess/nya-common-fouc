class PlayerHost {
public:
	uint8_t _0[0x14];
	Player** aPlayers;
	Player** aPlayersEnd;

	int GetNumPlayers() {
		return aPlayersEnd - aPlayers;
	}
};

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
	uint8_t _0[0x4A4];
	int nGameState;
	uint8_t _4A8[0x8];
	int nGameMode; // +4B0
	int nGameRules; // +4B4
	uint8_t _4B8[0x4];
	int nAIClass; // +4BC
	uint8_t _4C0[0xC];
	int nLevelId; // +4CC
	uint8_t _4D0[0x4];
	int nNumLaps; // +4D4
	int nInstantActionCar; // +4D8
	int nInstantActionCarSkin; // +4DC
	uint8_t _4E0[0x18];
	float fNitroMultiplier; // +4F8
	uint8_t _4FC[0x18];
	int nGameRulesIngame; // +514
	int nStuntType; // +518
	int nDerbyType; // +51C
	uint8_t _520[0xFCC];
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
	uint8_t _2824[0x62C];
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
	static void __attribute__((naked)) __fastcall AddArcadeRaceScore(const wchar_t* name, int category, GameFlow* game, float score, int unknown) {
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