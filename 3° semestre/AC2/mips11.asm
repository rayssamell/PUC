#  y = x – z + 300000
# y-> s0  x->s1  z->s2

.text
.globl main
main:
lui $t0, 0x1001     #t0 = 0x10010000
lw  $s1, 0 ($t0)     # s1 = MEM[0+t0]
lw  $s2, 4 ($t0)     # s2 = MEM[4+t0]
sub $t1, $s1, $s2   # t1 = x - z
ori $t2, $zero, 0x493E #t2=0x439E
sll $t2, $t2, 4        #t2 = 0x439E0 (300000)
add $s0, $t2, $t1      # y = t2 + t1
sw  $s0, 8 ($t0)     # MEM[8+t0] = z

.data
x: .word 100000
z: .word 200000
y: .word 0