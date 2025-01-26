enum eGameEvent {
	EVENT_RACE_BEGIN = 1002,
	EVENT_MENU_BEGIN = 1005,
	EVENT_QUIT_GAME = 1007,
	EVENT_START_RACE = 2011,
	EVENT_START_RACE_COUNTDOWN = 2013,
	EVENT_WAITING_FOR_HOST_PROMPT = 3007,
	EVENT_WAITING_FOR_PLAYERS_PROMPT = 3008,
	EVENT_START_RACE_PROMPT = 3009,
	EVENT_MUSIC_PLAY_TITLE = 4003,
	EVENT_MUSIC_PLAY_INGAME = 4004,
	EVENT_MUSIC_STOP = 4007,
	EVENT_SFX_TIME_TICK = 4030,
	EVENT_SFX_ARCADE_AWARD = 4033,
	EVENT_PLAYER_EJECT_WRECKED = 6009,
	EVENT_PLAYER_ON_OTHERPLAYER_WRECKED = 6023,
	EVENT_PLAYER_ON_SPLIT = 6026,
	EVENT_PLAYER_ON_LAP = 6027,
	EVENT_PLAYER_ON_ARCADE_CHECKPOINT = 6029,
	EVENT_PLAYER_ON_FINISH = 6031,
	EVENT_PLAYER_WRECKED = 6032,
	EVENT_PLAYER_DERBY_TIMEOUT = 6033,
	EVENT_PLAYER_RESPAWN = 6037,
	EVENT_PLAYER_RESPAWN_GHOST = 6040,
	EVENT_PLAYER_POWERUP_PICKUP = 6049,
	EVENT_PLAYER_WRECKED_2 = 6053,
	EVENT_PLAYER_UPDATE_FRAGDERBY_SCORE = 6060,
};

struct tEventData {
	int type;
	int data[8];

	tEventData(int type) {
		memset(this,0,sizeof(*this));
		this->type = type;
		this->data[2] = 0xFFFF;
	}

	tEventData(int type, int player) {
		memset(this,0,sizeof(*this));
		this->type = type;
		this->data[1] = player;
		this->data[2] = 0xFFFF;
	}
};


class EventManager {
public:
	// 4612C0
	static inline auto AddHandler = (void(__fastcall*)(int unk1, EventManager*, void(*pFunction)(tEventData*, void*), int unkFlags, void* funcParam2))0x4612C0;

	static inline uintptr_t PostEvent_call = 0x4611D0;
	float __attribute__((naked)) __fastcall PostEvent(tEventData* data) {
		__asm__ (
			"pushad\n\t"
			"mov eax, edx\n\t"
			"mov edx, ecx\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (PostEvent_call)
		);
	}

	static inline uintptr_t SendEvent_call = 0x461250;
	int __attribute__((naked)) __fastcall SendEvent(tEventData* data) {
		__asm__ (
			"pushad\n\t"
			"mov eax, edx\n\t"
			"push ecx\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (SendEvent_call)
		);
	}
};
auto& pEventManager = *(EventManager**)0x9298FB4;