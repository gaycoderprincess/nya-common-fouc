uintptr_t CheckFileIntegrity_call = 0x5DAF00;
void __attribute__((naked)) __fastcall CheckFileIntegrity(void* a1, const char* a2) {
	__asm__ (
		"push edx\n\t"
		"call %0\n\t"
		"add esp, 4\n\t"
		"ret\n\t"
			:
			: "m" (CheckFileIntegrity_call)
	);
}

class BFSManager {
public:

	static inline auto DoesFileExist = (bool(__stdcall*)(BFSManager*, const char*, int*))0x5B7170;
};
auto& pBFSManager = *(BFSManager**)0x846688;
auto DoesFileExist = (bool(__cdecl*)(const char*, char))0x5A5B80;

class FileCodec {
public:
	uint32_t _4[0];

	virtual void _vf0() = 0;
	virtual void _vf1() = 0;
	virtual void _vf2() = 0;
	virtual void _vf3() = 0;
	virtual void _vf4() = 0;
	virtual void _vf5() = 0;
	virtual void _vf6() = 0;
	virtual void _vf7() = 0;
	virtual size_t GetFileSize() = 0;
	virtual uint32_t GetFlags() = 0;
	virtual void _vf10() = 0;
	virtual void _vf11() = 0;
	virtual void _vf12() = 0;
	virtual void _vf13() = 0;
	virtual void _vf14() = 0;
	virtual void _vf15() = 0;
};

class File {
public:
	uint8_t _0[0x20];
	FileCodec* pFileCodec;

	static inline auto ReadBytes = (int(__thiscall*)(File*, void* out, int numBytes, int))0x5A5980;
};

uintptr_t SetTextureFolder_call = 0x5A6E20;
void __attribute__((naked)) __fastcall SetTextureFolder(const char* path) {
	__asm__ (
		"mov eax, ecx\n\t"
		"jmp %0\n\t"
			:
			: "m" (SetTextureFolder_call)
	);
}

uintptr_t SetSharedTextureFolder_call = 0x5A6E90;
void __attribute__((naked)) __fastcall SetSharedTextureFolder(const char* path) {
	__asm__ (
		"mov eax, ecx\n\t"
		"jmp %0\n\t"
			:
			: "m" (SetSharedTextureFolder_call)
	);
}

auto sTextureFolder = (const char*)0x845B78;
auto sSharedTextureFolder = (const char*)0x845C80;

auto ParseGameDDS = (bool(__thiscall*)(DevTexture* pThis, File* pFile, uint8_t* header))0x625AF0;

auto& pGameFilesChecksum1 = *(uint8_t**)0x825520; // uint8_t[20]
auto& pGameFilesChecksum2 = *(uint8_t**)0x82551C; // uint8_t[41]