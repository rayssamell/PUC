.text
.globl main
main:
ori $t8, $zero, 0x01  # $t8 = 0x00000001
sll $t8, $t8, 31      # $t8 = 0x80000000
sra $t8, $t8, 31      # $8 = 0xFFFFFFFF


