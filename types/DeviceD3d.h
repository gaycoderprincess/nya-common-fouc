class DeviceD3d {
public:
	uint8_t _0[0x8];
	uint32_t nResolutionX; // +8
	uint32_t nResolutionY; // +C
	uint8_t _10[0x8F4];
	float fAspectX; // +904
	float fAspectY; // +908
};
auto& pDeviceD3d = *(DeviceD3d**)0x84665C;