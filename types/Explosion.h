enum eExplosionType {
	EXPLOSION_BLAST,
	EXPLOSION_BOMB
};

class ExplosionBloom {
public:
	float fRadius; // +0
	uint32_t nDurationMs; // +4
	uint8_t _8[0x8];
	float fBloomColor[4]; // +10
	float fBloomTolerance; // +20
	float fBloomScale; // +24
	float fDecayPower; // +28
	float fCameraShakeScale; // +2C

	static inline auto& bInitialized = *(bool*)0x929908C;
	static inline auto Initialize = (void(*)())0x4F3270;
};
static_assert(sizeof(ExplosionBloom) == 0x30);

auto gExplosionBloom = (ExplosionBloom*)0x84B230;