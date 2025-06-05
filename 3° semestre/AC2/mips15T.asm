.text 
.globl main
main:
lui $t0, 0x1001           #t0 = 0x10010000
lw  $s0, 0 ($t0)          # s0 = valor de A
ori $t6, $zero, 2
div $s0, $t6
mfhi $t1     # x % 2
beq $t1, $zero, par  # se for zero vai para par
mult $s0, $s0 #x^2
mflo $t2
mult $s0, $t2 # x^3
mflo $t2
mult $s0, $t2 # x^4
mflo $t3
mult $t3, $s0  #x^5
mflo $t3

sub $s1, $t3, $t2
addi $s1, $s1, 1
j fim

par: 
mult $s0, $s0 #x^2
mflo $t2
mult $s0, $t2 # x^3
mflo $t3
mult $s0, $t3 # x^4
mflo $t4
mult $t2, $t6  #2 * x^2
mflo $t2

add $s1, $t3, $t4
sub $s1, $s1, $t2

fim:
sw  $s1, 4 ($t0)          # MEM[t0] = A


.data
A: .word 12
 
