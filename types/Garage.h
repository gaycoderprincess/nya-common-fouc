class GarageCar {
public:
	enum eUpgrade {
		BODY_LW = 0,
		BODY_MODIFIED = 1,
		BODY_RACING = 2,
		BODY_PRO = 3,
		CHASSIS_MODIFIED = 4,
		CHASSIS_RACING = 5,
		CHASSIS_PRO = 6,
		ROLLCAGE = 7,
		CHIP_DIS = 8,
		ENGINE_BALANCING_KIT = 9,
		FUEL_FILTER_KIT = 10,
		NITRO_KIT_1 = 11,
		NITRO_KIT_2 = 12,
		NITRO_KIT_3 = 13,
		TUNING_MODIFIED = 14,
		TUNING_RACING = 15,
		TUNING_PRO = 16,
		TURBO_KIT_MODIFIED = 17,
		TURBO_KIT_RACING = 18,
		TURBO_KIT_PRO = 19,
		EXHAUST_MODIFIED = 20,
		EXHAUST_RACING = 21,
		EXHAUST_PRO = 22,
		MANIFOLD_MODIFIED = 23,
		MANIFOLD_RACING = 24,
		MANIFOLD_PRO = 25,
		GEARBOX_MODIFIED = 26,
		GEARBOX_RACING = 27,
		GEARBOX_PRO = 28,
		CLUTCH_FLYWHEEL = 29,
		SUSPENSION_MODIFIED = 30,
		SUSPENSION_RACING = 31,
		SUSPENSION_PRO = 32,
		STEERING_MODIFIED = 33,
		STEERING_RACING = 34,
		STEERING_PRO = 35,
		ANTI_ROLL_BARS_MODIFIED = 36,
		ANTI_ROLL_BARS_RACING = 37,
		ANTI_ROLL_BARS_PRO = 38,
		TIRES_MODIFIED = 39,
		TIRES_RACING = 40,
		TIRES_PRO = 41,
		BRAKES_MODIFIED = 42,
		BRAKES_RACING = 43,
		BRAKES_PRO = 44,
	};

	uint32_t bIsLocked; // +0
	uint32_t bIsPurchased; // +4
	uint8_t nSkinId; // +8
	uint8_t nUpgrades[19]; // +9
	uint32_t nUpgradesValue; // +1C

	bool IsUpgradePurchased(int upgrade) {
		uint32_t bit = 1 << (upgrade % 8);
		return (nUpgrades[upgrade / 8] & bit) != 0;
	}
	void SetUpgradePurchased(int upgrade, bool purchased) {
		uint32_t bit = 1 << (upgrade % 8);
		if (purchased) {
			nUpgrades[upgrade / 8] |= bit;
		}
		else {
			nUpgrades[upgrade / 8] &= ~bit;
		}
	}
};
static_assert(sizeof(GarageCar) == 0x20);

class Garage {
public:
	uint8_t _0[0x5C];
	GarageCar* aCars; // +5C
	uint8_t _60[0x4];
};
static_assert(sizeof(Garage) == 0x64);