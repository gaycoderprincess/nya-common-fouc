class Track {
public:
	// size 0x40
	struct tSplitpoint {
		float fLeft[3]; // +0
		float fRight[3]; // +C
		float fPosition[3]; // +18
		uint8_t _24[0x1C];
	};
	// size 0x50
	struct tStartpoint {
		float fPosition[4];
		float fMatrix[4*4];
	};

	uint8_t _0[0x28D8];
	uint32_t nNumSplitpoints; // +28D8
	tSplitpoint aSplitpoints[32]; // +28DC
	uint8_t _30DC[0x804];
	tStartpoint aStartpoints[32]; // +38E0
	uint8_t _42E0[0x1540];
	uint32_t nNumStartpoints; // +5820
};

class TrackAI {
public:
	uint8_t _0[0x468];
	Track* pTrack; // +468
};
auto& pTrackAI = *(TrackAI**)0x9298FA8;