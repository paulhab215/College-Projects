##########################################################################
# Paul Habjanetz, CS 2318-002, Assignment 2 Part 1 Program D
############################ data segment ################################
		.data
legend1:	.asciiz "0: less than 32\n"
legend2:	.asciiz "1: 32 or higher\n"
inPrompt:	.asciiz "Enter an integer between 0 and 255: "
outLab:		.asciiz "It is "
############################ code segment ################################
		.text
		.globl main
main:
		li $v0, 4
		la $a0, legend1        
		syscall                   # print legend line 1
		la $a0, legend2        
		syscall                   # print legend line 2
		la $a0, inPrompt        
		syscall                   # print input prompt
		
		li $v0, 5
		syscall                   # read input integer

		##########################################################
		# Write NO MORE THAN 14 lines of code that involve using 
		# ONLY the following:
		# - syscall
		# - syscall supporting instructions (e.g.: li to load $v0)
		# - instruction to make a saved copy
		# - bit manipulating instructions (ANDing, ORing, XORing,
		#   NORing and shifting - only whatever that are needed)
		# so that the program will work just like the sample runs 
		# shown at the bottom.
		# You MUST test your completed program for AT LEAST the 
		# test cases shown (and include the result in hardcopy).
		##########################################################
		
		
		move $t0, $v0		# Moves value into temporary
		
		li $v0, 4
		la $a0, outLab		# Outputs OutLab to screen
		syscall
		
		li $t1, 0		# load $t1 with constant 0
		li $t2, 1		# load $t2 with constant 1
		
		andi $t0, $t0, 0xE0	# Compare # to 11100000
		
		bgtz $t0, else		# Branch to else if it is 32 or greater
		
		move $t0, $t1		# move $t1 into $t0
		j endif			# jump to end
		
else:		
		move $t0, $t2		# move $t2 into $t0

endif:			
	
		li $v0, 1
		move $a0, $t0		# display 1 or 0 based on # 
		syscall				 		
		
		
                ##########################################################
                                
                li $v0, 10               # exit
                syscall

########################## sample test runs ##############################
# 0: less than 32
# 1: 32 or higher
# Enter an integer between 0 and 255: 0
# It is 0
# -- program is finished running --
# 
# 
# Reset: reset completed.
# 
# 0: less than 32
# 1: 32 or higher
# Enter an integer between 0 and 255: 31
# It is 0
# -- program is finished running --
# 
# 
# Reset: reset completed.
# 
# 0: less than 32
# 1: 32 or higher
# Enter an integer between 0 and 255: 32
# It is 1
# -- program is finished running --
# 
# 
# Reset: reset completed.
# 
# 0: less than 32
# 1: 32 or higher
# Enter an integer between 0 and 255: 64
# It is 1
# -- program is finished running --
# 
# 
# Reset: reset completed.
# 
# 0: less than 32
# 1: 32 or higher
# Enter an integer between 0 and 255: 128
# It is 1
# -- program is finished running --
# 
# 
# Reset: reset completed.
# 
# 0: less than 32
# 1: 32 or higher
# Enter an integer between 0 and 255: 255
# It is 1
# -- program is finished running --
######################## end sample test runs ############################
