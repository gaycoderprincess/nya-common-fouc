// this enum is based off of chloe collection! all tracks are offset as empty slots have been removed
enum eTrack {
	TRACK_FOREST1A			= 1,
	TRACK_FOREST1B			= 2,
	TRACK_FOREST1C			= 3,
	TRACK_FOREST2A			= 4,
	TRACK_FOREST2B			= 5,
	TRACK_FOREST2C			= 6,
	TRACK_CITY1A			= 7,
	TRACK_CITY1B			= 8,
	TRACK_CITY1C			= 9,
	TRACK_CITY2A			= 10,
	TRACK_CITY2B			= 11,
	TRACK_CITY2C			= 12,
	TRACK_CANAL1A			= 13,
	TRACK_CANAL1B			= 14,
	TRACK_CANAL1C			= 15,
	TRACK_DESERT1A			= 16,
	TRACK_DESERT1B			= 17,
	TRACK_DESERT1C			= 18,
	TRACK_FIELDS1A			= 19,
	TRACK_FIELDS1B			= 20,
	TRACK_FIELDS1C			= 21,
	TRACK_FIELDS2A			= 22,
	TRACK_FIELDS2B			= 23,
	TRACK_FIELDS2C			= 24,
	TRACK_RACING1A			= 25,
	TRACK_RACING1B			= 26,
	TRACK_RACING1C			= 27,
	TRACK_RACING2A			= 28,
	TRACK_RACING2B			= 29,
	TRACK_RACING2C			= 30,
	TRACK_DERBY1A			= 31,
	TRACK_DERBY2A			= 32,
	TRACK_DERBY3A			= 33,
	TRACK_DERBY4A			= 34,
	TRACK_DERBY5A			= 35,
	TRACK_DERBY6A			= 36,
	TRACK_ARENA1			= 37,
	TRACK_ARENA2			= 38,
	TRACK_ARENA3			= 39,
	TRACK_ARENA4			= 40,
	TRACK_ARENA5			= 41,
	TRACK_ARENA6			= 42,
	TRACK_NASCAR1A			= 43,
	TRACK_NASCAR1B			= 44,
	TRACK_NASCAR1C			= 45,
	TRACK_GARAGETESTTRACK	= 46,
	TRACK_HIGHJUMP			= 47,
	TRACK_BOWLING			= 48,
	TRACK_SKIJUMP			= 49,
	TRACK_CURLING			= 50,
	TRACK_STONESKIPPING 	= 51,
	TRACK_RINGOFFIRE		= 52,
	TRACK_FIELDGOAL			= 53,
	TRACK_ROYALFLUSH		= 54,
	TRACK_BASKETBALL		= 55,
	TRACK_DARTS				= 56,
	TRACK_BASEBALL			= 57,
	TRACK_SOCCER			= 58,

	// fo1
	TRACK_TOWN2A			= 59,
	TRACK_TOWN2B			= 60,
	TRACK_TOWN2C			= 61,
	TRACK_PIT1A				= 62,
	TRACK_PIT1B				= 63,
	TRACK_PIT1C				= 64,
	TRACK_PIT2A				= 65,
	TRACK_PIT2B				= 66,
	TRACK_PIT2C				= 67,
	TRACK_PIT3A				= 68,
	TRACK_PIT3B				= 69,
	TRACK_PIT3C				= 70,
	TRACK_TOWN3A			= 71,
	TRACK_TOWN3B			= 72,
	TRACK_TOWN3C			= 73,
	TRACK_FO1FOREST1A		= 74,
	TRACK_FO1FOREST1B		= 75,
	TRACK_FO1FOREST1C		= 76,
	TRACK_FO1FOREST2A		= 77,
	TRACK_FO1FOREST2B		= 78,
	TRACK_FO1FOREST2C		= 79,
	TRACK_FO1FOREST3A		= 80,
	TRACK_FO1FOREST3B		= 81,
	TRACK_FO1FOREST3C		= 82,
	TRACK_WINTER1A			= 83,
	TRACK_WINTER1B			= 84,
	TRACK_WINTER1C			= 85,
	TRACK_WINTER2A			= 86,
	TRACK_WINTER2B			= 87,
	TRACK_WINTER2C			= 88,
	TRACK_FO1RACING1A		= 89,
	TRACK_FO1RACING1B		= 90,
	TRACK_FO1RACING1C		= 91,
	TRACK_FO1RACING2A		= 92,
	TRACK_FO1RACING2B		= 93,
	TRACK_FO1RACING2C		= 94,

