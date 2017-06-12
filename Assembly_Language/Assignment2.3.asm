#include <iostream>
#using namespace std;

#int a1[11],
#    a2[11],
#    a3[11];
			.data
iArr1:			.space 44
iArr2:			.space 44
iArr3:			.space 44
			
einPrompt:		.asciiz "\nEnter integer #: "
colSpace:		.asciiz ": "
maxMsg:			.asciiz "Max of 11 ints entered..."
emPrompt:		.asciiz "Enter more ints? (n or N = no, others = yes) "
a1Msg:		        .asciiz "\nbeginning a1: "
proMsg:			.asciiz "\nprocessed a1: "
sp1Msg:			.asciiz "          a2: "  
sp2Msg:			.asciiz "          a3: "  
endPrompt:		.asciiz "Do another case? (n or N = no, others = yes) "
line:			.asciiz "================================\n"
bye:			.asciiz "bye...\n"

#int main()
#{

			.text
			.globl main
		
main:

########################################
# Register Usage
########################################
# $t0: short-lived temporary
# $t1: used1
# $t2: used2
# $t3: used3
# $t4: hopPtr1
# $t5: hopPtr11
# $t6: hopPtr2
# $t7: hopPtr22
# $t8: hopPtr222
# $t9: hopPtr3

# $v1: reply

# $a2: remCount
# $a3: anchor

# $s0: endPtr1
# $s1: endPtr2
# $s2: endPtr3

########################################

#            char reply;
#            int used1,
#                used2,
#                used3,
#                remCount,
#                anchor;
#            int* hopPtr1;
#            int* hopPtr11;
#            int* hopPtr2;
#            int* hopPtr22;
#            int* hopPtr222;
#            int* hopPtr3;
#            int* endPtr1;
#            int* endPtr2;
#            int* endPtr3;


begWBody1:
#            used1 = 0;
             li $t1, 0
             
#            hopPtr1 = a1;
	     la $t4, iArr1
	     	
begWBody2:
#            cout << "Enter integer #" << (used1 + 1) << ": ";
	     li $v0, 4
	     la $a0 einPrompt
	     syscall
	     li $v0, 1
	     addi $a0, $t1, 1
	     syscall
	     li $v0, 4
   	     la $a0, colSpace
	     syscall
	     
#            cin >> *hopPtr1;
	     li $v0, 5
	     syscall
	     move $t4, $v0
             

#            ++used1;
	     addi $t1, $t1, 1
#      	     ++hopPtr1;
  	     addi, $t4, $t4, 4
			
#            if (used1 != 11) goto Else1;
	     li $t0, 11
	     bne $t1, $t0, Else1
	     
begIf1:

#	     cout << "Odd value entered... 1 added to evenize..." << endl;
	     li $v0, 4
	     la $a0, maxMsg
	     syscall
             
#            cout << "Max of 11 ints entered..." << endl;
	     li $v0, 4
	     la $a0, maxMsg
	     syscall
	     
	     li $v0, 11
	     li $a0, '\n'
	     syscall
	     
#	     reply = 'n';
	     li $v1, 'n'
#            goto endIf1;
	     j endIf1
	     
Else1:
#            cout << "Enter more ints? (n or N = no, others = yes) ";
  	     li $v0, 4
	     la $a0, emPrompt
	     syscall
	     
#            cin >> reply;
	     li $v0, 12
	     syscall
     	     move $v1, $v0

endIf1:

WTest2:
#            if (reply != 'n' && reply != 'N') goto begWBody2;

	     li $t0, 'n'
	     beq $v1, $t0, xitDW2
	     li $t0, 'N'
	     bne $v1, $t0, begWBody2
xitDW2:	     

#            cout << "beginning a1: ";
	     li $v0, 4
	     la $a0, a1Msg
	     syscall

#            endPtr1 = a1 + used1;
             la $t0, iArr1
             sll $s0, $t1, 2
             add $s0, $s0, $t0
             
#            hopPtr1 = a1;
	     la $t4, iArr1
             
#            goto FTest1;
     	     j FTest1
             
begFBody1:
#            if (hopPtr1 != endPtr1 - 1) goto Else2;
	     addi $t0, $s0, -4
	     bne $t4, $t0, Else2                
             
begIf2:
#            cout << *hopPtr1 << endl;
	     li $v0, 1
	     lw $a0, 0($t4)
	     syscall
	     
	     li $v0, 11
	     li $a0, 'n'
	     syscall
             
#            goto endIf2; 
             j endIf2
