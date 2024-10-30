;UNDERTALE DA TURMINHA DO DIDI XD
;escalonador

extrn code(task1, task2, task3)
public estado
  
            dseg at 8
estado: ds  1 
	
            cseg at 000bh   ;timer 0

            mov  th0,#(256-78) 
            mov  a, estado
            cjne a,#0, salto1
            call task1
            call task2
            call task3
            jmp  fim
  
salto1:     cjne a,#1,salto2
            call task1
			jmp  fim
			
salto2:		cjne a,#2,salto3
            call task1
			call task2
			jmp  fim

salto3:		cjne a,#3,salto4
            call task1
			call task3
			jmp  fim

salto4:		cjne a,#4,salto5
            call task1
			call task2
			jmp  fim

salto5:     cjne a,#5,salto6
            call task1
			mov  estado,#0
			jmp  fim2

salto6:
fim:     inc  estado
        jmp  fim2
fim2:       reti
            end