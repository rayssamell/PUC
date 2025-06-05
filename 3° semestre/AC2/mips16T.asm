.text 
.globl main
main:
lui $t0, 0x1001           #t0 = 0x10010000
lw  $s0, 0 ($t0)          # s0 = valor de A
slt $t1, $zero, $s0       # se 0 < x  
bne $t1, $zero, maior      # se for zero vai para par
mult $s0, $s0 #x^2
mflo $t2
mult $s0, $t2 # x^3
mflo $t2
mult $s0, $t2 # x^4
mflo $t2
addi $s1, $t2, -1
j fim

maior: 
mult $s0, $s0 #x^2
mflo $t2
mult $s0, $t2 # x^3
mflo $t2
addi $s1, $t2, 1

fim:
sw  $s1, 4 ($t0)          # MEM[t0] = A


.data
A: .word -12
 
