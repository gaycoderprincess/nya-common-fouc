class HUDElement {
public:
	uint8_t _0[0xE8];
	bool bVisible;
};

auto gPalette = (uint32_t*)0x9298B70;

auto AddHUDKeyword = (void(*)(const char*, int(__cdecl*)(wchar_t*, size_t, void*, void*), void*))0x4ECB20;
auto LoadHUDFromDB = (void*(__thiscall*)(void*, const char*, void*))0x4EB880;

// TODO: CreatePopup