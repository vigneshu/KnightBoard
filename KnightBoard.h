#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "board_structures.h"
#include "Knight.h"

using std::vector;

class KnightBoard {
public:
    KnightBoard(std::string board_file_path);
    void printBoard(Pose &knight_position);
    vector<Pose> findPath(Pose &start_pose, Pose &end_pose);
    Knight getKnight();

private:
    vector<Pose> getTeleportTiles();
    Pose getPositionFromIndex(const int index);
    int getIndexFromPosition(const Pose &pose);
    vector<vector<int> > getCostMatrix();
    vector<Pose> findPathHelper(vector<int> &parent, Pose &end_pose);
    void printHelper(vector< vector<int> > vec);

    int size_;
    vector<vector<Cell> > board_;
    Knight knight_;
    vector<vector<int> > cost_matrix_;
};