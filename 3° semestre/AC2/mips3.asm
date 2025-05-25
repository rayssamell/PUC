# x = 3; -> s0
# y = 4 ; -> s1
# z = ( 15*x + 67*y)*4  -> s2

.text
.globl main

main:
addi $s0, $zero, 3    # x = 3
addi $s1, $zero, 4    # y = 4

add $t0, $s0, $s0    # t0 = 2*x
add $t0, $t0, $t0    # t0 = 4*x
add $t0, $t0, $s0    # t0 = 5*x
add $t1, $t0, $t0    # t1 = t0 + t0
add $t0, $t0, $t1    # t0 = t1 + t0

add $t1, $s1, $s1    # t1 = 2*y
add $t1, $t1, $t1    # t1 = 4*y
add $t1, $t1, $t1    # t1 = 8*y
add $t1, $t1, $t1    # t1 = 16*y
addi $t1, $t1, 3     # t1 = t1 + 3
add $t1, $t1, $t1    # t1 = 2*t1
add $t1, $t1, $t1    # t1 = 3*t1

add $t0, $t0, $t1   # t0 = t0 + t1
add $t0, $t0, $t0   # t0 = 2*t0
add $s2, $t0, $t0   # s2 = 3*t0

