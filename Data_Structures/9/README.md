Project 9 – Problem and Description
The goal of this project was to create a vector of student records (1) and then insert those records into a binary search tree sorted by ID (2). Then I was to search two different nodes that were in the tree and display the result (3), and lastly delete two nodes within the tree (4) and redisplay the tree.

-	For the first part I used code from previous assignments and read in student records from a file using a loop iteration:
-	The second part I then inserted those nodes into a binary search tree using an insert function and looping through the vector. I also created a tree object. The insert function compared them to other values and then inserted the new child in the correct place:
-	The third thing I accomplished was traversing the list with a while loop and determining if or if not the student record was part of the binary search tree. I did this by comparing values to the value wanted to be found. If found I displayed so and then outputted the information to the screen:
-	The last thing I did was I deleted two nodes from the tree and then displayed the result after each deletion:

Test Input and Output
Here are the current Students (ID, Name, GPA, Student Address, 10+ test scores):  

     STUDENT ID  NAME                    GPA   STUDENT ADDRESS          

     33454444     Mike Stiller           3.75 221 Blue St.        Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 66, 77
     69988963     Marcy Eckhert          2.43 953 Ridgeway Rd.    Test Scores: 77, 89, 63, 74, 85, 90, 93, 74, 85, 74, 73, 83
     47763329     Lyndon Johnson         3.45 802 Love Ln.        Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 83, 73
     55584739     Wes Thompson           2.24 839 Hollow Tr.      Test Scores: 92, 93, 74, 85, 74, 99, 91, 83, 92, 77, 83, 73
     13453329     Alex Cortez            3.53 109 Crest St.       Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 88, 93
     45553894     Ben Lyons              3.34 220 Ridge Rd.       Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 73, 83
     59860454     Jimmy Woods            3.77 234 Orange St.      Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 83, 94
     38889643     Christie Mickey        3.45 552 Nickel Rd.      Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 47, 85
     59988963     Stella Esquire         3.33 9595 Colby Rd.      Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 83, 93
     61111339     Joey Gerald            2.46 1393 Mustang Tr.    Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 83, 94
     23897939     Ash Catchum            3.44 1550 Sagewood Tr.   Test Scores: 92, 93, 74, 85, 74, 99, 91, 83, 92, 77, 73, 98
     32498887     Caleb Nesbit           3.33 200 Peach Rd.       Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 88, 77
     66644324     Jackie Wild            2.74 134 Yellow St.      Test Scores: 99, 91, 83, 92, 66, 92, 37, 94, 83, 78, 83, 74
     57688874     Ricky Bobby            3.23 1776 Apple Ln.      Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 73, 83
     12493894     Ryan Marsh             3.23 220 River Rd.       Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 99, 93
     71771132     Michael Batson         1.46 1223 Lina Tr.       Test Scores: 57, 38, 88, 66, 74, 73, 44, 91, 89, 92, 83, 94
     52347499     Lexi Ryan              2.40 729 Wave Rd.        Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 83, 73
     20829499     Beth Marie             3.03 110 Copper Rd.      Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 92, 45
     44445939     Ashley Amigo           2.36 119 Sage Tr.        Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 88, 94
     75779329     Charlie Kowalski       4.00 919 Prarie Tr.      Test Scores: 97, 98, 88, 22, 79, 73, 99, 91, 83, 92, 84, 93

Here is the Binary Tree IN Order (ID, Name, GPA, Student Address, 10+ test scores):  

     STUDENT ID  NAME                    GPA   STUDENT ADDRESS          

     12493894     Ryan Marsh             3.23 220 River Rd.       Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 99, 93
     13453329     Alex Cortez            3.53 109 Crest St.       Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 88, 93
     20829499     Beth Marie             3.03 110 Copper Rd.      Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 92, 45
     23897939     Ash Catchum            3.44 1550 Sagewood Tr.   Test Scores: 92, 93, 74, 85, 74, 99, 91, 83, 92, 77, 73, 98
     32498887     Caleb Nesbit           3.33 200 Peach Rd.       Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 88, 77
     33454444     Mike Stiller           3.75 221 Blue St.        Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 66, 77
     38889643     Christie Mickey        3.45 552 Nickel Rd.      Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 47, 85
     44445939     Ashley Amigo           2.36 119 Sage Tr.        Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 88, 94
     45553894     Ben Lyons              3.34 220 Ridge Rd.       Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 73, 83
     47763329     Lyndon Johnson         3.45 802 Love Ln.        Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 83, 73
     52347499     Lexi Ryan              2.40 729 Wave Rd.        Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 83, 73
     55584739     Wes Thompson           2.24 839 Hollow Tr.      Test Scores: 92, 93, 74, 85, 74, 99, 91, 83, 92, 77, 83, 73
     57688874     Ricky Bobby            3.23 1776 Apple Ln.      Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 73, 83
     59860454     Jimmy Woods            3.77 234 Orange St.      Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 83, 94
     59988963     Stella Esquire         3.33 9595 Colby Rd.      Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 83, 93
     61111339     Joey Gerald            2.46 1393 Mustang Tr.    Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 83, 94
     66644324     Jackie Wild            2.74 134 Yellow St.      Test Scores: 99, 91, 83, 92, 66, 92, 37, 94, 83, 78, 83, 74
     69988963     Marcy Eckhert          2.43 953 Ridgeway Rd.    Test Scores: 77, 89, 63, 74, 85, 90, 93, 74, 85, 74, 73, 83
     71771132     Michael Batson         1.46 1223 Lina Tr.       Test Scores: 57, 38, 88, 66, 74, 73, 44, 91, 89, 92, 83, 94
     75779329     Charlie Kowalski       4.00 919 Prarie Tr.      Test Scores: 97, 98, 88, 22, 79, 73, 99, 91, 83, 92, 84, 93

