########################################################################## 
# Title:Assignment 2 			Author: Paul Habjanetz
# Class: CS2318-751	Due: 07/22/2013		Submitted:07/22/2013 

############################ data segment ################################

			.data
prompt1: 		.asciiz "Enter an integer: " 
prompt2: 		.asciiz "Enter a string up to 80 characters: " 
prompt3: 		.asciiz "Enter a character: " 
output1:		.asciiz "This is your integer:  "
output2:		.asciiz "This is your string:  " 
output3:		.asciiz "This is your character:  " 
newline: 		.asciiz "\n" 
input:			.space 80 # array of 80 bytes


#Part.C

intar:			.word 11, 22, 33, 44, 55 # int intar[5] = {11, 22, 33, 44, 55} 
intword1:		.asciiz "Values in array are: "	
intword2:		.asciiz "Values in array after swapping are: "	

############################ code segment ################################
			.text 
			.globl main

main:

##########################################################################
#
#Paul Habjanetz, CS 2318-751, Assignment 2 Part 1 Program A.
#
#Description - Read integer, string, and character and output the input
##########################################################################

#A.integer
						
			li $v0, 4 	#print prompt1 string
			la $a0, prompt1 #$a0 = address of prompt1 string
			syscall
			
			addi $v0, $0, 5 #read in int
			syscall
			
			move $t0, $v0 	# save int to temporary
			li $v0, 4
			la $a0, output1 #output "This is your integer: "
			syscall	
			
			li $v0, 1
			move $a0, $t0 	#print integer to screen
			syscall	
			
			li $v0, 11
			li $a0, '\n' 	#newline spacing
			syscall
			
			li $v0, 11
			li $a0, '\n' 	#newline spacing
			syscall
			
#A.string	


			li $v0, 4 	#print prompt2 string
			la $a0, prompt2 #$a0 = address of prompt2 string
			syscall  
			
			la $a0, input 	#$a0 = input buffer address
			li $a1, 80 	#$a1 = input buffer size
			li $v0, 8 	#read input string
			syscall 

			li $v0, 4 	#print output2 string
			la $a0, output2 #$a0 = address of output2 string 
			syscall
			
			li $v0, 4  	#print input string
			la $a0, input 	#$ao = address of input string
			syscall
			
			li $v0, 4  	#print newline string
			la $a0, newline #$a0 = address of newline string
			syscall
			
			
#A.Character

			li $v0, 4            
       			la $a0, prompt3 #Prints prompt3 to enter a character
       			syscall



			li $v0, 12 	#read in input
			syscall 	#pass to system
			
			move $t0, $v0	# save character in temporary
			li $v0, 11
			li $a0, '\n' 	#newline spacing
			syscall
			
			li $v0, 4 	#print output3 string
			la $a0, output3 #$a0 = address of output3 string 
			syscall
		

			li $v0, 11
			move $a0, $t0 	#print saved character
			syscall
			
			
			li $v0, 11
			li $a0, '\n' 	#newline spacing
			syscall
			
			li $v0, 11
			li $a0, '\n' 	#newline spacing
			syscall	


##########################################################################
#
#Paul Habjanetz, CS 2318-751, Assignment 2 Part 1 Program C.
#
#Description - Declare global array and then swap order and output to screen
##########################################################################

			li $v0, 4
			la $a0, intword1	#print "Values of array are: "
			syscall	
			
			li $v0, 1
			la $t0, intar 		# print value of an element of ia
			lw $a0, 0($t0)		# cout << ia[0]
			syscall
			
			li $v0, 11		
			li $a0, ','		#put comma between values
			syscall
			
			li $v0, 1
			la $t0, intar
			lw $a0, 4($t0)		# cout << ia[1]
			syscall
			
			li $v0, 11
			li $a0, ','		#put comma between values
			syscall
			
			li $v0, 1
			la $t0, intar 
			lw $a0, 8($t0)		# cout << ia[2]	
			syscall
			
			li $v0, 11
			li $a0, ','		#put comma between values
			syscall
			
			li $v0, 1
			la $t0, intar 
			lw $a0, 12($t0)		# cout << ia[3]
			syscall
			
			li $v0, 11
			li $a0, ','		#put comma between values
			syscall
			
			li $v0, 1
			la $t0, intar 
			lw $a0, 16($t0)		# cout << ia[4]
			syscall
			
			li $v0, 11
			li $a0, '\n' 		#newline spacing
			syscall
			
			
			li $v0, 4
			la $a0, intword2	#print "Values of array after swapping are: "
			syscall	
			
			lw $t1, 0($t0)
			lw $t2, 16($t0)
			sw $t1, 16($t0)
			sw $t2, 0($t0)		#swap 1st and 5th elements of intar
			
			lw $t3, 4($t0)
			lw $t4, 12($t0)
			sw $t3, 12($t0)
			sw $t4, 4($t0)		#swap 2nd and 4th elements of intar
			
			li $v0, 1
			la $t0, intar 		#print value of an element of ia
			lw $a0, 0($t0)		#cout << ia[0]
			syscall
			
			li $v0, 11		
			li $a0, ','		#put comma between values
			syscall
			
			li $v0, 1
			la $t0, intar
			lw $a0, 4($t0)		# cout << ia[1]
			syscall
			
			li $v0, 11
			li $a0, ','		#put comma between values
			syscall
			
			li $v0, 1
			la $t0, intar 
			lw $a0, 8($t0)		# cout << ia[2]	
			syscall
			
			li $v0, 11
			li $a0, ','		#put comma between values
			syscall
			
			li $v0, 1
			la $t0, intar 
			lw $a0, 12($t0)		# cout << ia[3]
			syscall
			
			li $v0, 11
			li $a0, ','		#put comma between values
			syscall
			
			li $v0, 1
			la $t0, intar 
			lw $a0, 16($t0)		# cout << ia[4]
			syscall
			
			li $v0, 11
			li $a0, '\n' 		#newline spacing
			syscall
			
			
			li $v0, 10 #exit
			syscall
