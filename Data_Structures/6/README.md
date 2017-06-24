Project 6 – Problem and Description

For this project I set out to solve the ancient disk game known as the Towers of Hanoi. In order to do this I read in the number of disks (1) and then called a function to move the disks while displaying the output (2).

-	For this portion of the assignment I merely read in the number of disks the user wished to solve for. I also set all the pegs equal to position ‘A’:
-	For the second portion of the assignment I called the function with the number of pegs and the array with all of the pegs set to position A. Upon calling the function the pegs were moved one by one from the first to the third, first to the second, third to the second, first to the third, second to the first, second to the third, and then the first to the third. Even if there were more disks than three I followed this general algorithm. I accomplished this by recursively calling the moveD function and displaying the information with the appropriate output:
 
Test Input and Output


Welcome to the monk inspired game: Tower of Hanoi

Enter number of discs you would like to play with: 3


Move disc 1 from A to C		(C, A, A)

Move disc 2 from A to B		(C, B, A)

Move disc 1 from C to B		(B, B, A)

Move disc 3 from A to C		(B, B, C)

Move disc 1 from B to A		(A, B, C)

Move disc 2 from B to C		(A, C, C)

Move disc 1 from A to C		(C, C, C)



Welcome to the monk inspired game: Tower of Hanoi

Enter number of discs you would like to play with: 4


Move disc 1 from A to B		(B, A, A, A)

Move disc 2 from A to C		(B, C, A, A)

Move disc 1 from B to C		(C, C, A, A)

Move disc 3 from A to B		(C, C, B, A)

Move disc 1 from C to A		(A, C, B, A)

Move disc 2 from C to B		(A, B, B, A)

Move disc 1 from A to B		(B, B, B, A)

Move disc 4 from A to C		(B, B, B, C)

Move disc 1 from B to C		(C, B, B, C)

Move disc 2 from B to A		(C, A, B, C)

Move disc 1 from C to A		(A, A, B, C)

Move disc 3 from B to C		(A, A, C, C)

Move disc 1 from A to B		(B, A, C, C)

Move disc 2 from A to C		(B, C, C, C)

Move disc 1 from B to C		(C, C, C, C)


Welcome to the monk inspired game: Tower of Hanoi

Enter number of discs you would like to play with: 5


Move disc 1 from A to C		(C, A, A, A, A)

Move disc 2 from A to B		(C, B, A, A, A)

Move disc 1 from C to B		(B, B, A, A, A)

Move disc 3 from A to C		(B, B, C, A, A)

Move disc 1 from B to A		(A, B, C, A, A)

Move disc 2 from B to C		(A, C, C, A, A)

Move disc 1 from A to C		(C, C, C, A, A)

Move disc 4 from A to B		(C, C, C, B, A)

Move disc 1 from C to B		(B, C, C, B, A)

Move disc 2 from C to A		(B, A, C, B, A)

Move disc 1 from B to A		(A, A, C, B, A)

Move disc 3 from C to B		(A, A, B, B, A)

Move disc 1 from A to C		(C, A, B, B, A)

Move disc 2 from A to B		(C, B, B, B, A)

Move disc 1 from C to B		(B, B, B, B, A)

Move disc 5 from A to C		(B, B, B, B, C)

Move disc 1 from B to A		(A, B, B, B, C)

Move disc 2 from B to C		(A, C, B, B, C)

Move disc 1 from A to C		(C, C, B, B, C)

Move disc 3 from B to A		(C, C, A, B, C)

Move disc 1 from C to B		(B, C, A, B, C)

Move disc 2 from C to A		(B, A, A, B, C)

Move disc 1 from B to A		(A, A, A, B, C)

Move disc 4 from B to C		(A, A, A, C, C)

Move disc 1 from A to C		(C, A, A, C, C)

Move disc 2 from A to B		(C, B, A, C, C)

Move disc 1 from C to B		(B, B, A, C, C)

Move disc 3 from A to C		(B, B, C, C, C)

Move disc 1 from B to A		(A, B, C, C, C)

Move disc 2 from B to C		(A, C, C, C, C)

Move disc 1 from A to C		(C, C, C, C, C)

 