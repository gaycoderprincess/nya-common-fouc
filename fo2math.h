uintptr_t FO2QuatToMatrix_call = 0x605AA0;
void __attribute__((naked)) __fastcall FO2QuatToMatrix(float* quaternion, float* matrix) {
	__asm__ (
		"pushad\n\t"
		"mov eax, edx\n\t"
		"call %0\n\t"
		"popad\n\t"
		"ret\n\t"
			:
			: "m" (FO2QuatToMatrix_call)
	);
}