#pragma once
#include <vector>
#include <memory>
#include "board_structures.h"
#include "Knight.h"

using std::vector;

class KnightBoard {
public:
    KnightBoard(int board_size);
    void printBoard(Pose &knight_position);
    vector<Pose> findPath(Pose &start_pose, Pose &end_pose);

private:
    vector<Pose> getTeleportTiles();
    Pose getPositionFromIndex(const int index);
    int getIndexFromPosition(const Pose &pose);
    vector<vector<int> > getCostMatrix();
    vector<Pose> findPathHelper(vector<int> &parent, Pose &end_pose);

    int size_;
    vector<vector<Cell> > board_;
    // std::shared_ptr<Knight> knight_;//{std::make_shared<AdapterFactoryMock>()};
    Knight knight_;//{std::make_shared<AdapterFactoryMock>()};
    vector<vector<int> > cost_matrix_;
};