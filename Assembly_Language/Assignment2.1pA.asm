##########################################################################
#
#Paul Habjanetz, CS 2318-002, Assignment 2 Part 1 Program A.
#
#Description - Read integer, string, and single char and ouput accordingly
##########################################################################
#
########################### data segment #################################

			.data
prompt1: 		.asciiz "Enter an integer: " 
prompt2: 		.asciiz "Enter a string up to 80 characters: " 
prompt3: 		.asciiz "Enter a character: " 
output1:		.asciiz "This is your integer:  "
output2:		.asciiz "This is your string:  " 
output3:		.asciiz "This is your character:  " 
newline: 		.asciiz "\n" 
input:			.space 80 # array of 80 bytes


############################ code segment ################################

			.text 
			.globl main

main:

#A.integer
						
			li $v0, 4 	#print prompt1 string
			la $a0, prompt1 #$a0 = address of prompt1 string
			syscall
			
			addi $v0, $0, 5 #read in int
			syscall
			
			move $t0, $v0 	#save int to temporary
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
       			la $a0, prompt3 #prints prompt3 to enter a character
       			syscall



			li $v0, 12 	#read in input
			syscall 	#pass to system
			
			move $t0, $v0	#save character in temporary
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
			
			li $v0, 10 `	#exit
			syscall
