.data
mydata: double 1.2, -3.0, -46, 0.1
var: dword 34, 34, 56
.code
	daddi r9, r0, 32
	xori r2, r0, 10
	l.d f1, mydata(r0)
	l.d f2, mydata(r1)	
	daddi r1, r1, 1
init:
	daddi r1, r0, 32
loop:
	beq r9, r0, exit
	daddi r1, r1, -8
	ld r10, var(r0)
	l.d f3, mydata(r1)
	mul.d f6, f2, f2
	div.d f6, f6, f1
	dadd r2, r1, r1
	daddi r9, r9, -8
	bne r1, r0, loop
	beqz r9, endprogram
	xor r2, r1, r3
endprogram:
	daddi r1, r0, 8
exit:
	nop

