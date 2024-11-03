class MusicInterface {
public:
	// size 0x60
	struct tSong {
		FO2String sFile; // +0
		FO2String sArtist; // +1C
		FO2String sTitle; // +38
		uint32_t nStartPos; // +54
		void* pUnknownPtr1; // +58
		void* pUnknownPtr2; // +5C
	};

	static inline auto& bMusicLoaded = *(bool*)0x846420;

	static inline auto& gPlaylistTitle = *(FO2Vector<tSong>*)0x84678C;
	static inline auto& gPlaylistIngame = *(FO2Vector<tSong>*)0x846780;
	static inline auto& gPlaylistStunt = *(FO2Vector<tSong>*)0x846774;

	static inline auto& gPlaylistTitleCurrent = *(int*)0x715ED8;
	static inline auto& gPlaylistIngameCurrent = *(int*)0x715EDC;
	static inline auto& gPlaylistStuntCurrent = *(int*)0x715EE0;

	static inline auto& gPlaylistTitleNext = *(int*)0x846438;
	static inline auto& gPlaylistIngameNext = *(int*)0x84643C;
	static inline auto& gPlaylistStuntNext = *(int*)0x846440;

	static inline auto UpdateMusicVolume = (void(*)())0x41D340;

	static inline auto LoadPlaylist = (void(*)(int))0x41D870;
	static inline auto FreePlaylists = (void(*)())0x41DCC0;
	static inline auto FreeTitle = (void(*)())0x674430;
	static inline auto FreeIngame = (void(*)())0x6743B0;
	static inline auto FreeStunt = (void(*)())0x674330;
};