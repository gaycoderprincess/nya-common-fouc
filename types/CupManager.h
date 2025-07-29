class CupManager {
public:
	struct tCupPlayer {
		uint32_t nPlayerId;
		uint32_t nCupPoints;
	};

	struct tRace {
		FO2String sName; // +0
		int nLevel; // +1C
		int nLaps; // +20
		int nAIHandicapOverridden; // +24
		int nAIUpgradeOverridden; // +28
		int nAIHandicapLevel; // +2C
		int nAIUpgradeLevel; // +30
		int nNextIndex1; // +34
		int nNextIndex2; // +38
		int nStartPosition; // +3C
		uint8_t _40[0x80];
		int nRules; // +C0
		int nEventType; // +C4
		int nWeather; // +C8
		int nIsFirstEvent; // +CC
		int nIsRaceCompleted; // +D0
		int nMedalTimes[3]; // +D4
	};
	static_assert(sizeof(tRace) == 0xE0);

	uint8_t _0[0x10];
	tRace aRaces[6]; // +10
	uint8_t _550[0x540];
	tCupPlayer aStandings[32]; // +A90
	uint32_t nCurrentRace; // +B90
	FO2String sCupName; // +B94
	uint32_t nNumRaces; // +BB0
	uint32_t nNumPlayers; // +BB4
	uint32_t nAIHandicapLevel; // +BB8
	uint32_t nAIUpgradeLevel; // +BBC
};
auto& pCupManager = *(CupManager**)0x9298FE8;
