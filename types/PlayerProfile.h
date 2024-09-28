class ArcadeRaceStats {
public:
	uint32_t score; // +0
	uint32_t placement; // +4, 255 if locked, 254 if unlocked, 1, 2, 3 otherwise
	uint8_t _8[0xC];
	uint32_t unlockScore; // +14
	uint8_t _18[0x8];
	uint32_t targetScores[3]; // +20
	uint8_t _2C[0x44];
};
static_assert(sizeof(ArcadeRaceStats) == 0x70);

class PlayerProfile {
public:
	uint8_t _0[0x3D0];
	struct {
		ArcadeRaceStats* races;
		uint32_t numRaces;
	} aArcadeClasses[0]; // +3D0
	uint8_t _3D0[0xEEA];
	uint8_t nActiveCar; // +12BA
};