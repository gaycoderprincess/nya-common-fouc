class PlayerScoreRace {
public:
	uint8_t _0[0x4];
	uint32_t nPlayerId; // 4
	uint32_t nPosition; // 8
	uint8_t _C[0x30];
	float fProgress; // 3C
	uint8_t _40[0x4];
	uint32_t nCurrentLap; // 44
	uint32_t nLapTimes[10];
};

class PlayerScoreDerby {
public:
	uint8_t _0[0x4];
	uint32_t nPlayerId; // 4
	uint8_t _8[0x31];
	uint8_t bKnockedOut; // 39 can be both wrecked or out of time, not set in dm derby
	uint8_t _3A[0x2];
	uint32_t nContactTimerCurrentTick; // 3C
	uint32_t nContactTimerLastHit; // 40
	uint8_t _44[0x10];
	uint32_t nScore1; // 54
	uint32_t nScore2; // 58
	uint8_t _5C[0x10];
	uint32_t nLives; // 6C
	uint8_t _70[0x14];
	float fScoreMultiplier;
};

class PlayerScoreTest {
public:
	uint8_t _0[0x4];
	uint32_t nPlayerId; // +4
	uint8_t _8[0x30];
	uint32_t nTopSpeed; // +38
};

class PlayerScoreBeatTheBomb {
public:
	uint8_t _0[0x4];
	uint32_t nPlayerId; // 4
	uint8_t _8[0x4C];
	float fScore; // 54
	uint8_t _58[0x4];
	int32_t nTimeLeft; // 5C
};

class PlayerScoreArcadeRace {
public:
	uint8_t _0[0x4];
	uint32_t nPlayerId; // +4
	uint32_t nPosition; // +8
	uint8_t _C[0x74];
	int32_t nTimeLeft; // 80
	uint8_t _84[0xC];
	float fScore; // 90
};

class ScoreManager {
public:
	uint8_t _0[0x4];
	uint32_t nNumLaps; // +4
	void** pScoresStart; // +8
	void** pScoresEnd; // +C
	uint8_t _10[0x34];
	uint32_t nSurvivorId; // +44
};
auto& pScoreManager = *(ScoreManager**)0x846514;

template<typename T>
T* GetPlayerScore(int playerId) {
	if (!pScoreManager) return nullptr;

	auto score = (T**)pScoreManager->pScoresStart;
	auto end = (T**)pScoreManager->pScoresEnd;
	while (score < end) {
		if ((*score)->nPlayerId + 1 == playerId) {
			return *score;
		}
		score++;
	}
	return nullptr;
}