Else2:
#            cout << *hopPtr1 << ' ';
	     li $v0, 1
	     lw $a0, 0($t4)
	     syscall
	     
	     li $v0, 11
	     li $a0, ' '
	     syscall
             
endIf2:
#            ++hopPtr1; ////
  	     addi, $t4, $t4, 4
  	     
FTest1:
#            if (hopPtr1 < endPtr1) goto begFBody1;
	     blt $t4, $s0, begFBody1
             
#            hopPtr1 = a1; ////
	     la $t4, iArr1
	     
#            hopPtr2 = a2; ////
             la $t6, iArr2
             
#            used2 = 0;    ////
             li $t2, 0
             
#            goto FTest2;
             j FTest2

begFBody2:
#           *hopPtr2 = *hopPtr1;
             move $t6, $t4
             
#            ++hopPtr1; ////
             addi, $t4, $t4, 4
             
#            ++hopPtr2; ////
             addi, $t6, $t6, 4
            
#            ++used2;   ////
             addi, $t2, $t2, 1
             syscall
              
FTest2:
#            if (hopPtr1 < endPtr1) goto begFBody2;
	     blt $t4, $s0, begFBody2           

#            endPtr2 = a2 + used2;
             la $t0, iArr2
             sll $s1, $t2, 2
             add $s1, $s1, $t0
             syscall
             
#            hopPtr2 = a2;
             la $t6, iArr2
             
#            goto FTest3;
             j FTest3
             
begFBody3:
#            anchor = *hopPtr2;
             move $a3, $t6
             
#            hopPtr22 = hopPtr2 + 1;
             addi $t7, $t6, 1
             
#            goto FTest4;
 	     j FTest4
             
begFBody4:
#            if (*hopPtr22 != anchor) goto endIf3;
             bne $t7, $a3, endIf3                
             
begIf3:
#            hopPtr222 = hopPtr22 + 1;
             addi $t8, $t7, 4
#            goto FTest5;
             j FTest5
             
begFBody5:
#            *(hopPtr222 - 1) = *hopPtr222;
	     move $t0, $t8
             addi $t8, $t8, -4
             syscall
             move $t8, $t0
             
#            ++hopPtr222; ////
             addi $t8, $t8, 4
             
FTest5:
#            if (hopPtr222 < endPtr2) goto begFBody5;
	     blt $t8, $s1, begFBody5
             
#            --used2;
             addi $t2, $t2, -1
#            --endPtr2;
             addi $s1, $s1, -4
#            --hopPtr22;
             addi $t7, $t7, -4
             
endIf3:
#            ++hopPtr22;
             addi $t7, $t7, 4
             
FTest4:
#            if (hopPtr22 < endPtr2) goto begFBody4;
             blt $t7, $s1, begFBody4
             
#            ++hopPtr2; ////
             addi $t6, $t6, 4
             
FTest3:
#            if (hopPtr2 < endPtr2) goto begFBody3;
             blt $t6, $s1, begFBody3
             
#            used3 = 0;
             li $t3, 0
#            hopPtr3 = a3;
             la $t9, iArr3
#            hopPtr1 = a1;
             la $t4, iArr1
#            goto WTest3;
             j WTest3
             
begWBody3:
#            *hopPtr3 = *hopPtr1;
             move $t9, $t4
             
#            ++used3;
	     addi $t3, $t3, 1
#            ++hopPtr3;
             addi $t9, $t9, 4
#            anchor = *hopPtr1;
 	     move $a3, $t4
#            remCount = 0;
             li $a2, 0
#            hopPtr11 = hopPtr1 + 1;
             addi $t5, $t4, 4
#            goto FTest6;
             j FTest6
             
begFBody6:
#            if (*hopPtr11 != anchor) goto Else4;
	     bne $t5, $a3, Else4 
	     
begIf4:
#            ++remCount;
             addi $a2, $a2, 1
             
#            goto endIf4; ////
             j endIf4
             
Else4:
#            *(hopPtr11 - remCount) = *hopPtr11;
             
	     move $t0, $t5
             sub $t5, $t5, $a2
             syscall
             move $t5, $t0          
endIf4:
#            ++hopPtr11; ////
             addi $t5, $t5, 4
FTest6:
#            if (hopPtr11 < endPtr1) goto begFBody6;
	     blt $t5, $s0, begFBody6
	     
#            used1 -= remCount;
             sub $t1, $t1, $a2
#            endPtr1 -= remCount;
             sub $s0, $s0, $a2        
