auto& pLoadingScreen = *(void**)0x929902C;

class HUDElement {
public:
	uint8_t _0[0xE8];
	bool bVisible;
};

auto AddHUDKeyword = (void(*)(const char*, void*, void*))0x4ECB20;
auto LoadHUDFromDB = (void*(__thiscall*)(void*, const char*, void*))0x4EB880;

// TODO: CreatePopup