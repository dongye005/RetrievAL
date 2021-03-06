#include <windows.h>
#include "intrinsic.h"

EXTERN_C void __cdecl TMainForm_SubjectAccess_StoreFileNamePrefix();
EXTERN_C void __cdecl TMainForm_SubjectAccess_CorrectListItemText();
EXTERN_C void __cdecl TMainForm_SubjectAccess_ToULongDef();
#define TSSGCtrl_DrawTreeCell_StoreFileNamePrefix TMainForm_SubjectAccess_StoreFileNamePrefix
EXTERN_C void __cdecl TMainForm_DrawTreeCell_CorrectDrawText();
#define TSSGCtrl_LoopSSRFile_StoreFileNamePrefix TMainForm_SubjectAccess_StoreFileNamePrefix
EXTERN_C void __cdecl TSSGCtrl_EnumReadSSR_SwitchCommonList();
EXTERN_C void __cdecl TSSGCtrl_LoopSSRFile_CommonList();
EXTERN_C void __cdecl TSSGCtrl_AddressNaming_CommonList();

EXTERN_C void __cdecl Attach_CommonList()
{
	// TMainForm::SubjectAccess
	// case ssgCtrl::atLONG_INDEX:
	/*
		push    0                                   ; 0043A4ED _ 6A, 00
		sub     esp, 24                             ; 0043A4EF _ 83. EC, 18
		mov     word ptr [esi + 10H], 260           ; 0043A4F2 _ 66: C7. 46, 10, 0104
		lea     ecx, [ebp - 0A8H]                   ; 0043A4F8 _ 8D. 8D, FFFFFF58
		mov     eax, esp                            ; 0043A4FE _ 8B. C4
		push    ecx                                 ; 0043A500 _ 51
		inc     dword ptr [esi + 1CH]               ; 0043A501 _ FF. 46, 1C
		push    00602CD8H                           ; 0043A504 _ 68, 00602CD8(d)
	*/
	*(LPDWORD)0x0043A4EC = BSWAP32(0x006A0083);
	*(LPDWORD)0x0043A4F0 = BSWAP32(0xEC1866C7);
	*(LPDWORD)0x0043A4F4 = BSWAP32(0x46100401);
	*(LPDWORD)0x0043A4F8 = BSWAP32(0x8D8D58FF);
	*(LPDWORD)0x0043A4FC = BSWAP32(0xFFFF8BC4);
	*(LPDWORD)0x0043A500 = BSWAP32(0x51FF461C);
	*(LPDWORD)0x0043A504 = BSWAP32(0x68D82C60);
	*(LPBYTE )0x0043A508 =         0x00       ;

	*(LPDWORD)(0x0043A54F + 1) = (DWORD)TMainForm_SubjectAccess_StoreFileNamePrefix - (0x0043A54F + 1 + sizeof(DWORD));

	/*
		jmp     0043A79AH                           ; 0043A5A2 _ E9, 000001F3
	*/
	*(LPDWORD)0x0043A5A3 = 0x000001F3;

	*(LPDWORD)(0x0043A648 + 1) = (DWORD)TMainForm_SubjectAccess_CorrectListItemText - (0x0043A648 + 1 + sizeof(DWORD));

	/*
		sub     dword ptr [esi + 1CH], 3            ; 0043A796 _ 83. 6E, 1C, 03
		pop     ecx                                 ; 0043A79A _ 59
		jmp     0043CBF1H                           ; 0043A79B _ E9, 00002451
		nop                                         ; 0043A7A0 _ 90
		nop                                         ; 0043A7A1 _ 90
		nop                                         ; 0043A7A2 _ 90
		nop                                         ; 0043A7A3 _ 90
	*/
	*(LPWORD )0x0043A796 = BSWAP16(    0x836E);
	*(LPDWORD)0x0043A798 = BSWAP32(0x1C0359E9);
	*(LPDWORD)0x0043A79C = BSWAP32(0x51240000);
	*(LPDWORD)0x0043A7A0 = BSWAP32(0x90909090);

#ifdef FORMAT_NOT_IMPLEMENTED
	// TMainForm::DrawTreeCell
	// case ssgCtrl::atLONG_INDEX:
	/*
		push    0                                   ; 00445531 _ 6A, 00
		sub     esp, 24                             ; 00445533 _ 83. EC, 18
		mov     word ptr [ebp - 174H], 308          ; 00445536 _ 66: C7. 85, FFFFFE8C, 0134
		lea     eax, [ebp - 0B4H]                   ; 0044553F _ 8D. 85, FFFFFF4C
		mov     edx, esp                            ; 00445545 _ 8B. D4
		push    eax                                 ; 00445547 _ 50
		inc     dword ptr [ebp - 168H]              ; 00445548 _ FF. 85, FFFFFE98
		push    0060310FH                           ; 0044554E _ 68, 0060310F(d)
	*/
	*(LPDWORD)0x00445530 = BSWAP32(0x006A0083);
	*(LPDWORD)0x00445534 = BSWAP32(0xEC1866C7);
	*(LPDWORD)0x00445538 = BSWAP32(0x858CFEFF);
	*(LPDWORD)0x0044553C = BSWAP32(0xFF34018D);
	*(LPDWORD)0x00445540 = BSWAP32(0x854CFFFF);
	*(LPDWORD)0x00445544 = BSWAP32(0xFF8BD450);
	*(LPDWORD)0x00445548 = BSWAP32(0xFF8598FE);
	*(LPDWORD)0x0044554C = BSWAP32(0xFFFF680F);
	*(LPDWORD)0x00445550 = BSWAP32(0x31600052);

	*(LPDWORD)(0x004455A5 + 1) = (DWORD)TSSGCtrl_DrawTreeCell_StoreFileNamePrefix - (0x004455A5 + 1 + sizeof(DWORD));

	/*
		je      004457C6H                           ; 004455D8 _ 0F 84, 000001E8
	*/
	*(LPWORD )0x004455DA = 0x01E8;

	/*
		jbe     004457C6H                           ; 004455FD _ 0F 86, 000001C3
	*/
	*(LPDWORD)0x004455FF = 0x000001C3;

	*(LPDWORD)(0x0044566C + 1) = (DWORD)TMainForm_DrawTreeCell_CorrectDrawText - (0x0044566C + 1 + sizeof(DWORD));

	/*
		sub     dword ptr [ebp - 168H], 2           ; 004457BF _ 83. AD, FFFFFE98, 02
		pop     ecx                                 ; 004457C6 _ 59
		jmp     00445B80H                           ; 004457C7 _ E9, 000003B4
		nop                                         ; 004457CC _ 90
		nop                                         ; 004457CD _ 90
		nop                                         ; 004457CE _ 90
		nop                                         ; 004457CF _ 90
	*/
	*(LPBYTE )0x004457BF =               0x83 ;
	*(LPDWORD)0x004457C0 = BSWAP32(0xAD98FEFF);
	*(LPDWORD)0x004457C4 = BSWAP32(0xFF0259E9);
	*(LPDWORD)0x004457C8 = BSWAP32(0xB4030000);
	*(LPDWORD)0x004457CC = BSWAP32(0x90909090);
#endif

	// TSSDoubleList::Read
	/*
		mov     eax, dword ptr [eax]                ; 004C43D6 _ 8B. 00
		lea     edx, [edx + edx * 2]                ; 004C43D8 _ 8D. 14 52
		mov     eax, dword ptr [eax + edx * 8]      ; 004C43DB _ 8B. 04 D0
		xor     ecx, ecx                            ; 004C43DE _ 33. C9
		push    eax                                 ; 004C43E0 _ 50
		call    TMainForm_SubjectAccess_ToULongDef  ; 004C43E1 _ E8, <offset TMainForm_SubjectAccess_ToULongDef - 004C43E6>
	*/
	*(LPWORD )0x004C43D6 = BSWAP16(    0x8B00);
	*(LPDWORD)0x004C43D8 = BSWAP32(0x8D14528B);
	*(LPDWORD)0x004C43DC = BSWAP32(0x04D033C9);
	*(LPDWORD)0x004C43E2 = (DWORD)TMainForm_SubjectAccess_ToULongDef - 0x004C43E6;

	// TSSDoubleList::Write
	/*
		mov     eax, dword ptr [eax]                ; 004C54BD _ 8B. 00
		lea     edx, [edx + edx * 2]                ; 004C54BF _ 8D. 14 52
		mov     eax, dword ptr [eax + edx * 8]      ; 004C54C2 _ 8B. 04 D0
		mov     cl, 4                               ; 004C54C5 _ B1, 04
		push    eax                                 ; 004C54C7 _ 50
		call    TMainForm_SubjectAccess_ToULongDef  ; 004C54C8 _ E8, <offset TMainForm_SubjectAccess_ToULongDef - 004C54CD>
	*/
	*(LPDWORD)0x004C54BC = BSWAP32(0xFF8B008D);
	*(LPDWORD)0x004C54C0 = BSWAP32(0x14528B04);
	*(LPDWORD)0x004C54C4 = BSWAP32(0xD0B10450);
	*(LPDWORD)0x004C54C9 = (DWORD)TMainForm_SubjectAccess_ToULongDef - 0x004C54CD;

	// TSSDoubleList::ToByteCode
	/*
		mov     eax, dword ptr [eax]                ; 004C679B _ 8B. 00
		lea     edx, [edx + edx * 2]                ; 004C679D _ 8D. 14 52
		mov     eax, dword ptr [eax + edx * 8]      ; 004C67A0 _ 8B. 04 D0
		mov     cl, 8                               ; 004C67A3 _ B1, 08
		push    eax                                 ; 004C67A5 _ 50
		call    TMainForm_SubjectAccess_ToULongDef  ; 004C67A6 _ E8, <offset TMainForm_SubjectAccess_ToULongDef - 004C67AB>
	*/
	*(LPDWORD)0x004C6798 = BSWAP32(0xFDFFFF8B);
	*(LPDWORD)0x004C679C = BSWAP32(0x008D1452);
	*(LPDWORD)0x004C67A0 = BSWAP32(0x8B04D0B1);
	*(LPBYTE )0x004C67A4 =         0x08       ;
	*(LPDWORD)0x004C67A7 = (DWORD)TMainForm_SubjectAccess_ToULongDef - 0x004C67AB;

	// TSSGCtrl::EnumReadSSR
#if 0// replaced at "FixRepeat/Attach_FixRepeat.c"
	*(LPDWORD)(0x004FFDD5 + 1) = (DWORD)TSSGCtrl_EnumReadSSR_SwitchCommonList - (0x004FFDD5 + 1 + sizeof(DWORD));
#endif

	// TSSGCtrl::LoopSSRFile
	// Type == ssgCtrl::rtFILE
	/*
		push    0                                   ; 00502091 _ 6A, 00
		sub     esp, 24                             ; 00502093 _ 83. EC, 18
		mov     word ptr [ebx + 10H], 212           ; 00502096 _ 66: C7. 43, 10, 00D4
		lea     eax, [ebp - 0F8H]                   ; 0050209C _ 8D. 85, FFFFFF08
		mov     edx, esp                            ; 005020A2 _ 8B. D4
		push    eax                                 ; 005020A4 _ 50
		inc     dword ptr [ebx + 1CH]               ; 005020A5 _ FF. 43, 1C
		push    00631C0DH                           ; 005020A8 _ 68, 00631C0D(d)
	*/
	*(LPDWORD)0x00502090 = BSWAP32(0x006A0083);
	*(LPDWORD)0x00502094 = BSWAP32(0xEC1866C7);
	*(LPDWORD)0x00502098 = BSWAP32(0x4310D400);
	*(LPDWORD)0x0050209C = BSWAP32(0x8D8508FF);
	*(LPDWORD)0x005020A0 = BSWAP32(0xFFFF8BD4);
	*(LPDWORD)0x005020A4 = BSWAP32(0x50FF431C);
	*(LPDWORD)0x005020A8 = BSWAP32(0x680D1C63);
	*(LPDWORD)0x005020AC = BSWAP32(0x0052E835);

	*(LPDWORD)(0x005020EA + 1) = (DWORD)TSSGCtrl_LoopSSRFile_StoreFileNamePrefix - (0x005020EA + 1 + sizeof(DWORD));

	/*
		jnz     0050210BH                           ; 005020FF _ 75, 0A
		pop     ecx                                 ; 00502101 _ 59
		jmp     005026B6H                           ; 00502102 _ E9, 000005AF
		nop                                         ; 00502107 _ 90
		nop                                         ; 00502108 _ 90
		nop                                         ; 00502109 _ 90
		nop                                         ; 0050210A _ 90
		mov     eax, dword ptr [ebp - 180H]         ; 0050210B _ 8B. 85, FFFFFE80
		mov     ecx, dword ptr [ebp + 14H]          ; 00502111 _ 8B. 4D, 14
		mov     eax, dword ptr [eax]                ; 00502114 _ 8B. 00
		push    ecx                                 ; 00502116 _ 51
		mov     dword ptr [ebp - 180H], eax         ; 00502117 _ 89. 85, FFFFFE80
		lea     edx, [ebp - 60H]                    ; 0050211D _ 8D. 55, A0
	*/
	*(LPBYTE )0x005020FF =               0x75 ;
	*(LPDWORD)0x00502100 = BSWAP32(0x0A59E9AF);
	*(LPDWORD)0x00502104 = BSWAP32(0x05000090);
	*(LPDWORD)0x00502108 = BSWAP32(0x9090908B);
	*(LPDWORD)0x0050210C = BSWAP32(0x8580FEFF);
	*(LPDWORD)0x00502110 = BSWAP32(0xFF8B4D14);
	*(LPDWORD)0x00502114 = BSWAP32(0x8B005189);
	*(LPDWORD)0x00502118 = BSWAP32(0x8580FEFF);
	*(LPDWORD)0x0050211C = BSWAP32(0xFF8D55A0);

	*(LPDWORD)(0x005021C7 + 1) = (DWORD)TSSGCtrl_LoopSSRFile_CommonList - (0x005021C7 + 1 + sizeof(DWORD));

	/*
		add     esp, 20                             ; 005021D2 _ 83. C4, 14
	*/
	*(LPBYTE )0x005021D4 = 0x14;

	// TSSGCtrl::AddressNaming
	//   if(Index!= TStringDivision::ToULongDef( strD.Half(&tmpS,"=") ))
	*(LPDWORD)(0x005059BB + 1) = (DWORD)TSSGCtrl_AddressNaming_CommonList - (0x005059BB + 1 + sizeof(DWORD));
}