	// retro demo
	TRACK_RETRODEMO1A		= 95,
	TRACK_RETRODEMO1B		= 96,
	TRACK_RETRODEMO2A		= 97,
	TRACK_RETRODEMO2B		= 98,

	// tough trucks
	TRACK_TOUGHTRUCKS1		= 99,
	TRACK_TOUGHTRUCKS2		= 100,
	TRACK_TOUGHTRUCKS3		= 101,
	TRACK_TOUGHTRUCKS4		= 102,
	TRACK_TOUGHTRUCKS5		= 103,
	TRACK_TOUGHTRUCKS6		= 104,
	TRACK_TOUGHTRUCKS7		= 105,
	TRACK_TOUGHTRUCKS8		= 106,
	TRACK_TOUGHTRUCKS9		= 107,
	TRACK_TOUGHTRUCKS10		= 108,
	TRACK_TOUGHTRUCKS11		= 109,
	TRACK_TOUGHTRUCKS12		= 110,
	TRACK_TOUGHTRUCKS13		= 111,
	TRACK_TOUGHTRUCKS14		= 112,
	TRACK_TOUGHTRUCKS15		= 113,
	TRACK_TOUGHTRUCKS16		= 114,

	// rally trophy
	TRACK_RALLY1A			= 115,
	TRACK_RALLY2A			= 116,
	TRACK_RALLY3A			= 117,
	TRACK_RALLY3B			= 118,
	TRACK_RALLY3C			= 119,
	TRACK_RALLY3D			= 120,
	TRACK_RALLY3E			= 121,
	TRACK_RALLY3F			= 122,
	TRACK_RALLY4A			= 123,
	TRACK_RALLY4B			= 124,
	TRACK_RALLY5A			= 125,

	// rally trophy arcade
	TRACK_RALLY1I			= 126,
	TRACK_RALLY2G			= 127,
	TRACK_RALLY3G			= 128,
	TRACK_RALLY3H			= 129,
	TRACK_RALLY4G			= 130,
	TRACK_RALLY5G			= 131,
};

// this enum is based off of chloe collection! truck, bonecracker and grinder are offset
enum eCar {
	// derby
	CAR_CHILI			= 0,
	CAR_MALICE			= 1,
	CAR_ROAMER			= 2,
	CAR_SHAKER			= 3,
	CAR_BLASTERXL		= 4,
	CAR_BANGER			= 5,
	CAR_SPLITTER		= 6,
	CAR_SWITCHBLADE		= 7,
	CAR_VENOM			= 8,
	CAR_BONECRACKER		= 49,
	CAR_GRINDER			= 50,

	// race
	CAR_CTR				= 9,
	CAR_BOXER			= 10,
	CAR_MADRASH			= 11,
	CAR_NEVADA			= 12,
	CAR_LANCEA			= 13,
	CAR_FORTUNE			= 14,
	CAR_DAYTANA			= 15,
	CAR_BULLET			= 16,
	CAR_LENTUS			= 17,
	CAR_VENTURA			= 18,
	CAR_INSETTA			= 19,

	// street
	CAR_CHILIPEPPER		= 20,
	CAR_SCORPION		= 21,
	CAR_INSETTASPORT	= 22,
	CAR_SPARROWHAWK		= 23,
	CAR_CRUSADER		= 24,
	CAR_CTRSPORT		= 25,
	CAR_VEXTERXS		= 26,
	CAR_SPEEDSHIFTER	= 27,
	CAR_CANYON			= 28,
	CAR_TERRATOR		= 29,
	CAR_SUNRAY			= 30,
	CAR_SPEEDEVIL		= 31,
	CAR_ROADKING		= 32,
	CAR_BULLETGT		= 33,

	// stunt
	CAR_STARFLIGHT		= 34,
	CAR_TRAILBLAZER		= 35,
	CAR_AFTERBURNER		= 36,
	CAR_ROCKET			= 37,
	CAR_NUCLEON			= 38,

