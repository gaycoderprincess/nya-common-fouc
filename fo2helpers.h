int GetNumCars() {
	return GetLiteDB()->GetTable("FlatOut2.Cars")->GetPropertyArraySize("Car");
}

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
	int count = GetNumCars();
	for (int i = 0; i < count; i++) {
		auto table = db->GetTable(std::format("FlatOut2.Cars.Car[{}]", i).c_str());
		auto str = (const char*)table->GetPropertyPointer("DataPath");
		if (str == std::format("data/Cars/Car_{}/", dataId)) {
			matchups[dataId] = i;
			return i;
		}
	}
	return -1;
}

std::string GetCarDataPath(int dbId) {
	auto db = GetLiteDB();
	auto table = db->GetTable(std::format("FlatOut2.Cars.Car[{}]", dbId).c_str());
	return (const char*)table->GetPropertyPointer("DataPath");
}

int GetCarByName(const std::string& name) {
	auto db = GetLiteDB();
	int count = GetNumCars();
	for (int i = 0; i < count; i++) {
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

bool DoesTrackExist(int id) {
	auto lua = pScriptHost->pLUAStruct->pLUAContext;
	auto oldtop = lua_gettop(lua);

	lua_getfield(lua, -10002, "Levels");
	lua_rawgeti(lua, lua_gettop(lua), id);
	auto value = lua_type(lua, lua_gettop(lua));
	lua_settop(lua, oldtop);
	return value;
}

int GetNumTracks() {
	int i = 0;
	while (DoesTrackExist(i+1)) {
		i++;
	}
	return i;
}

bool DoesTrackValueExist(int id, const char* name) {
	if (!DoesTrackExist(id)) return false;

	auto lua = pScriptHost->pLUAStruct->pLUAContext;
	auto oldtop = lua_gettop(lua);

	lua_getfield(lua, -10002, "Levels");
	lua_rawgeti(lua, lua_gettop(lua), id);

	auto oldtop2 = lua_gettop(lua);
	lua_setglobal(lua, name);
	lua_gettable(lua, oldtop2);
	auto value = lua_type(lua, lua_gettop(lua));
	lua_settop(lua, oldtop);
	return value;
}

float GetTrackValueNumber(int id, const char* name) {
	if (!DoesTrackValueExist(id, name)) return 0;

	auto lua = pScriptHost->pLUAStruct->pLUAContext;
	auto oldtop = lua_gettop(lua);

	lua_getfield(lua, -10002, "Levels");
	lua_rawgeti(lua, lua_gettop(lua), id);

	auto oldtop2 = lua_gettop(lua);
	lua_setglobal(lua, name);
	lua_gettable(lua, oldtop2);
	auto f = luaL_checknumber(lua, lua_gettop(lua));

	lua_settop(lua, oldtop);

	return f;
}

const char* GetTrackValueString(int id, const char* name) {
	if (!DoesTrackValueExist(id, name)) return nullptr;

	auto lua = pScriptHost->pLUAStruct->pLUAContext;
	auto oldtop = lua_gettop(lua);

	lua_getfield(lua, -10002, "Levels");
	lua_rawgeti(lua, lua_gettop(lua), id);

	auto oldtop2 = lua_gettop(lua);
	lua_setglobal(lua, name);
	lua_gettable(lua, oldtop2);
	auto str = (const char*)lua_tolstring(lua, lua_gettop(lua), 0);

	lua_settop(lua, oldtop);

	return str;
}

const char* GetTrackName(int id) {
	return GetTrackValueString(id, "Name");
}