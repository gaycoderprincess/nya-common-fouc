class CarUnlockState {
public:
	uint32_t bIsLocked;
	uint32_t bIsPurchased;
	uint8_t _8[0x18];
};
static_assert(sizeof(CarUnlockState) == 0x20);

class Garage {
public:
	uint8_t _0[0x5C];
	CarUnlockState* aCarUnlocks;
};