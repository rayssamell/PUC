# Escreva um programa que avalie a expressão: (x*y)/z.
# Use x = 1600000 (=0x186A00)->s0 , y = 80000 (=0x13880)-> s1, e z = 400 000 (=0x61A80)->s2. Inicializar os
# registradores com os valores acima

.text
.globl main
main:
ori $s0, $zero, 0x186A  # x = 0x186A
sll $s0, $s0, 4         # x = 0x186A0
ori $s1, 0x1388         # y = 0x1388
sll $s1,$s1, 4          # y = 0x13880
ori $s2, $zero, 0x61A8  # z = 0x61A8
sll $s2, $s2, 4         # z = 0x61A80


