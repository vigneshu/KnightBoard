
# Description
* This repo contains the solution to the problem provided. 
* The program **does not** do input validations. Please be careful while editing `map.txt` or while inputing into the `cli`
* I have completed upto Level 5

# Build 
Run `make` from the root folder
# Run
Run `./output.exe` after running `make`
# Input
#### map.txt
*  contains the map. Look at it for an example map
*  Make sure **not** to add an empty line at the end of the file. This seg faults the program

# Brief description of file structure
The solutions to the problem statement  have been exposed in the public functions in header files `Knight.h` and `KnightBoard.h`
### Knight.h
Contains functionality specific to knight
* Fucntions of interest
    * `isValidJump`
        * Checks each jump with the following constraints
            *   Knight jump 
            *   Barrier in the path
            *   Whether pose is within bounds of chess board
    * `isValidSequence`
        * Checks if each jump in the sequence is valid 
### KnightBoard.h
* Fucntions of interest
    * `printBoard` (specified as optional in question)
         Prints the board with the knight specified on board
    * `findShortestPath`
        Finds shortest path. Takes in start and end pose 
    * `findLongestPath`
        Finds Longest path. Takes in start and end pose         
Contains functionality specific to board

### board_structures.h
Contains custom datastructures like `Pose`, `Sequence`, `enum BarrierType`, `Cell` (a cell in the checkboard)

### utils.h
Contains helper functions
* printPath
Prints the solution vector
* get_board_from_file
Converts a text file to 2D vector grid


(Question 1) `Knight.h: isValidSequence`
(Question 2) *Question 3* computes the shortest sequence. Hence this is covered in that section
(Question 3) `KnightBoard.h: findShortestPath`:  Uses dijkstra's on adjacency matrix.
(Question 4) `KnightBoard.h: getCostMatrix`: This builds the adjacency matrix based on the different types of barriers. Question 3 is applied on that
(Question 5) `KnightBoard.h: findLongestPath`: This negates the costMatrix and applies the shortes path

## Assumptions
* Only square boards
* Valid inputs
* Any number of teleports


# Question
There are 3 variations of this question, listed in increasing levels of difficulty. Please proceed through as far as your abilities allow. Please use C++,
The knight board can be represented in x,y coordinates. The upper left position is (0,0) and the bottom right is (7,7). Assume there is a single knight chess piece on the board that can move according to chess rules. Sample S[tart] and E[nd] points are shown below: 
 . . . . . . . . 
 . . . . . . . . 
 . S . . . . . . 
 . . . . . . . . 
 . . . . . E . . 
 . . . . . . . . 
 . . . . . . . . 
 . . . . . . . .

Step 1: Write a function that accepts a sequence of moves, and analyze and reports whether the sequence contains only valid knight moves. It should also optionally print the state of the knight board to the terminal as shown above after each move. The current position should be marked with a 'K'. 

Step 2: Compute a valid sequence of moves from a given start point to a given endpoint.

Step 3: Compute a valid sequence of moves from a given start point to a given endpoint in the fewest number of moves. 

[Advanced]: 
Step 4: Now repeat the Step 3 task for this 32x32 board. Also, modify your validator from step 1 to check your solutions. 
following additional rules:
 1) W[ater] squares count as two moves when a piece lands there
 2) R[ock] squares cannot be used
 3) B[arrier] squares cannot be used AND cannot lie in the path
 4) T[eleport] squares instantly move you from one T to the other in 
 the same move
 5) L[ava] squares count as five moves when a piece lands there
. . . . . . . . B . . . L L L . . . . . . . . . . . . . . . . .
 . . . . . . . . B . . . L L L . . . . . . . . . . . . . . . . .
 . . . . . . . . B . . . L L L . . . L L L . . . . . . . . . . .
 . . . . . . . . B . . . L L L . . L L L . . . R R . . . . . . .
 . . . . . . . . B . . . L L L L L L L L . . . R R . . . . . . .
 . . . . . . . . B . . . L L L L L L . . . . . . . . . . . . . .
 . . . . . . . . B . . . . . . . . . . . . R R . . . . . . . . .
 . . . . . . . . B B . . . . . . . . . . . R R . . . . . . . . .
 . . . . . . . . W B B . . . . . . . . . . . . . . . . . . . . .
 . . . R R . . . W W B B B B B B B B B B . . . . . . . . . . . .
 . . . R R . . . W W . . . . . . . . . B . . . . . . . . . . . .
 . . . . . . . . W W . . . . . . . . . B . . . . . . T . . . . .
 . . . W W W W W W W . . . . . . . . . B . . . . . . . . . . . .
 . . . W W W W W W W . . . . . . . . . B . . R R . . . . . . . .
 . . . W W . . . . . . . . . . B B B B B . . R R . W W W W W W W
 . . . W W . . . . . . . . . . B . . . . . . . . . W . . . . . .
 W W W W . . . . . . . . . . . B . . . W W W W W W W . . . . . .
 . . . W W W W W W W . . . . . B . . . . . . . . . . . . B B B B
 . . . W W W W W W W . . . . . B B B . . . . . . . . . . B . . .
 . . . W W W W W W W . . . . . . . B W W W W W W B B B B B . . .
 . . . W W W W W W W . . . . . . . B W W W W W W B . . . . . . .
 . . . . . . . . . . . B B B . . . . . . . . . . B B . . . . . .
 . . . . . R R . . . . B . . . . . . . . . . . . . B . . . . . .
 . . . . . R R . . . . B . . . . . . . . . . . . . B . T . . . .
 . . . . . . . . . . . B . . . . . R R . . . . . . B . . . . . .
 . . . . . . . . . . . B . . . . . R R . . . . . . . . . . . . .
 . . . . . . . . . . . B . . . . . . . . . . R R . . . . . . . .
 . . . . . . . . . . . B . . . . . . . . . . R R . . . . . . . .
 . . . . . . . . . . . B . . . . . . . . . . R R . . . . . . . .
 . . . . . . . . . . . B . . . . . . . . . . R R . . . . . . . .
 . . . . . . . . . . . B . . . . . . . . . . R R . . . . . . . .
 . . . . . . . . . . . B . . . . . . . . . . R R . . . . . . . .
 
 
Step 5 [HARD/Optional]: Compute the longest sequence of moves to complete Step 3 without visiting the same square twice. Use the 32x32 board. 
