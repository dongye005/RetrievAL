.486
.model flat, c

extrn EnableParserFix:dword
extrn ReplaceDefineDynamic@8:proc

public TSSGCtrl_AddressNaming_ReplaceDefineDynamic1

.code

align 16

TSSGCtrl_AddressNaming_ReplaceDefineDynamic1 proc near

	CallAddress equ 00504284H
	SSGS        equ <ebp + 10H>
	NameStr     equ edx

	mov     eax, dword ptr [EnableParserFix]
	mov     ecx, dword ptr [SSGS]
	test    eax, eax
	jz      L1
	push    NameStr
	push    ecx
	push    CallAddress
	jmp     ReplaceDefineDynamic@8
L1:
	mov     eax, CallAddress
	jmp     eax

TSSGCtrl_AddressNaming_ReplaceDefineDynamic1 endp

end