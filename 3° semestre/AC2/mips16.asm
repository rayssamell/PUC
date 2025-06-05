# Escreva um programa que avalie a expressão: (x*y)/z.
# Use x = 1600000 (=0x186A00)->s0 , y = 80000 (=0x13880)-> s1, e z = 400 000 (=0x61A80)->s2. Inicializar os
# registradores com os valores acima

.text
.globl main

main:
ori $s0, $zero, 0x186A     # $s0 = 0x0000186A
sll $s0, $s0, 8            # $s0 = 0x00186A00
ori $s1, $zero, 0x1388     # $s1 = 0x00001388
sll $s1, $s1, 4            # $s1 = 0x00013880
ori $s2, $zero, 0x61A8     # $s2 = 0x000061A8
sll $s2, $s2, 4            # $s2 = 0x00061A80
ori $t0,$s0, 0         #aux=x

aqui:
addi $s1, $s1, -1 #y =-
bne $s1, $zero, mult  # se y!=0
j fim

mult:
add $s0, $s0, $t0  #x=x+aux
j aqui

fim: