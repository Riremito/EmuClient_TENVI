#include"../Share/Simple/Simple.h"
#include"../Share/Hook/SimpleHook.h"

bool Tenvi_2ch() {
	Rosemary r;
	// HSUpdate ���C�v���Ɠ���
	r.Patch(0x005D70D6, L"31 C0 C2 0C 00");
	// EHSvc Loader 2 ���C�v���Ɠ���
	r.Patch(0x005D4A98, L"31 C0 C2 18 00");
	// EHSvc Loader 1? ���C�v���ƈႤ
	r.Patch(0x005D4D27, L"31 C0 C3");
	// HS Init? ���C�v���Ɩ߂�l�Ⴄ
	r.Patch(0x005749CE, L"B8 01 00 00 00 C3");
	// �E�B���h�E���[�h, �ꉞ���W�X�g���ݒ�ŉ\�炵��
	r.Patch(0x005915D6, L"31 C0 40");

	MessageBoxW(NULL, L"OK = Start", L"Tenvi_2ch.dll", MB_OK);
	return true;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
	{
		DisableThreadLibraryCalls(hinstDLL);
		Tenvi_2ch();
		break;
	}
	case DLL_PROCESS_DETACH:
	{
		break;
	}
	default:
	{
		break;
	}
	}
	return TRUE;
}