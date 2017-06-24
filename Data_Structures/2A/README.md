Project 2A – Description and Explanation

The task was to create an array of Student records for ID, Name, Address, and GPA (1), and then display the record (2), then push the records to a static stack (3), then pop the records off the static stack(4).

-	The task was to push the student information from a file into a set of students array. This was accomplished through reading in the information from a file with a loop. Each field of student information was read into its own separate array:
-	The display task was accomplished by looping through the student information in the array and displaying it with the appropriate formatting:
-	The task of pushing the information onta the static stack took place by creating a static stack object and then pushing it into the stack item with the push function. As each item was pushed onto the static stack the top of stack pointer was incremeneted:
-	The final task was to pop 5 records off the stack and display what remained. This took place through the pop function that caught the variables as they were popped off the static stack:


Project 2 Input and Output

Here are the current Students (ID, Name, GPA, Student Address):  

     STUDENT ID  NAME                    GPA   STUDENT ADDRESS          

     33454444     Mike Stiller           3.75   221 Blue St.            
     69988963     Marcy Eckhert          2.43   953 Ridgeway Rd.        
     47763329     Lyndon Johnson         3.45   802 Love Ln.            
     55584739     Wes Thompson           2.24   839 Hollow Tr.          
     13453329     Alex Cortez            3.53   109 Crest St.           
     45553894     Ben Lyons              3.34   220 Ridge Rd.           
     59860454     Jimmy Woods            3.77   234 Orange St.          
     38889643     Christie Mickey        3.45   552 Nickel Rd.          
     59988963     Stella Esquire         3.33   9595 Colby Rd.          
     61111339     Joey Gerald            2.46   1393 Mustang Tr.        
     23897939     Ash Catchum            3.44   1550 Sagewood Tr.       
     32498887     Caleb Nesbit           3.33   200 Peach Rd.           
     66644324     Jackie Wild            2.74   134 Yellow St.          
     57688874     Ricky Bobby            3.23   1776 Apple Ln.          
     12493894     Ryan Marsh             3.23   220 River Rd.           
     71771132     Michael Batson         1.46   1223 Lina Tr.           
     52347499     Lexi Ryan              2.40   729 Wave Rd.            
     20829499     Beth Marie             3.03   110 Copper Rd.          
     44445939     Ashley Amigo           2.36   119 Sage Tr.            
     75779329     Charlie Kowalski       4.00   919 Prarie Tr.          

Popping 5 records - they are as follows: 

      STUDENT ADDRESS          GPA    NAME                    STUDENT ID  

      919 Prarie Tr.          4.00   Charlie Kowalski       75779329    
      119 Sage Tr.            2.36   Ashley Amigo           44445939    
      110 Copper Rd.          3.03   Beth Marie             20829499    
      729 Wave Rd.            2.40   Lexi Ryan              52347499    
      1223 Lina Tr.           1.46   Michael Batson         71771132    


Here is your what is left on the stack after popping off 5 records 

 STUDENT ADDRESS          GPA   NAME                    STUDENT ID  

 220 River Rd.          3.23   Ryan Marsh              12493894    
 1776 Apple Ln.         3.23   Ricky Bobby             57688874    
 134 Yellow St.         2.74   Jackie Wild             66644324    
 200 Peach Rd.          3.33   Caleb Nesbit            32498887    
 1550 Sagewood Tr.      3.44   Ash Catchum             23897939    
 1393 Mustang Tr.       2.46   Joey Gerald             61111339    
 9595 Colby Rd.         3.33   Stella Esquire          59988963    
 552 Nickel Rd.         3.45   Christie Mickey         38889643    
 234 Orange St.         3.77   Jimmy Woods             59860454    
 220 Ridge Rd.          3.34   Ben Lyons               45553894    
 109 Crest St.          3.53   Alex Cortez             13453329    
 839 Hollow Tr.         2.24   Wes Thompson            55584739    
 802 Love Ln.           3.45   Lyndon Johnson          47763329    
 953 Ridgeway Rd.       2.43   Marcy Eckhert           69988963    
 221 Blue St.           3.75   Mike Stiller            33454444    
