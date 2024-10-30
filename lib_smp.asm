; bilioteca de rotinas SMP

public	COD0,COD1,COD2,COD3,COD4,COD5,COD6,COD7
public    dig0,dig1,dig2,dig3,dig4
public	init_lib,muxdisplay,_convert,_bintobcd,_delaycm	

; Arquivo com as funções Arduíno 

public _digitalWrite,_digitalRead,_delay,_pinMode


DSP1      equ       P2.0      
DSP2      equ       P2.1
DSP3      equ       P2.2      
DSP4      equ       P2.3
DSP0      equ       P2.4      
DSP5      equ       P2.5
DSP6      equ       P2.6      
DSP7      equ       P2.7

dados	segment	data
prog	segment   code
xdados	segment	xdata
;flags     segment   bit

 ;         rseg      flags


	rseg	dados
DIGITO:	ds	1
PDIGITO:	ds	1
COD1:	ds	1
COD2:	ds	1
COD3:	ds	1
COD4:	ds	1
COD0:	ds	1
COD5:	ds	1
COD6:	ds	1
COD7:	ds	1

dig0:	ds	1
dig1:	ds	1
dig2:	ds	1
dig3:	ds	1
dig4:	ds	1


	rseg	xdados
dummy:	ds	1

	rseg	prog
init_lib:	clr	DSP0
          mov       DIGITO,#0FEh
          mov       PDIGITO,#0
	ret
;=====================================================================

muxdisplay:
          push      psw
          push      acc
          push      00h
          mov	P2,#0ffh	   ;16 ciclos 8us
	mov	a,#COD1
	add	a,PDIGITO
	MOV	R0,a
	mov	P0,@r0
	mov	a,DIGITO
	mov	P2,a
	inc	PDIGITO
	anl	PDIGITO,#07h
	rl	a
	mov	DIGITO,a
          pop       00h
          pop       acc
          pop       psw
	ret

;---------------------delay---------------------------------
; Nc =  16*R5:R6:R7 + 6; 
;
_delaycm: mov       a,r7      ;1
          dec       r7        ;1
          jnz       fimd      ;2
          mov       a,r6      ;1
          dec       R6        ;1
          jnz       fimd2     ;2
          dec       R5        ;1
          sjmp      seg1      ;2 = 11
fimd:     nop                 ;1
          nop                 ;1
          nop                 ;1
          nop                 ;1
fimd2:    nop                 ;1
          nop                 ;1
          nop                 ;1
seg1:     mov       a,r7      ;1
          orl       a,r6      ;1
          orl       a,r5      ;1
          jnz       _delaycm  ;2
          ret                 ;2
;=====================================================================


_convert:	mov       a,r7
          mov	dptr,#tabela7seg
	movc	a,@a+dptr  ; pega na tabela o equivalente 7 segmentos
          mov       r7,a
	ret
;=====================================================================

;
;  num = r6:r7
;
_bintobcd:
          mov       a,r7
	mov	r3,#16
	clr	c
	mov	dig0,#0
	mov	dig1,#0
	mov	dig2,#0
	mov	dig3,#0
	mov	dig4,#0

bintodecx:rlc	a
	xch	a,r6
	rlc	a
	xch	a,r6

	push	acc

	mov	a,dig0
	addc	a,acc
	cjne	a,#10,dif9
dif9:	jc	fim0
	clr	c
	subb	a,#10
fim0:	cpl	c
	mov	dig0,a

	mov	a,dig1
	addc	a,acc
	cjne	a,#10,dif91
dif91:	jc	fim1
	clr	c
	subb	a,#10
fim1:	cpl	c
	mov	dig1,a

	mov	a,dig2
	addc	a,acc
	cjne	a,#10,dif92
dif92:	jc	fim2
	clr	c
	subb	a,#10
fim2:	cpl	c
	mov	dig2,a

	mov	a,dig3
	addc	a,acc
	cjne	a,#10,dif93
dif93:	jc	fim3
	clr	c
	subb	a,#10
fim3:	cpl	c
	mov	dig3,a

	mov	a,dig4
	addc	a,acc
	cjne	a,#10,dif94
