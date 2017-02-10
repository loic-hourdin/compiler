		.data
list_Pascal:	.space	256
dim_Pascal_h:	.word	0
dim_Pascal_w:	.word	0
val_i:	.word	0
val_j:	.word	0
val_t0:	.word	0
val_t1:	.word	0
val_t2:	.word	0
val_t3:	.word	0
val_t4:	.word	0
val_t5:	.word	0
val_t6:	.word	0
val_t7:	.word	0
val_t8:	.word	0
val_t9:	.word	0
val_t10:	.word	0
val_t11:	.word	0
		.text
main:
li $t0, 8
sw $t0, dim_Pascal_h
li $t0, 8
sw $t0, dim_Pascal_w
li $t0, 0
sw $t0, val_i
lab_l5:
li $t0, 0
sw $t0, val_j
lab_l3:
lw $t0, val_i
lw $t1, val_j
beq $t0, $t1, lab_l0 
lw $t0, val_j
li $t1, 0
bne $t0, $t1, lab_l1 
lab_l0:
lw $t0, val_i
lw $t1, dim_Pascal_h
mult $t0, $t1
mflo $t2
sw $t2, val_t0
lw $t0, val_t0
lw $t1, val_j
add $t2, $t0, $t1
sw $t2, val_t0
li $t0, 1
lw $t1, val_t0
la $t2, list_Pascal
add $t1, $t1, $t1
add $t1, $t1, $t1
add $t1, $t1, $t2
sw $t0, 0($t1)
j lab_l2
lab_l1:
lw $t0, val_i
li $t1, 1
sub $t2, $t0, $t1
sw $t2, val_t1
lw $t0, val_t1
lw $t1, dim_Pascal_h
mult $t0, $t1
mflo $t2
sw $t2, val_t2
lw $t0, val_t2
lw $t1, val_j
add $t2, $t0, $t1
sw $t2, val_t2
lw $t2, val_t2
la $t1, list_Pascal
add $t2, $t2, $t2
add $t2, $t2, $t2
add $t2, $t2, $t1
lw $t0, 0($t2)
sw $t0, val_t3
lw $t0, val_i
li $t1, 1
sub $t2, $t0, $t1
sw $t2, val_t4
lw $t0, val_j
li $t1, 1
sub $t2, $t0, $t1
sw $t2, val_t5
lw $t0, val_t4
lw $t1, dim_Pascal_h
mult $t0, $t1
mflo $t2
sw $t2, val_t6
lw $t0, val_t6
lw $t1, val_t5
add $t2, $t0, $t1
sw $t2, val_t6
lw $t2, val_t6
la $t1, list_Pascal
add $t2, $t2, $t2
add $t2, $t2, $t2
add $t2, $t2, $t1
lw $t0, 0($t2)
sw $t0, val_t7
lw $t0, val_t3
lw $t1, val_t7
add $t2, $t0, $t1
sw $t2, val_t8
lw $t0, val_i
lw $t1, dim_Pascal_h
mult $t0, $t1
mflo $t2
sw $t2, val_t9
lw $t0, val_t9
lw $t1, val_j
add $t2, $t0, $t1
sw $t2, val_t9
lw $t0, val_t8
lw $t1, val_t9
la $t2, list_Pascal
add $t1, $t1, $t1
add $t1, $t1, $t1
add $t1, $t1, $t2
sw $t0, 0($t1)
lab_l2:
lw $t0, val_j
lw $t1, val_i
beq $t0, $t1, lab_l4 
lw $t0, val_j
li $t1, 1
add $t2, $t0, $t1
sw $t2, val_j
j lab_l3
lab_l4:
lw $t0, val_i
li $t1, 7
beq $t0, $t1, lab_l6 
lw $t0, val_i
li $t1, 1
add $t2, $t0, $t1
sw $t2, val_i
j lab_l5
lab_l6:
li $t0, 0
sw $t0, val_i
lab_l9:
li $t0, 0
sw $t0, val_j
lab_l7:
lw $t0, val_i
lw $t1, dim_Pascal_h
mult $t0, $t1
mflo $t2
sw $t2, val_t10
lw $t0, val_t10
lw $t1, val_j
add $t2, $t0, $t1
sw $t2, val_t10
lw $t2, val_t10
la $t1, list_Pascal
add $t2, $t2, $t2
add $t2, $t2, $t2
add $t2, $t2, $t1
lw $t0, 0($t2)
sw $t0, val_t11
li $v0, 1
lw $a0, val_t11
syscall
li $a0, 32
li $v0, 11
syscall
lw $t0, val_j
lw $t1, val_i
beq $t0, $t1, lab_l8 
lw $t0, val_j
li $t1, 1
add $t2, $t0, $t1
sw $t2, val_j
j lab_l7
lab_l8:
li $a0, 10
li $v0, 11
syscall
lw $t0, val_i
li $t1, 7
beq $t0, $t1, lab_l10 
lw $t0, val_i
li $t1, 1
add $t2, $t0, $t1
sw $t2, val_i
j lab_l9
lab_l10:
li $a0, 10
li $v0, 11
syscall
li $v0, 10
syscall
