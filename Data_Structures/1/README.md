Problem 1 – Problem and Description

Create an unsorted linked list (1) and then a sorted linked list (2). As well be able to delete from the list (3) and insert into a sorted list (4).

-	The first goal for this project was to be able to create a linked list by appending information from an array into the list – unsorted. This was accomplished through a simple loop and append function. To populate the Linked List each element of the Linked List was passed to the linked list separately:
-	The second task was to then reinsert that array into the Linked List using the insert function in order to have it organized by ID. This was accomplished with a loop and insert function. . To populate the Linked List each element of the Linked List was passed to the linked list separately:
-	The third part was to prompt the user to input the info to be deleted and then delete the node and that was inputted by passing it to the delete function. This was done by searching for the information within the Linked List and then deleting it by connecting the other nodes to one another: 
-	The last part of the problem was to insert a student’s information into the Linked List in the appropriate place. This was done by receiving the students information (each piece individually) and then passing it to the insert function – where it found the correct placement for the new node:

Project 1 Input and Output

Here are the current Students (ID, Name, GPA, Student Address, 10+ test scores):  

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
     52347499     Lexi Ryan              2.4    729 Wave Rd.            
     20829499     Beth Marie             3.03   110 Copper Rd.          
     44445939     Ashley Amigo           2.36   119 Sage Tr.            
     75779329     Charlie Kowalski       4      919 Prarie Tr.          

Now lets create a linked list from this array.

Here are the current Students (ID, Name, GPA, Student Address, 10+ test scores):  

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
     52347499     Lexi Ryan              2.4    729 Wave Rd.            
     20829499     Beth Marie             3.03   110 Copper Rd.          
     44445939     Ashley Amigo           2.36   119 Sage Tr.            

Here they are sorted through Insert:

Here are the current Students (ID, Name, GPA, Student Address, 10+ test scores):  

     STUDENT ID  NAME                    GPA   STUDENT ADDRESS          

     12493894     Ryan Marsh             3.23   220 River Rd.           
     13453329     Alex Cortez            3.53   109 Crest St.           
     20829499     Beth Marie             3.03   110 Copper Rd.          
     23897939     Ash Catchum            3.44   1550 Sagewood Tr.       
     32498887     Caleb Nesbit           3.33   200 Peach Rd.           
     33454444     Mike Stiller           3.75   221 Blue St.            
     38889643     Christie Mickey        3.45   552 Nickel Rd.          
     44445939     Ashley Amigo           2.36   119 Sage Tr.            
     45553894     Ben Lyons              3.34   220 Ridge Rd.           
     47763329     Lyndon Johnson         3.45   802 Love Ln.            
     52347499     Lexi Ryan              2.4    729 Wave Rd.            
     55584739     Wes Thompson           2.24   839 Hollow Tr.          
     57688874     Ricky Bobby            3.23   1776 Apple Ln.          
     59860454     Jimmy Woods            3.77   234 Orange St.          
     59988963     Stella Esquire         3.33   9595 Colby Rd.          
     61111339     Joey Gerald            2.46   1393 Mustang Tr.        
     66644324     Jackie Wild            2.74   134 Yellow St.          
     69988963     Marcy Eckhert          2.43   953 Ridgeway Rd.        
     71771132     Michael Batson         1.46   1223 Lina Tr.           

Enter the ID you wish to Delete: 52347499


Here is the list after deletion: 
Here are the current Students (ID, Name, GPA, Student Address, 10+ test scores):  

     STUDENT ID  NAME                    GPA   STUDENT ADDRESS          

     12493894     Ryan Marsh             3.23   220 River Rd.           
     13453329     Alex Cortez            3.53   109 Crest St.           
     20829499     Beth Marie             3.03   110 Copper Rd.          
     23897939     Ash Catchum            3.44   1550 Sagewood Tr.       
     32498887     Caleb Nesbit           3.33   200 Peach Rd.           
     33454444     Mike Stiller           3.75   221 Blue St.            
     38889643     Christie Mickey        3.45   552 Nickel Rd.          
     44445939     Ashley Amigo           2.36   119 Sage Tr.            
     45553894     Ben Lyons              3.34   220 Ridge Rd.           
     47763329     Lyndon Johnson         3.45   802 Love Ln.            
     55584739     Wes Thompson           2.24   839 Hollow Tr.          
     57688874     Ricky Bobby            3.23   1776 Apple Ln.          
     59860454     Jimmy Woods            3.77   234 Orange St.          
     59988963     Stella Esquire         3.33   9595 Colby Rd.          
     61111339     Joey Gerald            2.46   1393 Mustang Tr.        
     66644324     Jackie Wild            2.74   134 Yellow St.          
     69988963     Marcy Eckhert          2.43   953 Ridgeway Rd.        
     71771132     Michael Batson         1.46   1223 Lina Tr.           

Enter the ID you wish to insert: 52347499


Enter the name you wish to insert: Lexi Ryan


Enter the gpa you wish to insert: 2.4

Enter the address you wish to insert: 249 Wave Rd.

Enter the address you wish to insert: Here are the current Students (ID, Name, GPA, Student Address, 10+ test scores):  

     STUDENT ID  NAME                    GPA   STUDENT ADDRESS          

     12493894     Ryan Marsh             3.23   220 River Rd.           
     13453329     Alex Cortez            3.53   109 Crest St.           
     20829499     Beth Marie             3.03   110 Copper Rd.          
     23897939     Ash Catchum            3.44   1550 Sagewood Tr.       
     32498887     Caleb Nesbit           3.33   200 Peach Rd.           
     33454444     Mike Stiller           3.75   221 Blue St.            
     38889643     Christie Mickey        3.45   552 Nickel Rd.          
     44445939     Ashley Amigo           2.36   119 Sage Tr.            
     45553894     Ben Lyons              3.34   220 Ridge Rd.           
     47763329     Lyndon Johnson         3.45   802 Love Ln.            
     52347499     Lexi Ryan 		   2.4    249 Wave Rd.
     55584739     Wes Thompson           2.24   839 Hollow Tr.          
     57688874     Ricky Bobby            3.23   1776 Apple Ln.          
     59860454     Jimmy Woods            3.77   234 Orange St.          
     59988963     Stella Esquire         3.33   9595 Colby Rd.          
     61111339     Joey Gerald            2.46   1393 Mustang Tr.        
     66644324     Jackie Wild            2.74   134 Yellow St.          
     69988963     Marcy Eckhert          2.43   953 Ridgeway Rd.        
     71771132     Michael Batson         1.46   1223 Lina Tr.           


 Thank you for joining us!

 