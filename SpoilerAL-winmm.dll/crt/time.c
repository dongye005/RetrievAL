#include <windows.h>

#ifndef _M_IX86
__time32_t __cdecl _time32(__time32_t *timer)
{
	ULONGLONG time;

	GetSystemTimeAsFileTime((LPFILETIME)&time);
	time = (time - 116444736000000000) / 10000000;
	if (timer)
		*timer = (__time32_t)time;
	return (__time32_t)time;
}
#else
__declspec(naked) __time32_t __cdecl _time32(__time32_t *timer)
{
	__asm
	{
		#define timer (esp + 4)

		push    0
		push    0
		push    esp
		call    GetSystemTimeAsFileTime
		pop     eax
		pop     edx
		sub     eax, 0xD53E8000
		mov     ecx, 10000000
		sbb     edx, 0x019DB1DE
		div     ecx
		mov     ecx, dword ptr [timer]
		test    ecx, ecx
		jz      L1
		mov     dword ptr [ecx], eax
	L1:
		ret

		#undef timer
	}
}
#endif

#ifndef _M_IX86
__time64_t __cdecl _time64(__time64_t *timer)
{
	ULONGLONG time;

	GetSystemTimeAsFileTime((LPFILETIME)&time);
	time = (time - 116444736000000000) / 10000000;
	if (timer)
		*timer = (__time64_t)time;
	return (__time64_t)time;
}
#else
__declspec(naked) __time64_t __cdecl _time64(__time64_t *timer)
{
	/* reciprocal divisor:
	 *   ((1 << 64) + 10000000 - 1) / 10000000 = ((1 << 64) + 0x98967F) / 0x989680
	 *                                         = 0x1000000000098967 / 0x98968
	 *                                         = 0x000001AD7F29ABCB
	 * division:
	 *   x / 10000000 = (x * 0x000001AD7F29ABCB) >> 64
	 */
	__asm
	{
		#define timer (esp + 4)

		push    ebx
		push    esi
		push    0
		push    0
		push    esp
		call    GetSystemTimeAsFileTime
		pop     ecx
		pop     ebx
		sub     ecx, 0xD53E8000
		mov     eax, 0x7F29ABCB
		sbb     ebx, 0x019DB1DE
		mul     ecx
		mov     eax, 0x7F29ABCB
		mov     esi, edx
		mul     ebx
		add     esi, eax
		mov     eax, ecx
		mov     ecx, edx
		mov     edx, 0x000001AD
		adc     ecx, 0
		mul     edx
		add     esi, eax
		mov     eax, ebx
		adc     ecx, edx
		mov     ebx, 0
		adc     ebx, 0
		mov     edx, 0x000001AD
		mul     edx
		add     eax, ecx
		mov     ecx, dword ptr [timer + 8]
		adc     edx, ebx
		test    ecx, ecx
		jz      L1
		mov     dword ptr [ecx], eax
		mov     dword ptr [ecx + 4], edx
	L1:
		pop     esi
		pop     ebx
		ret

		#undef timer
	}
}
#endif
