#pragma once
#include <vector>
#include "board_structures.h"

using std::vector;

class Knight{
    public:
        Knight();
        explicit Knight(vector<vector<Cell> > board);
        bool isValidJump(Pose pose1, Pose pose2);
        bool isValidSequence(Sequence seq);
    
    private:
        bool isPoseWithinBounds(Pose pose);
        bool isPathBlocked(Pose pose1, Pose pose2);
        vector<vector<Cell> > board_;

};