dif94:	jc	fim4
	clr	c
	subb	a,#10
fim4:	cpl	c
	mov	dig4,a

	pop	acc
	djnz	r3,bintodecx
	ret
;=====================================================================


tabela7seg:
	db	0C0h	;0 - 1100$0000
	db	0F9h      ;1 - 1111$1001
	db	0A4h      ;2 - 1010$0100
	db        0B0h	;3 - 1011$0000
	db        099h      ;4 - 1001$1001
	db	092h      ;5 - 1001$0010
	db	082h      ;6 - 1000$0010
	db	0d8h      ;7 - 1101$1000
	db	080h      ;8 - 1000$0000
	db	090h      ;9 - 1001$0000



;r7 numero do pino, r5 nivel 1 ou 0
_digitalWrite:
          mov       a,r7
          mov       b,#8
          div       ab  ; a= porta, b = bit(0,7)
          mov       r7,a
          cjne      r5,#0,_setbit1
          mov       r5,b
          jmp       _clrbit
_setbit1:
          mov       r5,b
          jmp       _setbit
                          
_setbit:  mov       dptr,#tabela2
          mov       a,r5
          movc      a,@a+dptr      
          cjne      r7,#0,neh0
          orl       P0,a
neh0:
          cjne      r7,#1,neh1
          orl       P1,a
neh1:
          cjne      r7,#2,neh2
          orl       P2,a
neh2:
          cjne      r7,#3,neh3
          orl       P3,a

neh3:
          ret ; sub-rotinas retornam no ret


_clrbit:  mov       dptr,#tabela2
          mov       a,r5
          movc      a,@a+dptr 
          cpl       a     
          cjne      r7,#0,neh0a
          anl       P0,a
neh0a:
          cjne      r7,#1,neh1a
          anl       P1,a
neh1a:
          cjne      r7,#2,neh2a
          anl       P2,a
neh2a:
          cjne      r7,#3,neh3a
          anl       P3,a

neh3a:
          ret ; sub-rotinas retornam no ret

;r7 recebe o numero da porta
_digitalRead:
          mov       a,r7
          mov       b,#8
          div       ab  ; a= porta, b = bit(0,7)
          mov       r7,a
          mov       r5,b
          mov       dptr,#tabela2
          mov       a,r5
          movc      a,@a+dptr 
          mov       r5,a     
          cjne      r7,#0,neh0x
          mov       a,P0
          anl       a,r5
          jmp       finalx
neh0x:
          cjne      r7,#1,neh1x
          mov       a,P1
          anl       a,r5
          jmp       finalx
neh1x:
          cjne      r7,#2,neh2x
          mov       a,P2
          anl       a,r5
          jmp       finalx
neh2x:
          cjne      r7,#3,neh3x
          mov       a,P3
          anl       a,r5
          jmp       finalx

finalx:
          jz        jogazerox
          mov       r7,#1
          ret

jogazerox:
          mov       r7,#0
          ret
  
neh3x:
          ret ; sub-rotinas retornam no ret
          

;Parâmetro é em milisegundos r6:r7, clock 24mhZ
;Cm = 0.5us
;1ms = 2000Cm 
_delay:
          mov       r0,#250   ;PARA 1ms
loop:     nop ;1
          nop ;1      
          nop ;1
          nop ;1
          nop ;1
          nop ;1             ;6*0,5 = 3*250 = 750us 
          djnz      r0,loop  ;2 * 250 = 500 => 500 * 0,5 = 250us ;250us + 750us = 1ms  
          dec       r7
          mov       a,r7
          cjne      a,#0ffh,saltar
          dec       r6
saltar:
          mov       a,r6
          add       a,r7
          jnz       _delay
          ret

;Existe apenas por compatibilidade
_pinMode:
          
          ret


tabela2:   
          db        01h ; bit 0 = 1
          db        02h ; bit 1 = 1
          db        04h ; bit 2 = 2
          db        08h ; bit 3 = 1
          db        10h ; bit 4 = 1
          db        20h ; bit 5 = 1
          db        40h ; bit 6 = 1
          db        80h ; bit 7 = 1

          
	end

