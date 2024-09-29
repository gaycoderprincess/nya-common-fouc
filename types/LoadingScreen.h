class LoadingScreen {
public:

	static inline auto Create = (void(*)())0x46F8D0;
	static inline auto Free = (void(*)())0x46F920;
	static inline auto& nCopyrightTimer = *(int*)0x8465F4;

	static inline uintptr_t Draw_call = 0x5647E0;
	void __attribute__((naked)) __fastcall Draw() {
		__asm__ (
			"pushad\n\t"
			"mov esi, ecx\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (Draw_call)
		);
	}
};

auto& pLoadingScreen = *(LoadingScreen**)0x929902C;
