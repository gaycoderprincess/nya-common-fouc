#include <filesystem>

namespace FO2Version {
	enum eVersions {
		FO1_1_1,
		FO1_ZOOM,
		FO2_1_2,
		FO2_ZOOM,
		FOUC_GFWL,
		FOUC_ZOOM,
	};

	const char* aFO1VersionFail = "Unsupported game version! Make sure you're using v1.1 (.exe size of 2822144 bytes)\n\nYou can acquire this .exe from ZPatch FO1.\n\nNote that the newest \"\"update\"\" is not supported.";
	const char* aFO2VersionFail = "Unsupported game version! Make sure you're using DRM-free v1.2 (.exe size of 2990080 bytes)\n\nYou can acquire this .exe from Selo's Car Pack or ZPatch FO2.\n\nNote that the newest \"\"update\"\" is not supported.";
	const char* aFOUCVersionFail = "Unsupported game version! Make sure you're using the Steam GFWL version (.exe size of 4242504 bytes)\n\nNote that the newest \"\"update\"\" is not supported.";
	const char* aGenericVersionFail = "Unsupported game version!";

	bool IsFO1ZOOMVersion() {
		if (GetModuleHandleA("fo_zoom.dll")) return true;
		if (std::filesystem::exists("data.bfs") && std::filesystem::file_size("data.bfs") == 1280764879) return true;
		if (std::filesystem::exists("zoom_platform.bfs")) return true;
		return false;
	}

	bool IsFO2ZOOMVersion() {
		if (GetModuleHandleA("fo2_zoom.dll")) return true;
		if (std::filesystem::exists("data.bfs") && std::filesystem::file_size("data.bfs") == 2473174138) return true;
		if (std::filesystem::exists("zoom_platform.bfs")) return true;
		return false;
	}

	bool IsFOUCZOOMVersion() {
		auto xliveSize = std::filesystem::exists("xlive.dll") ? std::filesystem::file_size("xlive.dll") : UINT_MAX;
		if (xliveSize == 732064 || (xliveSize <= 1000000 && std::filesystem::exists("zoom_flatout.ini"))) return true;

		if (std::filesystem::exists("data.bfs") && std::filesystem::file_size("data.bfs") == 1987070590) return true;
		if (std::filesystem::exists("streamed.bfs") && std::filesystem::file_size("streamed.bfs") == 1836064668) return true;
		if (std::filesystem::exists("zoom_platform.bfs")) return true;
		return false;
	}

	int GetFlatOutVersion() {
		auto entryPoint = NyaHookLib::GetEntryPoint();
		if (entryPoint == 0x1E829F) {
			return IsFO1ZOOMVersion() ? FO1_ZOOM : FO1_1_1;
		}
		if (entryPoint == 0x202638) {
			return IsFO2ZOOMVersion() ? FO2_ZOOM : FO2_1_2;
		}
		if (entryPoint == 0x24CEF7) {
			return IsFOUCZOOMVersion() ? FOUC_ZOOM : FOUC_GFWL;
		}
		return -1;
	}
}

void DoFlatOutVersionCheck(int targetVersion) {
	auto failText = FO2Version::aGenericVersionFail;
	switch (targetVersion) {
		case FO2Version::FO1_1_1:
			failText = FO2Version::aFO1VersionFail;
			break;
		case FO2Version::FO2_1_2:
			failText = FO2Version::aFO2VersionFail;
			break;
		case FO2Version::FOUC_GFWL:
			failText = FO2Version::aFOUCVersionFail;
			break;
	}

	if (FO2Version::GetFlatOutVersion() != targetVersion) {
		MessageBoxA(nullptr, failText, "nya?!~", MB_ICONERROR);
		exit(0);
	}
}