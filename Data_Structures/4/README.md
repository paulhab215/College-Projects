Project 4 – Problem and Description

In project 4 we were to create a vector of student records with 10 + test scores (1), and then use a recursive binary search to search one ID in the vector (2) and then search again for an ID that is not in the vector (3). 

-	For the first portion of the assignment I read information in from a file using a loop and then pushed each individual structure into a vector of structs:
-	For the second portion of the assignment I created a search function that halved places of the vector and determined if the number was higher or lower or equal to the ID number that was in the halved location. Upon determination it would continue to halve the vector by recursively calling itself and checking the halved value – calling higher or lower depending on the value:
-	For the final portion if there was an ID not in the vector I displayed an error message to the screen.

Test Input and Output
Here are the current Students (ID, Name, GPA, Student Address, 10 test scores):  

     STUDENT ID  NAME                    GPA   STUDENT ADDRESS          

     33454444     Mike Stiller           3.75   221 Blue St.            Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 66, 77, 
     69988963     Marcy Eckhert          2.43   953 Ridgeway Rd.        Test Scores: 77, 89, 63, 74, 85, 90, 93, 74, 85, 74, 73, 83, 
     47763329     Lyndon Johnson         3.45   802 Love Ln.            Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 83, 73, 
     55584739     Wes Thompson           2.24   839 Hollow Tr.          Test Scores: 92, 93, 74, 85, 74, 99, 91, 83, 92, 77, 83, 73, 
     13453329     Alex Cortez            3.53   109 Crest St.           Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 88, 93, 
     45553894     Ben Lyons              3.34   220 Ridge Rd.           Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 73, 83, 
     59860454     Jimmy Woods            3.77   234 Orange St.          Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 83, 94, 
     38889643     Christie Mickey        3.45   552 Nickel Rd.          Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 47, 85, 
     59988963     Stella Esquire         3.33   9595 Colby Rd.          Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 83, 93, 
     61111339     Joey Gerald            2.46   1393 Mustang Tr.        Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 83, 94, 
     23897939     Ash Catchum            3.44   1550 Sagewood Tr.       Test Scores: 92, 93, 74, 85, 74, 99, 91, 83, 92, 77, 73, 98, 
     32498887     Caleb Nesbit           3.33   200 Peach Rd.           Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 88, 77, 
     66644324     Jackie Wild            2.74   134 Yellow St.          Test Scores: 99, 91, 83, 92, 66, 92, 37, 94, 83, 78, 83, 74, 
     57688874     Ricky Bobby            3.23   1776 Apple Ln.          Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 73, 83, 
     12493894     Ryan Marsh             3.23   220 River Rd.           Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 99, 93, 
     71771132     Michael Batson         1.46   1223 Lina Tr.           Test Scores: 57, 38, 88, 66, 74, 73, 44, 91, 89, 92, 83, 94, 
     52347499     Lexi Ryan              2.4    729 Wave Rd.            Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 83, 73, 
     20829499     Beth Marie             3.03   110 Copper Rd.          Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 92, 45, 
     44445939     Ashley Amigo           2.36   119 Sage Tr.            Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 88, 94, 
     75779329     Charlie Kowalski       4      919 Prarie Tr.          Test Scores: 97, 98, 88, 22, 79, 73, 99, 91, 83, 92, 84, 93, 

Enter the Student ID you wish to search for: 61111339


Here is your Student - found through Binary Recursion: 

     STUDENT ID  NAME                    GPA   STUDENT ADDRESS          

     61111339     Joey Gerald            2.46   1393 Mustang Tr.        Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 83, 94,



Test 2
Here are the current Students (ID, Name, GPA, Student Address, 10 test scores):  

     STUDENT ID  NAME                    GPA   STUDENT ADDRESS          

     33454444     Mike Stiller           3.75   221 Blue St.            Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 66, 77, 
     69988963     Marcy Eckhert          2.43   953 Ridgeway Rd.        Test Scores: 77, 89, 63, 74, 85, 90, 93, 74, 85, 74, 73, 83, 
     47763329     Lyndon Johnson         3.45   802 Love Ln.            Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 83, 73, 
     55584739     Wes Thompson           2.24   839 Hollow Tr.          Test Scores: 92, 93, 74, 85, 74, 99, 91, 83, 92, 77, 83, 73, 
     13453329     Alex Cortez            3.53   109 Crest St.           Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 88, 93, 
     45553894     Ben Lyons              3.34   220 Ridge Rd.           Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 73, 83, 
     59860454     Jimmy Woods            3.77   234 Orange St.          Test Scores: 99, 91, 83, 92, 94, 92, 97, 94, 93, 78, 83, 94, 
     38889643     Christie Mickey        3.45   552 Nickel Rd.          Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 47, 85, 
     59988963     Stella Esquire         3.33   9595 Colby Rd.          Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 83, 93, 
     61111339     Joey Gerald            2.46   1393 Mustang Tr.        Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 83, 94, 
     23897939     Ash Catchum            3.44   1550 Sagewood Tr.       Test Scores: 92, 93, 74, 85, 74, 99, 91, 83, 92, 77, 73, 98, 
     32498887     Caleb Nesbit           3.33   200 Peach Rd.           Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 88, 77, 
     66644324     Jackie Wild            2.74   134 Yellow St.          Test Scores: 99, 91, 83, 92, 66, 92, 37, 94, 83, 78, 83, 74, 
     57688874     Ricky Bobby            3.23   1776 Apple Ln.          Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 73, 83, 
     12493894     Ryan Marsh             3.23   220 River Rd.           Test Scores: 88, 92, 83, 27, 94, 93, 92, 94, 94, 92, 99, 93, 
     71771132     Michael Batson         1.46   1223 Lina Tr.           Test Scores: 57, 38, 88, 66, 74, 73, 44, 91, 89, 92, 83, 94, 
     52347499     Lexi Ryan              2.4    729 Wave Rd.            Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 83, 73, 
     20829499     Beth Marie             3.03   110 Copper Rd.          Test Scores: 77, 89, 93, 74, 85, 92, 93, 74, 85, 74, 92, 45, 
     44445939     Ashley Amigo           2.36   119 Sage Tr.            Test Scores: 57, 38, 88, 22, 76, 73, 99, 91, 83, 92, 88, 94, 
     75779329     Charlie Kowalski       4      919 Prarie Tr.          Test Scores: 97, 98, 88, 22, 79, 73, 99, 91, 83, 92, 84, 93, 

Enter the Student ID you wish to search for: 222


Here is your Student - found through Binary Recursion: 

     STUDENT ID  NAME                    GPA   STUDENT ADDRESS          

That number does not exist in the vector. 