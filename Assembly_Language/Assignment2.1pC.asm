##########################################################################
#
#Paul Habjanetz, CS 2318-002, Assignment 2 Part 1 Program C.
#
#Description - Declare global array and then swap order and output to screen
##########################################################################
#
########################### data segment #################################

			.data
intar:			.word 111, 222, 333, 444, # int intar[4] = {111, 222, 333, 444} 
intword1:		.asciiz "Values in array are: "	
intword2:		.asciiz "Values in array after swapping are: "	
commaspace:		.asciiz ", "

############################ code segment ################################

			.text 
			.globl main

main:

			li $v0, 4
			la $a0, intword1	#print "Values of array are: "
			syscall	
			
			li $v0, 1
			la $t0, intar 		# print value of an element of ia
			lw $a0, 0($t0)		# cout << ia[0]
			syscall
			
			li $v0, 4
			la $a0, commaspace	#print ", "
			syscall	
			
			li $v0, 1
			la $t0, intar
			lw $a0, 4($t0)		# cout << ia[1]
			syscall
			
			li $v0, 4
			la $a0, commaspace	#print ", "
			syscall	
			
			li $v0, 1
			la $t0, intar 
			lw $a0, 8($t0)		#cout << ia[2]	
			syscall
			
			li $v0, 4
			la $a0, commaspace	#print ", "
			syscall	
			
			
			li $v0, 1
			la $t0, intar 
			lw $a0, 12($t0)		#cout << ia[3]
			syscall
			
			li $v0, 11
			li $a0, '\n' 		#newline spacing
			syscall
			
			
			li $v0, 4
			la $a0, intword2	#print "Values of array after swapping are: "
			syscall	
			
			lw $t1, 0($t0)
			lw $t2, 8($t0)
			sw $t1, 8($t0)
			sw $t2, 0($t0)		#swap 1st and 5th elements of intar
			
			lw $t3, 4($t0)
			lw $t4, 12($t0)
			sw $t3, 12($t0)
			sw $t4, 4($t0)		#swap 2nd and 4th elements of intar
			
			li $v0, 1
			la $t0, intar 		#print value of an element of ia
			lw $a0, 0($t0)		#cout << ia[0]
			syscall
			
			li $v0, 4
			la $a0, commaspace	#print ", "
			syscall	
			
			li $v0, 1
			la $t0, intar
			lw $a0, 4($t0)		#cout << ia[1]
			syscall
			
			li $v0, 4
			la $a0, commaspace	#print ", "
			syscall	
			
			
			li $v0, 1
			la $t0, intar 
			lw $a0, 8($t0)		#cout << ia[2]	
			syscall
			
			li $v0, 4
			la $a0, commaspace	#print ", "
			syscall	
			
			li $v0, 1
			la $t0, intar 
			lw $a0, 12($t0)		#cout << ia[3]
			syscall
			
			li $v0, 11
			li $a0, '\n' 		#newline spacing
			syscall
			
			
			li $v0, 10 		#exit
			syscall
