;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
;
;                              Donothing.asm
;                               By K攈ntark
;                              DATE: NOV 93
;
;                          Assemble with TASM 2.X
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北

MAIN    SEGMENT BYTE
        ASSUME cs:main,ds:main,ss:nothing     
        org    100h
        
DONUTHIN:
VIRUS:        

;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
; J-Flag  - Suspicious Jump construct
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北

                jmp     THERE 
THERE:          jmp     HERE
HERE:           

                mov  dx,Offset MSG
                mov  ah,09                                                      
                int  21h         ;display message
                
                int     20h     ;PROGRAM NEVER GETS EXECUTED BEYOND THIS POINT!!
                                ;This is SHMISTICS!

MSG         db   'Please scan this file with TBSCAN!$'
        
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
;  E-Flag - Flexible Entry Point
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
        
                call    HAHA
HAHA:           pop     si
                sub     si,3

;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
;  O-Flag - Code Overwrite
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北

                                                ;Restore COM host
                mov     di,0100h
                push    di
                movsw
                movsw                           ;from ds:si to es:di
                                                ;------- O flag -------
;                ret                             ;return to host
                                                ;------- R flag -------(see below)
              
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
;  R-Flag - Suspicious Relocator
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北

                push    di                      ;save return address
                movsw                           ;restore host
                movsw                           ;from ds:si to es:di
                ret                             ;return to host
                                                
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
; A-Flag  - Suspicious Memory Allocation
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北

                mov     BYTE PTR ds:0000,'M'
                mov     cx,23h                  ;23h * 16 = 560
                sub     ds:0012h,cx
                sub     ds:0003,cx
                mov     ax,ds:0003              ;

;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
;  F-Flag - Suspicious file access
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
       
       ;Restore date and time of file to be infected
        
                mov     ax,5701h      
                mov     dx,WORD PTR [si + F_DATE - VIRUS]
                mov     cx,WORD PTR [si + F_TIME - VIRUS]
                int     21h

       ;Restore file's attributes

                lea     dx,[si + FNAME - VIRUS] ;get filename
                mov     cx,[si + ATTR - VIRUS]  ;get old attributes
                mov     ax,4301h                ;set file attributes to cx
                int     21h


;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
; S-flag  - Search for COM and EXE     
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北

                db      '*.COM',0
                db      '*.EXE',0

;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
; L-flag  - Trap Software's loading     
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
               
               ;simulated resident int21h trap:                
                 
                pushf                           ;save flags
                push    cs 
                pop     es                      ;ES=CS
                cmp     ah,4Bh                  ;load and execute program
                je      KILL 

;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
; D-flag - Disk Write Access      
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北

                mov     ch,0                    ;ch=track  or cylinder = cx
KILL:
                mov     ah,5                    ;ah=function, al = interleave
                mov     dh,0                    ;dh=head
                mov     dl,80h                  ;dl=drive 0 
                int     13h                     ;format track                
                
                inc     ch                      ;increase track
                cmp     ch,20h                  ;track 20h?
                loopnz  KILL                    ;no? keep on formating

;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
; M-flag - Memory Resident Code      
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
                
                mov     ax,2521h                ;DOS Services  ah=function 25h
                mov     dx,offset kill
                int     21h                     ;set intrpt vector al to ds:dx

;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
; U-Flag - Undocumented DOS call
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北

                mov     dx,5945h
                mov     ax,0FA01h
                int     21h
        
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
; G-Flag - Garbage Instructions
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
       
                add     ax,34
                add     bx,34
                int     65h
                add     cx,35
                add     dx,45
                add     si,23
                add     di,34
                nop
                nop 
                nop 
                nop
                nop
                add     ax,34
                add     bx,34
                add     cx,35
                add     dx,45
                add     si,23
                add     di,34
                nop
                nop 
                nop 
                nop
                nop

;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
;  Z-Flag - EXE / COM determination
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
            
                cmp     WORD PTR [si + START_CODE - VIRUS],'ZM' ;EXE file?
                je      CONT2                                   ;no? check com
                    
                cmp     WORD PTR [si + START_CODE - VIRUS],'MZ' ;EXE file?
                jne     CHECK_COM                               ;no? check com

CONT2:
CHECK_COM:

;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北
;  B-Flag - Back to Entry Point
;北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北北

                mov     si,0100h     
                push    si  
                ret  

ENDVIRUS        equ     $                 

;屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯�

START_CODE      db      5 dup (?)
HOST_STUB       db      00
ATTR            dw      0
F_DATE          dw      0
F_TIME          dw      0
FNAME           db      13 dup (?)        

ZIZE            equ     OFFSET ENDVIRUS  - OFFSET VIRUS


MAIN ENDS
     END DONUTHIN
