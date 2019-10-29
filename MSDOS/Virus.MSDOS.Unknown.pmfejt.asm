START	SEGMENT
	ASSUME CS:START,DS:START
	MOV	BX,80H
	MOV	CH,0
	MOV	CL,[BX]
	DEC	CX
	MOV	SI,OFFSET KODOK+100H
	CALL	BET
	JZ	KILEP
	MOV	SI,OFFSET FILEN+100H
	CALL	BET
	JZ	KILEP
	MOV	SI,OFFSET FILECO+100H
	CALL	BET
	JMP	FOLYT
KILEP:	INT	20H
FOLYT:	MOV	SI,OFFSET KODOK+100H
	MOV	BX,OFFSET KODTB+100H
CIKL1:	MOV	AL,[SI]
	OR	AL,AL
	JZ	FOLYT5
	OR	AL,20H
FOLYT5:	CMP	AL,[BX]
	JZ	FOLYTC
	JMP	KODER
FOLYTC:	CMP	AL,0
	JZ	FOLYT4
	INC	BX
	INC	SI
	JMP	CIKL1
FOLYT4:	MOV	AL,0
	MOV	AH,3DH
	MOV	DX,OFFSET FILECO+100H
	INT	21H
	JNC	FOLYTD
	JMP	FILER
FOLYTD:	PUSH	AX
	MOV	BX,AX
	MOV	AH,3FH
	MOV	CX,100H
	MOV	DX,OFFSET IPUFF+100H
	INT	21H
	POP	BX
	JNC	FOLYTE
	JMP	FILER
FOLYTE:	MOV	AH,3EH
	INT	21H
	JNC	FOLYTF
	JMP	FILER
FOLYTF:	MOV	BX,OFFSET IPUFF+100H
	MOV	SI,OFFSET PMNAM+100H
CIKL2:	MOV	AL,[SI]
	OR	AL,AL
	JZ	FOLYT7
	CMP	AL,[BX]
	JZ	PMOK
	JMP	PMER
PMOK:	INC	BX
	INC	SI
	JMP	CIKL2
FOLYT7:	MOV	DI,OFFSET FILMO+100H
	MOV	DL,2
CIKL4:	MOV	SI,OFFSET FILEN+100H
	MOV	CX,13
	REP	MOVSB
	DEC	DL
	JNZ	CIKL4	
FOLYTA:	MOV	BX,7
	MOV	CX,26
	MOV	AL,03FH
	MOV	AH,9
	INT	10H
	MOV	BX,OFFSET IPUFF+157H
	MOV	CX,26
	MOV	SI,OFFSET FILMO+100H
	MOV	DI,OFFSET OPUFF+100H
	MOV	BYTE PTR [IRANY+100H],1
CIKL6:	PUSH	CX
	MOV	CL,0
CIKL5:	MOV	AL,[SI]
	XOR	AL,CL
	ROR	AL,CL
	CMP	AL,[BX]
	JZ	FOLYTB
CIKL9:	ADD	CL,BYTE PTR [IRANY+100H]
	JNZ	CIKL5
	PUSH	BX
	PUSH	CX
	PUSH	AX
	MOV	AX,0E07H
	MOV	BX,0
	INT	10H
	MOV	AX,0E3FH
	MOV	BX,0
	INT	10H
	POP	AX
	POP	CX
	POP	BX
	JMP	TASZT
FOLYTB:	MOV	[DI],CL
	CMP	CL,128
	JC	FOLYTG
	JMP	CIKL9
FOLYTG:	CMP	CL,20H
	JC	CIKL9
TASZT1:	PUSH	CX
	PUSH	BX
	PUSH	AX
	MOV	BX,0
	MOV	AL,CL
	MOV	AH,0EH
	MOV	CX,1
	INT	10H
	POP	AX
	POP	BX
	POP	CX
TASZT:	MOV	AH,0
	INT	16H
	CMP	AH,4BH
	JZ	BAL
	CMP	AH,4DH
	JZ	JOBB
	CMP	AH,48H
	JZ	FEL
	CMP	AH,50H
	JZ	LE1
	CMP	AH,1CH
	JZ	ESC1
	JMP	TASZT
LE1:	CALL	BALRA
	MOV	BYTE PTR [IRANY+100H],0FFH
	JMP	CIKL9
BALRA:	PUSH	BX
	PUSH	CX
	PUSH	AX
	MOV	AX,0E08H
	MOV	BX,0
	INT	10H
	POP	AX
	POP	CX
	POP	BX
	RET
FEL:	CALL	BALRA
	MOV	BYTE PTR [IRANY+100H],01H
	JMP	CIKL9
BAL:	CALL	BALRA
	CMP	BX,OFFSET IPUFF+157H
	JNC	BAL1
	JMP	CIKL9
BAL1:	CALL	BALRA
	DEC	BX
	DEC	SI
	DEC	DI
	POP	CX
	INC	CX
	JMP	CIKL6
JOBB:	CMP	BX,OFFSET IPUFF+157H+25
	JC	JOBB1
	CALL	BALRA
	JMP	CIKL9
JOBB1:	INC	BX
	INC	SI
	INC	DI
	POP	CX
	DEC	CX
	JMP	CIKL6
ESC1:	POP	CX	
	MOV	AX,0E0DH
	MOV	BX,0
	INT	10H
	MOV	AX,0E0AH
	MOV	BX,0
	INT	10H
	MOV	BYTE PTR [OPUFF+100H+28],0
KILEP1:	MOV	SI,OFFSET OPUFF+100H
	CALL	KIIR
	JMP	KILEP
IRANY:	DB	1
PMER:	MOV	SI,OFFSET PERR+100H
	CALL	KIIR
	JMP	KILEP
KODER:	MOV	SI,OFFSET KDERR+100H
	CALL	KIIR
	JMP	KILEP
FILER:	MOV	SI,OFFSET FERR+100H
	CALL	KIIR
	JMP	KILEP
KIIR:	MOV	AL,[SI]
	CMP	AL,0
	JNZ	FOLYT6
	RET
FOLYT6:	MOV	AH,0EH
	MOV	BX,0
	INT	10H
	INC	SI
	JMP	KIIR
BET:	MOV	AL,[BX+2]
	CMP	AL,20H
	JNZ	FOLYT2
	MOV	BYTE PTR [SI],0
	INC	BX
	INC	SI
	LOOP	FOLYT3
	XOR	AL,AL
FOLYT3:	RET
FOLYT2:	MOV	[SI],AL
	INC	SI
	INC	BX
	LOOP	BET
	MOV	BYTE PTR [SI],0
	XOR	AL,AL
	RET
PMNAM:	DB	'File encrypted by PathMinder v2.01 (c) Copyright 1984,1985 Westlake Data Corporation',0
FERR:	DB	'TOLTESI HIBA A LEMEZEN',0DH,0AH,0
PERR:	DB	'HIBAS PM-VERZIO',0DH,0AH,0
KRERR:	DB	'KERESESI HIBA',0DH,0AH,0
KDERR:	DB	'KODOLASI HIBA',0DH,0AH,0
FILEN:	DB	64 DUP (0)
FILECO:	DB	64 DUP (0)	
KODOK:	DB	64 DUP (0)
KODTB:	DB	'feri&bozo',0
IPUFF:	DB	256 DUP (0)
FILMO:	DB	30 DUP (0)
OPUFF:	DB	32*64 DUP (0)
START	ENDS
	END
