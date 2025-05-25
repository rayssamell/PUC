# x = 3; -> s0
# y = 4 ; -> s1
# z = ( 15*x + 67*y)*4  -> s2

.text 
.globl main

#inicio:
main:
ori $s0, $zero, 3 # x=3
ori $s1, $zero, 4 # y=4

sll $t0, $s0, 4    # t0=16x
sub $t0, $t0, $s0  # t0=15x
sll $t1, $s1, 6    

add $t1, $t1, $s1
add $t1, $t1, $s1
add $t1, $t1, $s1
add $t0, $t0, $t1
sll $s2, $t0, 2