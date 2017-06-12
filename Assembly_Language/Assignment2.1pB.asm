##########################################################################
#
#Paul Habjanetz, CS 2318-002, Assignment 2 Part 1 Program B.
#
#Function Description - Evaluates course score based on 3 exam scores and 
#grading policy.
#
##########################################################################
#
############################ data segment ################################

		.data
exam1:		.asciiz "Enter score for Exam 1: "
exam2:		.asciiz "Enter score for Exam 2: "
finalexam:	.asciiz "Enter score for Final Exam: "
average:	.asciiz "Here is your final score for the class: "


############################ code segment ################################
		.text 
		.globl main

main:

		li $v0, 4
		la $a0, exam1			# prompt for input for exam 1
		syscall
				
		li $v0, 5			# read in input
		syscall
		move $t1, $v0			# save input in temp variable 1
				
		li $v0, 11
		li $a0, '\n' 			# newline spacing
		syscall	

		li $v0, 4
		la $a0, exam2			# prompt for input for exam 2
		syscall
				
		li $v0, 5			# read in input
		syscall
		move $t2, $v0			# save input in temp variabl 2
				
		li $v0, 11
		li $a0, '\n' 			# newline spacing
		syscall	
				
		li $v0, 4
		la $a0, finalexam		# prompt for input for exam 3
		syscall
				
		li $v0, 5			# read in input
		syscall
		move $t3, $v0			# save input in temp variable 3
				
		li $v0, 11
		li $a0, '\n' 			# newline spacing
		syscall	
						
		li $t4, 2558			# load $t4 with constant 2558
		li $t5, 614			# load $t5 with constant 614
		
		
		sll $t1, $t1, 9			# multiply int in $t1 by 512 (= 2^9)		
		div $t1, $t4			# divide int by 2258
		mflo $t1			# move value into lo register
				
		mul $t2, $t2, $t5		# multiply $t2 by 614		
		sra $t2, $t2, 11		# divide by 2048 (= 2^11)
		
				
		sra $t3, $t3, 1			# divide int in $t3 by 2 (=2^1)
				
		add $t3, $t3, $t2		# add $t3 and $t2
		add $t3, $t3, $t1		# add $t3 and $t1
				
		li $v0, 4
		la $a0, average			# print screen about average
		syscall
				
		li $v0, 1
		move $a0, $t3
		syscall				# display final score 	
				
		li $v0, 11
		li $a0, '\n' 			# newline spacing
		syscall	
		
		li $v0, 11
		li $a0, '\n' 			# newline spacing
		syscall	
		
		li $v0, 10 			#exit
		syscall
				   		   
	
				
