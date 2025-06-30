.text
.globl main
main:
ori $t0, $zero, 0x7FFF #t0 = 0x7FFF  00007FFF (100000)
sll $t0, $t0, 16       #t0= shift 16  7FFF0000
#lui $t0, 0x7FFF
ori $s0, $t0, 0xFFFF   #x= 0x7FFFFFFF
ori $t0, $zero, 0x493E #t0=0x439E
sll $s1, $t0, 4        #y = 0x439E0       (300000)
sll $t0, $s1, 2        #t0 = y*4
sub $s2, $s0, $t0      #z = x - 4*y