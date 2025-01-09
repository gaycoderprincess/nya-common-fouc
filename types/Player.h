struct tEventData;

class Player {
public:
	uint8_t _4[0x220];
	uint32_t nArrowColor; // +224
	uint32_t nArrowColorId; // +228
	uint8_t _22C[0x58];
	Controller* pController; // +284
	uint8_t _288[0xC];
	Car* pCar; // +294
	uint32_t nCarId; // +298
	uint32_t nCarSkinId; // +29C
	uint8_t _2A0[0x4];
	uint32_t nCharacterTypeId; // +2A4
	uint32_t nCharacterSkinId; // +2A8
	uint8_t _2AC[0x18];
	uint32_t nPlayerId; // +2C4
	uint32_t nPlayerType; // +2C8
	uint32_t nStartPosition; // +2CC
	uint8_t _2D0[0x8];
	uint32_t nIsWrecked; // +2D8
	uint8_t _2DC[0x30];
	int32_t nRaceTime; // +30C
	uint8_t _310[0x4];
	uint32_t nFrameTime; // +314
	uint8_t _318[0xCC];
	uint32_t nCurrentSplit; // +3E4
	uint32_t nCurrentLap; // +3E8
	uint8_t _3EC[0x54];
	uint32_t nGhosting; // +440
	uint8_t _444[0x10];
	uint32_t nWrongWayGhost; // +454
	uint8_t _458[0x64];
	uint32_t nTimeInAir; // +4BC
	uint8_t _4C0[0x3AC];
	uint32_t nNitroRegen; // +86C
	uint8_t _870[0xC];
	uint32_t nIsPowerupEnabled; // +87C
	uint32_t nPowerupType; // +880
	uint32_t nPowerupTime; // +884
	uint8_t _888[0x18];
	uint32_t nSteeringKeyboardLeft; // +8A0
	uint32_t nSteeringKeyboardRight; // +8A4
	uint8_t _8A8[0x14];
	uint32_t nIsUsingKeyboard; // +8BC
	uint8_t _8C0[0x8];
	float fSteeringController; // +8C8
	float fOutputSteerAngle; // +8CC
	float fGasPedal; // +8D0
	float fBrakePedal; // +8D4
	float fHandbrake; // +8D8
	float fNitroButton; // +8DC
	uint8_t _8E0[0x4];
	uint32_t nSomeFlags; // +8E4
	uint8_t _8E8[0x18];
	float fTimeInAirForBonus; // +900
	uint8_t _904[0x38];
	// size 0x93C

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

	static inline auto GetBumpMass = (void(__thiscall*)(Player*))0x47DFA0;

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

class AIPlayer : public Player {
public:
	struct tAIProfile {
		int nCarNum; // +96C
		int nSkin; // +970
		int nCharacterType; // +974
		int nCharacterSkinId; // +978
		float fCatchUpMul; // +97C
		float fHandicapMul; // +980
		float fMagnetSpeedLimit; // +984
		float fMagnetDistanceLimitAhead; // +988
		float fMagnetDistanceLimitBehind; // +98C
		float fMagnetSpeedRatio; // +990
		float fRLMagnetSpeedLimit; // +994
		float fRLMagnetMul; // +998
		float fAggression; // +99C
		float fBumpAggression; // +9A0
		float fBlockAggression; // +9A4
		float fOvertakeAggression; // +9A8
		float fThrottleLimit; // +9AC
		float fHandicapRacing; // +9B0
		float fHandicapOffTrack; // +9B4
		float fHandicapAirborne; // +9B8
		float fCatchUpRacing; // +9BC
		float fCatchUpOffTrack; // +9C0
		float fCatchUpAirborne; // +9C4
		float fNitroUsage; // +9C8
		int nNitroScan; // +9CC
		float fAvoidance; // +9D0
		float fDamageReaction; // +9D4
		float fDamageRecovery; // +9D8
		float fLookAheadMin; // +9DC
		float fLookAheadMax; // +9E0
		float fLookAheadModifier; // +9E4
		float fUseAltRoute; // +9E8
		float fUnderSteerRange; // +9EC
		float fOverSteerRange; // +9F0
		float fSpinOutRange; // +9F4
		float fNeutralSlide; // +9F8
		float fNeutralBrakeTime; // +9FC
		float fMinBrakeTime; // +A00
		float fMaxBrakeTime; // +A04
		float fSlideFrictionScale; // +A08
		float fBrakeFrictionScale; // +A0C
		float fFrictionAdjust; // +A10
		float fHandicapAhead; // +A14
		float fHandicapBehind; // +A18
		float fCoefP; // +A1C
		float fCoefI; // +A20
		float fCoefD; // +A24
		float fDerbyFavourCenter; // +A28
		float fDerbyTargetPlayer; // +A2C
		float fDerbyExitCruiseSpeed; // +A30
		float fDefaultTurbo; // +A34
		float fPackCoeff; // +A38
		float fTimeCoeff; // +A3C
		float fSteeringMul; // +A40
		float fPowerUpDirMin; // +A44
		float fPowerUpDistMax; // +A48 gets squared after it's read from db
		float fBumpMassDriver; // +A4C
	};
	static_assert(sizeof(tAIProfile) == 0xA50-0x96C);

	uint8_t _93C[0x30];
	tAIProfile AIProfile; // +96C
	uint32_t nAIId; // +A50
	uint32_t nAIClassId; // +A54
	uint8_t _A58[0x4];
	uint32_t nIsDerbyAI; // +A5C
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