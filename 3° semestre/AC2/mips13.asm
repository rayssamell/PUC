# Escreva um programa que leia um valor A da memória, identifique se o número é negativo ou
# não e encontre o seu módulo. O valor deverá ser reescrito sobre A

.text
.globl main
main:
lui $t0, 0x1001           #t0 = 0x10010000
lw  $s0, 0 ($t0)          # s0 = valor de A
sra $t1, $s0, 31          # t1 = pega bit mais significativo
bne $t1, $zero, modulo    # (t1 != 0) 
j registrar                

modulo:
sub $s0, $zero, $s0  # $t1 = $t1 - t2 (se t2=-1, soma 1)

registrar:
sw  $s0, 0 ($t0)          # MEM[t0] = A

.data
A: .word -111111