#            ++hopPtr1;
             addi $t4, $t4, 4
             
WTest3:
#            if (hopPtr1 < endPtr1) goto begWBody3;
	     blt $t4, $s0, begWBody3
	     
#            cout << "processed a1: ";
             li $v0, 4
	     la $a0 proMsg
	     syscall
	     
#            hopPtr1 = a1;
	     la $t4, iArr1
#            goto FTest7;
             j FTest7
             
begFBody7:
#            if (hopPtr1 != endPtr1 - 1) goto Else5;
             addi $t0, $s0, -4
	     bne $t4, $t0, Else5       
             
begIf5:
#            cout << *hopPtr1 << endl;
             li $v0, 1
	     lw $a0 0($t4)
	     syscall	
	     li $v0, 11
	     li $a0, '\n'
	     syscall
			
#            goto endIf5; ////
             j endIf5
             
Else5:
#            cout << *hopPtr1 << ' ';
             li $v0, 1
	     lw $a0, 0($t4)
	     syscall
	     li $v0, 11
	     li $a0, ' '
	     syscall
	     
endIf5:
#            ++hopPtr1; ////
             addi $t4, $t4, 4
             
FTest7:
#            if (hopPtr1 < endPtr1) goto begFBody7;
             blt $t4, $s0, begFBody7

#            cout << "          a2: ";
             li $v0, 4
	     la $a0, sp1Msg
	     syscall
	   
#            hopPtr2 = a2;
             la $t6, iArr2
             
#            goto FTest8;
             j FTest8
             
begFBody8:
#            if (hopPtr2 != endPtr2 - 1) goto Else6;
             addi $t0, $s1, -4
	     bne $t6, $t0, Else6  
             
begIf6:
#            cout << *hopPtr2 << endl;
             li $v0, 1
	     lw $a0 0($t6)
	     syscall	
	     li $v0, 11
	     li $a0, '\n'
	     syscall
            
#            goto endIf6; ////
             j endIf6
             
Else6:
#            cout << *hopPtr2 << ' ';
             li $v0, 1
	     lw $a0, 0($t6)
	     syscall
	     li $v0, 11
	     li $a0, ' '
	     syscall
	               
endIf6:
#            ++hopPtr2; ////
             addi $t6, $t6, 4
             
FTest8:
#            if (hopPtr2 < endPtr2) goto begFBody8;
             blt $t6, $s1, begFBody8
             
#            cout <<"          a3: ";
             li $v0, 4
	     la $a0, sp2Msg
	     syscall
	     
#            endPtr3 = a3 + used3;
	     la $t0, iArr3
	     sll $s2, $t3, 2
	     add $s2, $s2, $t0
#            hopPtr3 = a3;
             la $t9, iArr3
#            goto FTest9;
             j FTest9
             
begFBody9:
#            if (hopPtr3 != endPtr3 - 1) goto Else7;
             addi $t0, $s2, -4
	     bne $t9, $t0, Else7
	       
begIf7:
#            cout << *hopPtr3 << endl;
             li $v0, 1
	     lw $a0 0($t9)
	     syscall
	     	
	     li $v0, 11
	     li $a0, '\n'
	     syscall
	     
#            goto endIf7;
             j endIf7
             
Else7:
#            cout << *hopPtr3 << ' ';
             li $v0, 1
	     lw $a0 0($t9)
	     syscall
	     	
	     li $v0, 11
	     li $a0, ' '
	     syscall
endIf7:
#            ++hopPtr3; ////
             addi $t9, $t9, 4
FTest9:
#            if (hopPtr3 < endPtr3) goto begFBody9;
             blt $t9, $s2, begFBody9

#            cout << "Do another case? (n or N = no, others = yes) ";
             li $v0, 4
	     la $a0 endPrompt
	     syscall

#            cin >> reply; 	     
	     li $v0, 12
	     syscall
	     move $v1, $v0

WTest1:
#            if (reply != 'n' && reply != 'N') goto begWBody1;
 	     li $t0, 'n'
	     bne $v1, $t0, xitDW1
	     li $t0, 'N'
	     bne $v1, $t0, begWBody1
	     
xitDW1:

#            cout << "================================" << endl;
             li $v0, 4
	     la $a0 line
	     syscall
#            cout << "bye..." << endl;
             li $v0, 4
	     la $a0 bye
	     syscall
#            cout << "================================" << endl;
             li $v0, 4
	     la $a0 line
	     syscall

#            return 0;
             li $v0, 10
	     syscall
             
#}
