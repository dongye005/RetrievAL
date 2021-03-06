#include <windows.h>
#include "TSSGCtrl.h"

__declspec(naked) struct
{
	bool   CheckFunnel;
	HANDLE SHandle;
} __cdecl TSSDoubleList_Write_CheckFunnel(ResErr result)
{
	__asm
	{
		#define SSGC          (ebp + 0x0C)
		#define SSGS          (ebp + 0x08)
		#define SHandle       (ebp - 0x04)
		#define Index         (ebp - 0x0160)

		test    eax, eax
		jnz     PASS// FixDoubleList/TSSDoubleList_SwitchStatus.c raised reINDEX_ERROR
		mov     edx, dword ptr [SSGS]
		mov     ecx, dword ptr [SSGC]
		push    dword ptr [Index]
		push    edx
		push    ecx
		call    dword ptr [TSSGCtrl_CheckFunnel]
		add     esp, 12
	PASS:
		mov     edx, dword ptr [SHandle]
		ret
		
		#undef Index
		#undef SHandle
		#undef SSGS
		#undef SSGC
	}
}

