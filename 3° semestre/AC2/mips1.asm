# a =2; -> s0
# b =3; -> s1
# c =4; -> s2
# d =5; -> s3
# x = (a+b) - (c+d); -> s4  
# y = a – b + x; -> s5      
# b = x – y;                

.text 
.globl main

main:
addi $s0, $zero, 2  # a = 2
addi $s1, $zero, 3  # b = 3
addi $s2, $zero, 4  # c = 4
addi $s3, $zero, 5  # d = 5
add  $t0, $s0, $s1  # t0 = a + b
add  $t1, $s2, $s3  # t1 = c + d 
sub  $s4, $t0, $t1  # x = t0 - t1
sub  $t0, $s0, $s1  # t0 = a - b
add  $s5, $t0, $s4  # y = t0 + x
sub  $s1, $s4, $s5  # b = x - y   