	// bonus
	CAR_PIMPSTER		= 39,
	CAR_FLATMOBILE		= 40,
	CAR_MOBCAR			= 41,
	CAR_SCHOOLBUS		= 42,
	CAR_STARFLIGHTSS	= 43,
	CAR_TRAILBLAZERSS	= 44,
	CAR_AFTERBURNERSS	= 45,
	CAR_ROCKETSS		= 46,
	CAR_NUCLEONSS		= 47,
	CAR_TRUCK			= 48,
};

enum eGameMode {
	GM_NONE = 0,
	GM_CAREER = 1,
	GM_SINGLE_RACE = 2,
	GM_INSTANT_ACTION = 3,
	GM_CRASHTEST_DUMMY = 4,
	GM_ONLINE_MULTIPLAYER = 5,
	GM_PARTY = 6,
	GM_DEVELOPER = 7,
	GM_TOURNAMENT = 8,
	GM_SPLITSCREEN = 9,
	GM_TEST = 10,
	GM_ARCADE_CAREER = 11,
};

enum eGameRules {
	GR_DEFAULT = 0,
	GR_RACE = 1,
	GR_STUNT = 2,
	GR_DERBY = 3,
	GR_HUNTER_PREY = 4,
	GR_ARCADE_ADVENTURE = 5,
	GR_PONGRACE = 6,
	GR_TIMEATTACK = 7,
	GR_BEAT_THE_BOMB = 8,
	GR_ARCADE_RACE = 9,
	GR_TIME_TRIAL = 10,
	GR_TEST = 11,

	// chloe collection gamerules
	GR_TONYHAWK = 12,
	GR_SPEEDTRAP = 13,
	GR_DRIFT = 14,
	GR_LAPKNOCKOUT = 15,
};

enum eStuntType {
	STUNT_NONE = 0,
	STUNT_CURLING = 1,
	STUNT_BULLSEYE = 2,
	STUNT_HIGHJUMP = 3,
	STUNT_STONESKIPPING = 4,
	STUNT_RINGOFFIRE = 5,
	STUNT_DARTS = 6,
	STUNT_BREAKDOWN = 7,
	STUNT_BLACKDANNY = 8,
	STUNT_SKIJUMP = 9,
	STUNT_FIELDGOAL = 10,
	STUNT_BOWLING = 11,
	STUNT_BASKETBALL = 12,
	STUNT_BASEBALL = 13,
	STUNT_SOCCER = 14,
};

enum eCareerClass {
	CLASS_NONE = 0,
	CLASS_C = 1,
	CLASS_B = 2,
	CLASS_A = 3,
	CLASS_FINALS = 4,
	CLASS_EXTRA = 5,
};

enum eDerbyType {
	DERBY_NONE = 0,
	DERBY_LMS = 1,
	DERBY_WRECKING = 2,
	DERBY_FRAG = 3,
};

enum eUpgradeLevel {
	UPGRADE_DEFAULT = 0,
	UPGRADE_NONE = 1,
	UPGRADE_50 = 2,
	UPGRADE_100 = 3,
};

enum eNitroRegen {
	NITROREGEN_DEFAULT = 0,
	NITROREGEN_ON = 1,
	NITROREGEN_OFF = 2,
};

enum ePlayerType {
	PLAYERTYPE_UNKNOWN = 0,
	PLAYERTYPE_LOCAL = 1,
	PLAYERTYPE_REMOTE = 2,
	PLAYERTYPE_OBSERVER = 3,
	PLAYERTYPE_AI = 4,
	PLAYERTYPE_SIMULATED = 5,
};

enum eCarClass {
	CARCLASS_ANY,
	CARCLASS_DERBY,
	CARCLASS_RACING,
	CARCLASS_STREET,
	CARCLASS_STUNT,
	CARCLASS_NOBONUS,
	CARCLASS_BONUS,
	CARCLASS_SAMEASHOST,
};

// chloe collection stunt show air control
enum eAirControlMode {
	AIRCONTROL_DEFAULT,
	AIRCONTROL_ON,
	AIRCONTROL_YAWONLY,
	AIRCONTROL_OFF
};