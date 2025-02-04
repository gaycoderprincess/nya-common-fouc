class Minimap {
public:
	uint8_t _0[0x290];
	float fMapTopLeft[3]; // +290
	float fMapBottomRight[3]; // +29C
};

class Track {
public:
	struct tSplitpoint {
		float fLeft[3]; // +0
		float fRight[3]; // +C
		float fPosition[3]; // +18
		uint8_t _24[0x1C];
	};
	static_assert(sizeof(tSplitpoint) == 0x40);

	struct tStartpoint {
		float fPosition[4];
		float fMatrix[4*4];
	};
	static_assert(sizeof(tStartpoint) == 0x50);

	struct tMaterial {
		DevTexture* pTexture;
		DevTexture* pTexture2; // usually glow? at least for particles
		uint8_t _4[0x98];
	};
	static_assert(sizeof(tMaterial) == 0xA0);

	uint8_t _0[0x294];
	float fUnkForLOS; // +294
	uint8_t _298[0x194C];
	float fTreeLodFadeBegin; // +1BE4
	float fTreeLodFadeEnd; // +1BE8
	float fTreeLodNullDistance; // +1BEC
	float fBushLodFadeBegin; // +1BF0
	float fBushLodFadeEnd; // +1BF4
	float fBushLodNullDistance; // +1BF8
	uint8_t _1BFC[0x184];
	float fShadowR[4]; // +1D80
	float fShadowG[4]; // +1D90
	float fShadowB[4]; // +1DA0
	uint8_t _1DB0[0xF0];
	float mSunPosition[4][4]; // +1EA0
	uint8_t _1EE0[0x12C];
	float fMaxVisibility; // +200C
	float fMaxVisibilitySplit; // +2010
	float fMaxObjectVisibility; // +2014
	float fMaxObjectVisibilityInReflection; // +2018
	uint8_t _201C[0x14];
	tMaterial Skidmark; // +2030
	tMaterial Particles; // +20D0
	tMaterial ParticlesAmbient; // +2170
	tMaterial PowerlineAlpha; // +2210
	DevTexture* pParticlesSparks; // +22B0
	uint8_t _22B4[0x14];
	float fWaterColorMin[3]; // +22C8
	float fWaterColorMax[3]; // +22D4
	float fWaterBackground[2]; // +22E0
	float fWaterVariance[2]; // +22E8
	uint8_t _22F0[0x4];
	bool bWaterPlane; // +22F4
	uint8_t _22F5[0xF7];
	uint32_t nDefaultEAX; // +23EC
	uint8_t _23F0[0x340];
	FO2String sGFXSetPath; // +2730
	FO2String sTrackPath; // +274C
	FO2String sStagePath; // +2768
	uint8_t _2784[0x154];
	uint32_t nNumSplitpoints; // +28D8
	tSplitpoint aSplitpoints[32]; // +28DC
	uint8_t _30DC[0x804];
	tStartpoint aStartpoints[32]; // +38E0
	uint8_t _42E0[0x1540];
	uint32_t nNumStartpoints; // +5820
	uint8_t _5824[0x4];
	Minimap* pMinimap; // +5828
	void* pResetmap; // +582C
	tMaterial Checkpoint; // +5830
	tMaterial CheckpointOutline; // +58D0
	tMaterial PowerupMaterials[7]; // +5970
	void* pPowerupManager; // +5DD0
	uint8_t _5DD4[0xC];
};
static_assert(sizeof(Track) == 0x5DE0);

auto& pEnvironment = *(Track**)0x8465F0;

class TrackAI {
public:
	uint8_t _0[0x410];
	uint32_t nNumSplines; // +410
	uint8_t _414[0x54];
	Track* pTrack; // +468
};
auto& pTrackAI = *(TrackAI**)0x9298FA8;