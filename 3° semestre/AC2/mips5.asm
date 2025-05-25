.text
.globl main
main:
ori $t0, $zero, 0x186A   #t0 = 0x186A 100000
sll $s0, $t0, 4          #x=0x186A0
ori $t0, $zero, 0x30D4   #t0=0x30D4 
sll $s1, $t0, 4          #y=0x30D40  200000
add $s2, $s0, $s1        #z=x+y