
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