Enter first Student ID to search for: 66644324

66644324    Jackie Wild  2.74 134 Yellow St.   

Enter first Student ID to search for: 99
Student with ID: 99 cannot be found in the tree.


Enter one Student's ID to delete: 66644324
Here is the Binary Tree IN Order (ID, Name, GPA, Student Address, 10+ test scores):  

     STUDENT ID  NAME                    GPA   STUDENT ADDRESS          

     12493894     Ryan Marsh             3.23 220 River Rd.       Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 99, 93
     13453329     Alex Cortez            3.53 109 Crest St.       Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 88, 93
     20829499     Beth Marie             3.03 110 Copper Rd.      Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 92, 45
     23897939     Ash Catchum            3.44 1550 Sagewood Tr.   Test Scores: 92, 93, 74, 85, 74, 99, 91, 83, 92, 77, 73, 98
     32498887     Caleb Nesbit           3.33 200 Peach Rd.       Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 88, 77
     33454444     Mike Stiller           3.75 221 Blue St.        Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 66, 77
     38889643     Christie Mickey        3.45 552 Nickel Rd.      Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 47, 85
     44445939     Ashley Amigo           2.36 119 Sage Tr.        Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 88, 94
     45553894     Ben Lyons              3.34 220 Ridge Rd.       Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 73, 83
     47763329     Lyndon Johnson         3.45 802 Love Ln.        Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 83, 73
     52347499     Lexi Ryan              2.40 729 Wave Rd.        Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 83, 73
     55584739     Wes Thompson           2.24 839 Hollow Tr.      Test Scores: 92, 93, 74, 85, 74, 99, 91, 83, 92, 77, 83, 73
     57688874     Ricky Bobby            3.23 1776 Apple Ln.      Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 73, 83
     59860454     Jimmy Woods            3.77 234 Orange St.      Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 83, 94
     59988963     Stella Esquire         3.33 9595 Colby Rd.      Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 83, 93
     61111339     Joey Gerald            2.46 1393 Mustang Tr.    Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 83, 94
     69988963     Marcy Eckhert          2.43 953 Ridgeway Rd.    Test Scores: 77, 89, 63, 74, 85, 90, 93, 74, 85, 74, 73, 83
     71771132     Michael Batson         1.46 1223 Lina Tr.       Test Scores: 57, 38, 88, 66, 74, 73, 44, 91, 89, 92, 83, 94
     75779329     Charlie Kowalski       4.00 919 Prarie Tr.      Test Scores: 97, 98, 88, 22, 79, 73, 99, 91, 83, 92, 84, 93

Enter one Student's ID to delete: 52347499     
Here is the Binary Tree IN Order (ID, Name, GPA, Student Address, 10+ test scores):  

     STUDENT ID  NAME                    GPA   STUDENT ADDRESS          

     12493894     Ryan Marsh             3.23 220 River Rd.       Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 99, 93
     13453329     Alex Cortez            3.53 109 Crest St.       Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 88, 93
     20829499     Beth Marie             3.03 110 Copper Rd.      Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 92, 45
     23897939     Ash Catchum            3.44 1550 Sagewood Tr.   Test Scores: 92, 93, 74, 85, 74, 99, 91, 83, 92, 77, 73, 98
     32498887     Caleb Nesbit           3.33 200 Peach Rd.       Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 88, 77
     33454444     Mike Stiller           3.75 221 Blue St.        Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 66, 77
     38889643     Christie Mickey        3.45 552 Nickel Rd.      Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 47, 85
     44445939     Ashley Amigo           2.36 119 Sage Tr.        Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 88, 94
     45553894     Ben Lyons              3.34 220 Ridge Rd.       Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 73, 83
     47763329     Lyndon Johnson         3.45 802 Love Ln.        Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 83, 73
     55584739     Wes Thompson           2.24 839 Hollow Tr.      Test Scores: 92, 93, 74, 85, 74, 99, 91, 83, 92, 77, 83, 73
     57688874     Ricky Bobby            3.23 1776 Apple Ln.      Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 73, 83
     59860454     Jimmy Woods            3.77 234 Orange St.      Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 83, 94
     59988963     Stella Esquire         3.33 9595 Colby Rd.      Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 83, 93
     61111339     Joey Gerald            2.46 1393 Mustang Tr.    Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 83, 94
     69988963     Marcy Eckhert          2.43 953 Ridgeway Rd.    Test Scores: 77, 89, 63, 74, 85, 90, 93, 74, 85, 74, 73, 83
     71771132     Michael Batson         1.46 1223 Lina Tr.       Test Scores: 57, 38, 88, 66, 74, 73, 44, 91, 89, 92, 83, 94
     75779329     Charlie Kowalski       4.00 919 Prarie Tr.      Test Scores: 97, 98, 88, 22, 79, 73, 99, 91, 83, 92, 84, 93