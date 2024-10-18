class Model {
public:
	uint8_t _0[0x8];
	NyaVec3 vBBoxMin; // +8
	NyaVec3 vBBoxMax; // +14
	NyaVec3 vRadius; // +20
	float fRadius; // +2C
};

class CompactMesh {
public:
	struct tSomeStruct {
		uint8_t _0[0x10];
		struct {
			Model* pModel;
			uint8_t _4[0x4];
		} aModels[0]; // +10
	};

	uint8_t _0[0x1C];
	tSomeStruct* pSomeStruct; // +1C
};

class DynamicObject {
public:
	uint8_t _0[0x2C];
	CompactMesh* pMesh; // +2C
	float mMatrix[4*4]; // +30
	uint8_t _70[0x80];
	float qQuaternion[4]; // +F0
	float vVelocity[3]; // +100
	uint8_t _10C[0x4];
	float vAngVelocity[3]; // +110
	uint8_t _11C[0x20];
	float fMass; // +13C

#ifdef NYA_MATH_H
	inline NyaMat4x4* GetMatrix() {
		return (NyaMat4x4*)mMatrix;
	}
	inline NyaVec3* GetVelocity() {
		return (NyaVec3*)vVelocity;
	}
	inline NyaVec3* GetAngVelocity() {
		return (NyaVec3*)vAngVelocity;
	}
#endif
};