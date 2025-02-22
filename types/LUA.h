class ScriptHost {
public:
	struct tLUAStruct {
		const char* unkString; // "unnamed"
		void* pLUAContext; // +4
	};

	uint8_t _0[0x10];
	tLUAStruct* pLUAStruct;
};
auto& pScriptHost = *(ScriptHost**)0x9298FB8;

auto luaL_checktype = (void(*)(void*, int, int))0x634C70;
auto luaL_checkudata = (void*(*)(void*, int, const char*))0x634BB0;
auto luaL_typerror = (void(*)(void*, int, const char*))0x634900;
auto lua_pushnumber = (int(*)(void*, float))0x633550;
auto lua_tolstring = (const wchar_t*(*)(void*, int, void*))0x6332B0;
auto lua_toboolean = (bool(*)(void*, int))0x633260;
auto luaL_checknumber = (float(*)(void*, int))0x634DD0;
auto lua_setfield = (void(*)(void*, int, const char*))0x633D20;
auto lua_pushcfunction = (void(*)(void*, void*, int))0x633750;
auto lua_pushboolean = (int(*)(void*, int))0x633870;
auto lua_pushlstring = (int(*)(void*, const wchar_t*, size_t))0x6335D0;
auto lua_pushnil = (int(*)(void*))0x633520;
auto lua_settable = (int(*)(void*, int))0x633CD0;
auto lua_setglobal = (int(*)(void*, const char*))0x633640;
auto lua_gettable = (void(*)(void*, int))0x633940;
auto lua_getfield = (void(*)(void*, int, const char*))0x633980;
auto lua_rawgeti = (void(*)(void*, int, int))0x633A80;
auto lua_gettop = (int(*)(void*))0x632B10;
auto lua_settop = (void(*)(void*, int))0x632B30;
auto lua_type = (int(*)(void*, int))0x632F20;
auto lua_dofile = (int(__thiscall*)(void*, const char*, int))0x5DBE80;