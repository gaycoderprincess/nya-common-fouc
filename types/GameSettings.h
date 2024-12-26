struct tGameSetting {
	enum eValueType {
		VALUE_TYPE_INT,
		VALUE_TYPE_BOOL,
		VALUE_TYPE_FLOAT,
		VALUE_TYPE_STRING,
	};

	const char* category;
	const char* name;
	void* value;
	int type;
	float minValue;
	float maxValue;
};
auto& aGameSettings = *(tGameSetting**)0x45882C;

auto SetDefaultOptions = (void(*)())0x458A80;

auto& bImperialUnits = *(int*)0x849494;
auto& bIngameMap = *(int*)0x84949C;