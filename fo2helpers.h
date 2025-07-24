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

int GetCarDataID_slow(int dbId) {
	static int matchups[1024];
	static bool bOnce = true;
	if (bOnce) {
		for (auto& i : matchups) {
			i = -1;
		}
		bOnce = false;
	}

	if (matchups[dbId] != -1) return matchups[dbId];

	auto db = GetLiteDB();
	auto table = db->GetTable(std::format("FlatOut2.Cars.Car[{}]", dbId).c_str());
	auto str = (const char*)table->GetPropertyPointer("DataPath");
	matchups[dbId] = std::stoi(&str[14]);
	return matchups[dbId];
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

std::string GetTrackValueString(int id, const char* name) {
	if (!DoesTrackValueExist(id, name)) return nullptr;

	auto lua = pScriptHost->pLUAStruct->pLUAContext;
	auto oldtop = lua_gettop(lua);

	lua_getfield(lua, -10002, "Levels");
	lua_rawgeti(lua, lua_gettop(lua), id);

	auto oldtop2 = lua_gettop(lua);
	lua_setglobal(lua, name);
	lua_gettable(lua, oldtop2);
	std::string str;
	if (lua_type(lua, lua_gettop(lua)) == 3) { // int, translated language entry
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		str = converter.to_bytes(GetPhrase(luaL_checknumber(lua, lua_gettop(lua))));
	}
	else {
		str = (const char*)lua_tolstring(lua, lua_gettop(lua), 0);
	}

	lua_settop(lua, oldtop);

	return str;
}

std::string GetTrackName(int id) {
	return GetTrackValueString(id, "Name");
}

std::string GetTrackDescription(int id) {
	return GetTrackValueString(id, "Description");
}

int GetNumSkinsForCar(int dbCar) {
	auto path = "data/cars/car_" + std::to_string(GetCarDataPath(dbCar, false)) + "/skin";
	int i;
	for (i = 0; i < 255; i++) {
		auto file1 = (path + std::to_string(i+1) + ".dds");
		auto file2 = (path + std::to_string(i+1) + "_damaged.dds");
		auto file3 = (path + std::to_string(i+1) + "_damaged_normal.dds");
		auto file4 = (path + std::to_string(i+1) + "_normal.dds");
		auto file5 = (path + std::to_string(i+1) + "_specular.dds");
		if (!DoesFileExist(file1.c_str(), 0) || !DoesFileExist(file2.c_str(), 0) || !DoesFileExist(file3.c_str(), 0) || !DoesFileExist(file4.c_str(), 0) || !DoesFileExist(file5.c_str(), 0)) {
			break;
		}
	}
	return i;
}

tGameSetting* GetGameSettingByName(const std::string& name) {
	auto setting = aGameSettings;
	while (setting->name) {
		if (setting->name == name) {
			return setting;
		}
		setting++;
	}
	return nullptr;
}