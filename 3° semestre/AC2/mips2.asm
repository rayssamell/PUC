# x = 1; -> s0
# y = 5*x + 15; -> s1

.text
.globl main

main:
addi $s0, $zero, 1   # x = 1
add  $t0, $s0, $s0   # t0 = 2*x
add  $t0, $t0, $s0   # t0 = 3*x
add  $t0, $t0, $s0   # t0 = 4*x
add  $t0, $t0, $s0   # t0 = 5*x
addi $t1, $zero, 15  # t1 = 15
add $s1, $t0, $t1   # y = t0 + t1 