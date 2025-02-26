#include <codecvt>

class Font {
public:
	uint8_t _0[0xC];
	NyaDrawing::CNyaRGBA32 nColor; // +C
	uint8_t _10[0x2C];
	struct
	{
		bool bXCenterAlign : 1;
		bool bXRightAlign : 1;
	}; // +3C
	uint8_t _40[0x14];
	float fScaleX; // +54
	float fScaleY; // +58

	static inline auto GetFont = (Font*(__stdcall*)(void*, const char*))0x457D00;
	static inline auto Display = (void(*)(Font*, float, float, const wchar_t*, ...))0x5A8BE0;

private:
	static inline float drawWidthOutX = 0.0;
	static inline float drawWidthOutY = 0.0;
	static inline uintptr_t GetDrawWidth_call = 0x5A9A60;
	static void __attribute__((naked)) __fastcall GetDrawWidth_bad(const wchar_t* text, Font* font) {
		__asm__ (
			"pushad\n\t"
			// text = ecx
			"lea edi, %1\n\t" // draw width out X from param2 to esi
			"mov esi, edx\n\t" // font from param2 to esi
			"lea eax, %2\n\t" // draw width Y
			"push 0\n\t" // a6
			"push 0\n\t" // a5
			"push eax\n\t" // push Y
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (GetDrawWidth_call), "m" (drawWidthOutX), "m" (drawWidthOutY)
		);
	}

public:
	static float GetWidth(Font* font, const wchar_t* text) {
		GetDrawWidth_bad(text, font);
		return drawWidthOutX;
	}
};

struct tFontBak {
	NyaDrawing::CNyaRGBA32 nColor;
	bool bXCenterAlign : 1;
	bool bXRightAlign : 1;
	float fScaleX;
	float fScaleY;
};

void DrawStringFO2(tNyaStringData data, const wchar_t* string, const char* font) {
	auto pFont = Font::GetFont(*(void**)(0x9298FD8), font);

	tFontBak bak;
	bak.fScaleX = pFont->fScaleX;
	bak.fScaleY = pFont->fScaleY;
	bak.nColor = pFont->nColor;
	bak.bXCenterAlign = pFont->bXCenterAlign;
	bak.bXRightAlign = pFont->bXRightAlign;

	pFont->fScaleX = data.size * nResX / 20.0;
	pFont->fScaleY = data.size * nResY / 20.0;
	pFont->bXRightAlign = data.XRightAlign;
	pFont->bXCenterAlign = data.XCenterAlign;
	pFont->nColor.r = data.b;
	pFont->nColor.g = data.g;
	pFont->nColor.b = data.r;
	pFont->nColor.a = data.a;
	pFont->fScaleX *= GetAspectRatioInv();
	if (data.YCenterAlign) {
		data.y -= data.size * 0.5;
	}
	Font::Display(pFont, data.x * nResX, data.y * nResY, string);

	pFont->fScaleX = bak.fScaleX;
	pFont->fScaleY = bak.fScaleY;
	pFont->nColor = bak.nColor;
	pFont->bXCenterAlign = bak.bXCenterAlign;
	pFont->bXRightAlign = bak.bXRightAlign;
}

float GetStringWidthFO2(tNyaStringData data, const wchar_t* string, const char* font) {
	auto pFont = Font::GetFont(*(void**)(0x9298FD8), font);

	tFontBak bak;
	bak.fScaleX = pFont->fScaleX;
	bak.fScaleY = pFont->fScaleY;
	bak.nColor = pFont->nColor;
	bak.bXCenterAlign = pFont->bXCenterAlign;
	bak.bXRightAlign = pFont->bXRightAlign;

	pFont->fScaleX = data.size * nResX / 20.0;
	pFont->fScaleY = data.size * nResY / 20.0;
	pFont->bXRightAlign = data.XRightAlign;
	pFont->bXCenterAlign = data.XCenterAlign;
	pFont->nColor.r = data.b;
	pFont->nColor.g = data.g;
	pFont->nColor.b = data.r;
	pFont->nColor.a = data.a;
	pFont->fScaleX *= GetAspectRatioInv();
	if (data.YCenterAlign) {
		data.y -= data.size * 0.5;
	}
	auto w = Font::GetWidth(pFont, string);

	pFont->fScaleX = bak.fScaleX;
	pFont->fScaleY = bak.fScaleY;
	pFont->nColor = bak.nColor;
	pFont->bXCenterAlign = bak.bXCenterAlign;
	pFont->bXRightAlign = bak.bXRightAlign;

	w /= (double)nResX;
	return w;
}

void DrawStringFO2(const tNyaStringData& data, const std::string& name) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	DrawStringFO2(data, converter.from_bytes(name).c_str(), "FontLarge");
}

float GetStringWidthFO2(const tNyaStringData& data, const std::string& name) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return GetStringWidthFO2(data, converter.from_bytes(name).c_str(), "FontLarge");
}