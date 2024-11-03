// size 0x1C
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