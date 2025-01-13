class DevTexture {
public:
	uint8_t _0[0x14];
	void* pSomePtr; // +14
	uint8_t _18[0x4];
	FO2String sPath; // +1C
	uint8_t _38[0x14];
	PDIRECT3DTEXTURE9 pD3DTexture; // +4C
};

class DeviceD3d {
public:
	uint8_t _0[0x8];
	uint32_t nResolutionX; // +8
	uint32_t nResolutionY; // +C
	uint8_t _10[0x50];
	IDirect3DDevice9* pD3DDevice; // +60
	uint8_t _64[0x18];
	HWND hWnd; // +7C
	uint8_t _80[0x884];
	float fAspectX; // +904
	float fAspectY; // +908
};
auto& pDeviceD3d = *(DeviceD3d**)0x84665C;

auto& nGameResolutionX = *(int*)0x764A84;
auto& nGameResolutionY = *(int*)0x764A88;