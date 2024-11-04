class MenuScene {
public:
	uint8_t _0[0x2C];
	Camera* pCamera; // +2C
};

class MenuInterface {
public:
	uint8_t _0[0xD0];
	MenuScene Scene;
};