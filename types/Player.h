class Player {
public:
	uint8_t _4[0x220];
	uint32_t nArrowColor; // +224
	uint32_t nArrowColorId; // +228
	uint8_t _22C[0x68];
	Car* pCar; // +294
	uint32_t nCarId; // +298
	uint32_t nCarSkinId; // +29C
	uint8_t _2A0[0x4];
	uint32_t nCharacterTypeId; // +2A4
	uint32_t nCharacterSkinId; // +2A8
	uint8_t _2AC[0x18];
	uint32_t nPlayerId; // +2C4
	uint32_t nPlayerType; // +2C8
	uint32_t nPlayerStartPosition; // +2CC
	uint8_t _2D0[0x8];
	uint32_t nIsWrecked; // +2D8
	uint8_t _2DC[0x30];
	int32_t nRaceTime; // +30C
	uint8_t _310[0x130];
	uint32_t nGhosting; // +440
	uint8_t _444[0x78];
	uint32_t nTimeInAir; // +4BC
	uint8_t _4C0[0x3E0];
	uint32_t nSteeringKeyboardLeft; // +8A0
	uint32_t nSteeringKeyboardRight; // +8A4
	uint8_t _8A8[0x14];
	uint32_t nIsUsingKeyboard; // +8BC
	uint8_t _8C0[0x8];
	float fSteeringController; // +8C8
	float fOutputSteerAngle; // +8CC
	float fGasPedal; // +8D0
	float fBrakePedal; // +8D4
	uint8_t _8D8[0xC];
	uint32_t nSomeFlags; // +8E4
	uint8_t _8E8[0x18];
	float fTimeInAirForBonus; // +900
	uint8_t _904[0x68];
	uint32_t nAICarNum; // +96C
	uint8_t _970[0x6C];
	float fLookAheadMin; // +9DC
	float fLookAheadMax; // +9E0
	float fLookAheadModifier; // +9E4
	uint8_t _9E8[0x68];
	int nAIId; // +A50
	int nAIClassId; // +A54

	static inline uintptr_t DrawJoinedGameNotification_call = 0x4E1B00;
	void __attribute__((naked)) __fastcall DrawJoinedGameNotification(const wchar_t* string) {
		__asm__ (
			"pushad\n\t"
			"mov esi, [ecx+0x22C]\n\t"
			"mov eax, [ecx+0x30C]\n\t"
			"push edx\n\t"
			"push eax\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (DrawJoinedGameNotification_call)
		);
	}

	static inline uintptr_t DrawLeftGameNotification_call = 0x4E1B90;
	void __attribute__((naked)) __fastcall DrawLeftGameNotification(const wchar_t* string) {
		__asm__ (
			"pushad\n\t"
			"mov esi, [ecx+0x22C]\n\t"
			"mov eax, [ecx+0x30C]\n\t"
			"push edx\n\t"
			"push eax\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (DrawLeftGameNotification_call)
		);
	}

	virtual void _vf0() = 0;
	virtual void _vf1() = 0;
	virtual void _vf2() = 0;
	virtual void _vf3() = 0;
	virtual void _vf4() = 0;
	virtual void _vf5() = 0;
	virtual void _vf6() = 0;
	virtual void _vf7() = 0;
	virtual void _vf8() = 0;
	virtual void _vf9() = 0;
	virtual void _vf10() = 0;
	virtual void _vf11() = 0;
	virtual void _vf12() = 0;
	virtual void _vf13() = 0;
	virtual void _vf14() = 0;
	virtual void _vf15() = 0;
	virtual void _vf16() = 0;
	virtual void _vf17() = 0;
	virtual void TriggerEvent(tEventData* properties) = 0;
};

class PlayerInfo {
public:
	wchar_t sPlayerName[16]; // +0
	int nCar; // +20
	int nCarSkin; // +24
	int nCarUpgrades; // +28
	int nType; // +2C
	int nController; // +30
	int nCharType; // +34
	int nPeerId; // +38
	int nNetworkId; // +3C
	uint8_t _40[0x10]; // +40
};
static_assert(sizeof(PlayerInfo) == 0x50);

Player* GetPlayer(int id) {
	auto host = pGameFlow->pHost;
	if (!host) return nullptr;
	auto players = host->aPlayers;
	if (!players) return nullptr;
	if (id > host->GetNumPlayers()) return nullptr;
	auto ply = players[id];
	if (!ply || !ply->pCar) return nullptr;
	return ply;
}