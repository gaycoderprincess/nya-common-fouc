namespace NyaFO2Hooks {
	std::vector<void(*)()> aEndSceneFuncs;
	std::vector<void(*)()> aD3DResetFuncs;
	std::vector<void(*)(HWND, UINT, WPARAM, LPARAM)> aWndProcFuncs;

	auto EndSceneOrig = (HRESULT(__thiscall*)(void*))nullptr;
	HRESULT __fastcall EndSceneHook(void* a1) {
		for (auto& func : aEndSceneFuncs) {
			func();
		}
		return EndSceneOrig(a1);
	}

	auto D3DResetOrig = (void(__thiscall*)(void*))nullptr;
	void __fastcall D3DResetHook(void* a1) {
		for (auto& func : aD3DResetFuncs) {
			func();
		}
		return D3DResetOrig(a1);
	}

	auto WndProcOrig = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))nullptr;
	LRESULT __stdcall WndProcHook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		for (auto& func : aWndProcFuncs) {
			func(hWnd, msg, wParam, lParam);
		}
		return WndProcOrig(hWnd, msg, wParam, lParam);
	}

	void PlaceD3DHooks() {
		if (!EndSceneOrig) {
			EndSceneOrig = (HRESULT(__thiscall*)(void*))(*(uintptr_t*)0x677448);
			NyaHookLib::Patch(0x677448, &EndSceneHook);
			D3DResetOrig = (void(__thiscall*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x60F744, &D3DResetHook);
		}
	}

	void PlaceWndProcHooks() {
		if (!WndProcOrig) {
			WndProcOrig = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))(*(uintptr_t*)0x60F0CF);
			NyaHookLib::Patch(0x60F0CF, &WndProcHook);
		}
	}
}