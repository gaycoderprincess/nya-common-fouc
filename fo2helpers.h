int GetCarDBID(int dataId) {
	static int matchups[1024];
	static bool bOnce = true;
	if (bOnce) {
		for (auto& i : matchups) {
			i = -1;
		}
		bOnce = false;
	}

	if (matchups[dataId] != -1) return matchups[dataId];

	auto db = GetLiteDB();
	for (int i = 0; i < 255; i++) {
		auto table = db->GetTable(std::format("FlatOut2.Cars.Car[{}]", i).c_str());
		auto str = (const char*)table->GetPropertyPointer("DataPath");
		if (str == std::format("data/Cars/Car_{}/", dataId)) {
			matchups[dataId] = i;
			return i;
		}
	}
	return -1;
}

int GetCarByName(const std::string& name) {
	auto db = GetLiteDB();
	for (int i = 0; i < 255; i++) {
		auto table = db->GetTable(std::format("FlatOut2.Cars.Car[{}]", i).c_str());
		auto str = (const char*)table->GetPropertyPointer("Name");
		if (str == name) {
			return i;
		}
	}
	return -1;
}

const char* GetCarName(int id) {
	auto table = GetLiteDB()->GetTable(std::format("FlatOut2.Cars.Car[{}]", id).c_str());
	return (const char*)table->GetPropertyPointer("Name");
}

const char* GetTrackName(int id) {
	auto lua = pScriptHost->pLUAStruct->pLUAContext;
	auto oldtop = lua_gettop(lua);

	lua_getfield(lua, -10002, "Levels");
	lua_rawgeti(lua, lua_gettop(lua), id);

	auto oldtop2 = lua_gettop(lua);
	lua_setglobal(lua, "Name");
	lua_gettable(lua, oldtop2);
	auto name = (const char*)lua_tolstring(lua, lua_gettop(lua), 0);

	lua_settop(lua, oldtop);

	return name;
}