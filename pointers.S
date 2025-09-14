 # pointers.S
 # By David Broman, 2015-09-14
 # Ported 2024/??/?? by W Szczerek (from MIPS to RISC-V)
 # This file is in the public domain


# Choose the syntax for RARS or DTEK-V board.
# The syntax for RARS is probably due to its MIPS heritage.
###################
# Macros for RARS #
###################
.macro	PUSH (%reg)
	addi	sp,sp,-4
	sw	%reg,0(sp) 
.end_macro

.macro	POP (%reg)
	lw	%reg,0(sp)
	addi	sp,sp,4
.end_macro
###################
# Macros for DTEK #
###################
#.macro	PUSH reg
#	addi sp,sp,-4
#	sw \reg,0(sp) 
#.endm

#.macro	POP reg
#	lw	\reg,0(sp)
#	addi	sp,sp,4
#.endm
###################

	.data
text1: 	  .asciz "This is a string."
text2:	  .asciz "Yet another thing."

	.align 2
list1: 	.space 80
list2: 	.space 80
counter:.word  0

	.text
	.globl main
	.type main, @function
main:
	jal	work
stop:	j	stop

# function work()
work:
# Create pointers to the strings and the lists.
# Call copycodes() twice, once for each string/list pair.
# After each call, the variable "counter" should contain
# the number of characters copied so far.
	PUSH	ra
	la 	a0,text1
	la	a1,list1
	la	a2,counter
	jal	copycodes
	
	la 	a0,text2
	la	a1,list2
	la	a2,counter
	jal	copycodes  
	POP	ra. 
	jr	ra
	
	
# function copycodes()
copycodes:
loop:
	lb	t0,0(a0)	 
	beqz	t0,done
	sw	t0,0(a1). 

	addi	a0,a0,1
	addi	a1,a1,4
	
	lw	t1,0(a2)
	addi	t1,t1,1
	sw	t1,0(a2)
	j	loop
done:
	jr	ra
		



