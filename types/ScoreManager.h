class PlayerScore {
public:
	uint32_t nPlayerId; // +4
	int32_t nPosition; // +8
	uint8_t _C[0x2C];

	virtual void _vf0() = 0;
	virtual void _vf1() = 0;
	virtual void _vf2() = 0;
	virtual void _vf3() = 0;
	virtual void _vf4() = 0;
	virtual bool HasFinished() = 0; // 5
	virtual bool IsDNF() = 0; // 6
	virtual uint32_t GetFinishTime() = 0; // 7
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
};
static_assert(sizeof(PlayerScore) == 0x38);

class PlayerScoreRace : public PlayerScore {
public:
	bool bHasFinished; // +38
	bool bIsDNF; // +39
	uint8_t _3A[0x2];
	float fProgress; // +3C
	uint8_t _40[0x4];
	uint32_t nCurrentLap; // +44
	uint32_t nLapTimes[10]; // +48
	uint8_t _70[0x4];
	uint32_t nBestLapTime; // +74
	uint32_t nFinishTime; // +78
};

class PlayerScoreDerby : public PlayerScore {
public:
	uint8_t _38[0x1];
	uint8_t bKnockedOut; // +39 can be both wrecked or out of time, not set in dm derby
	uint8_t _3A[0x2];
	uint32_t nContactTimerCurrentTick; // +3C
	uint32_t nContactTimerLastHit; // +40
	uint8_t _44[0x10];
	uint32_t nScore1; // +54
	uint32_t nScore2; // +58
	uint8_t _5C[0x10];
	uint32_t nLives; // +6C
	uint8_t _70[0x14];
	float fScoreMultiplier; // +84
};

class PlayerScoreTest : public PlayerScore {
public:
	uint32_t nTopSpeed; // +38
};

class PlayerScoreBeatTheBomb : public PlayerScore {
public:
	uint8_t _38[0x1C];
	float fScore; // +54
	uint8_t _58[0x4];
	int32_t nTimeLeft; // +5C
};

class PlayerScoreArcadeRace : public PlayerScore {
public:
	uint8_t _38[0x48];
	int32_t nTimeLeft; // +80
	uint8_t _84[0xC];
	float fScore; // +90
};

class PlayerScoreStunt : public PlayerScore {
public:
	float fScore; // +38
};

class ScoreManager {
public:
	uint8_t _0[0x4];
	uint32_t nNumLaps; // +4
	FO2Vector<PlayerScoreRace*> aScores;
	uint8_t _14[0x30];
	uint32_t nSurvivorId; // +44
};
auto& pScoreManager = *(ScoreManager**)0x846514;

template<typename T>
T* GetPlayerScore(int playerId) {
	if (!pScoreManager) return nullptr;

	for (int i = 0; i < pScoreManager->aScores.GetSize(); i++) {
		auto score = pScoreManager->aScores[i];
		if (score->nPlayerId + 1 == playerId) {
			return (T*)score;
		}
	}
	return nullptr;
}