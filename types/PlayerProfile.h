class ArcadeRace {
public:
	uint32_t nScore; // +0
	uint32_t nPlacement; // +4, 255 if locked, 254 if unlocked, 1, 2, 3 otherwise
	uint32_t nLevel; // +8
	uint32_t nCar; // +C
	uint32_t nCarSkin; // +10
	uint32_t nPointsToUnlock; // +14
	uint32_t nCarUnlock; // +18
	uint32_t nRules; // +1C
	uint32_t nGoalScores[3]; // +20
	float fUpgradeLevel; // +2C
	float fAIUpgradeLevel; // +30
	uint32_t nAIHandicapLevel; // +34
	float fNitroMultiplier; // +38
	float fScoreMultiplier; // +3C
	uint32_t nRacePositionBonus[3]; // +40
	uint32_t nBonusPerSecondLeft; // +4C
	uint32_t nCrashBonuses[7]; // +50
	void* pAITargetPlayer; // +6C
};
static_assert(sizeof(ArcadeRace) == 0x70);

class PlayerProfile {
public:
	uint8_t _0[0x3D0];
	struct {
		ArcadeRace* races;
		uint32_t numRaces;
	} aArcadeClasses[0]; // +3D0
	uint8_t _3D0[0x30];
	Garage Garage; // +400
	uint8_t _464[0xE0C];
	wchar_t sPlayerName[16]; // +1270
	uint8_t _1290[0x24];
	int32_t nMoney; // +12B4
	uint8_t _12B8[0x2];
	uint8_t nActiveCar; // +12BA
	uint8_t _12BB[0x3];
	uint8_t aCupPoints[12]; // +12BE
};