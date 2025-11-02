class FO2String {
public:
	uint8_t _0[0x4];
	const char* string; // +4
	uint8_t _8[0xC];
	size_t length; // +14
	size_t maxLength; // +18

	const char* Get() {
		if (maxLength < 16) return (const char*)&string;
		return string;
	}
};
static_assert(sizeof(FO2String) == 0x1C);

class FO2WString {
public:
	uint8_t _0[0x4];
	const wchar_t* string; // +4
	uint8_t _8[0xC];
	size_t length; // +14
	size_t maxLength; // +18

	const wchar_t* Get() {
		if (maxLength < 8) return (const wchar_t*)&string;
		return string;
	}
};
static_assert(sizeof(FO2WString) == 0x1C);