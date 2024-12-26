class CupManager {
public:
	struct tCupPlayer {
		uint32_t nPlayerId;
		uint32_t nCupPoints;
	};

	uint8_t _0[0xA90];
	tCupPlayer aStandings[32]; // +A90
	uint32_t nResultsValid; // +B90
};
auto& pCupManager = *(CupManager**)0x9298FE8;
