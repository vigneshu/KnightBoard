#include <limits>
#include <algorithm>
#include <iostream>

#include "KnightBoard.h"
// #include "utils.h"

#define INT_MAX std::numeric_limits<int>::max()
const std::string file_path = "map.txt";

KnightBoard::KnightBoard(int board_size): size_(board_size) {
    // board_ = utils::get_board_from_file(file_path);
    Knight knight_temp(board_);
    knight_ = knight_temp;
    cost_matrix_ = getCostMatrix();
}

vector<Pose> KnightBoard::getTeleportTiles() {
    vector<Pose> tiles;
    for (auto row: board_) {
        for (auto cell: row) {
            if (cell.barrier_type == BarrierType::TELEPORT){
                tiles.push_back(cell.pose);
            }
        }
    }
}

Pose KnightBoard::getPositionFromIndex(const int index) {
    return Pose(index / size_, index % size_);
}

int KnightBoard::getIndexFromPosition(const Pose &pose) {
    return size_* pose.x + pose.y;
}

vector<vector<int> > KnightBoard::getCostMatrix(){
  vector< vector<int> > adjacency_matrix(size_*size_, vector<int>(size_*size_));
  for(int row = 0; row < size_* size_; row++) {
    for(int col = 0; col < size_* size_; col++) {
        Pose start_pose = getPositionFromIndex(row);
        Pose end_pose = getPositionFromIndex(col);
        if (knight_.isValidJump(start_pose, end_pose)) {
            switch (board_[end_pose.x][end_pose.y].barrier_type){
                case BarrierType::FREE_SPACE:
                    adjacency_matrix[row][col] = 1;
                    break;
                case BarrierType::WATER:
                    adjacency_matrix[row][col] = 2;
                    break;
                case BarrierType::LAVA:
                    adjacency_matrix[row][col] = 5;
                    break;
                case BarrierType::TELEPORT:
                    adjacency_matrix[row][col] = INT_MAX;
                    for (auto tile_pose: getTeleportTiles()) {
                        if (tile_pose == end_pose) {
                            adjacency_matrix[tile_pose.x][tile_pose.y] = INT_MAX;
                        }
                        else {
                            adjacency_matrix[tile_pose.x][tile_pose.y] = 1;
                        }
                    }
                    break;
            }
        }
        else {
            adjacency_matrix[row][col] = INT_MAX;
        }
    }
    }
}
vector<Pose> KnightBoard::findPathHelper(vector<int> &parent, Pose &end_pose) {
    int src = 0; 
    int end_pose_index = getIndexFromPosition(end_pose);

    vector<Pose> path;
    while(true){
        int parent_index = parent[end_pose_index];
        if (parent_index == -1)
            break;
        path.push_back(getPositionFromIndex(parent_index));
    }
    std::reverse(path.begin(),path.end());
    return path;
}

vector<Pose> KnightBoard::findPath(Pose &start_pose, Pose &end_pose) {
    vector<int> dist(cost_matrix_.size(), INT_MAX);
    vector<bool> visited(cost_matrix_.size(), false);
    vector<int> parent(cost_matrix_.size(), false);
    int start_pose_index = getIndexFromPosition(start_pose);
    parent[start_pose_index] = -1;
    dist[start_pose_index] = 0;
    for (int iteration = 0; iteration < cost_matrix_.size(); iteration++) {
        // Pop the minimum unvisted value
        int min = INT_MAX, min_index;
        for (int i = 0; i < cost_matrix_.size(); i++) 
            if (visited[i] == false && 
                       dist[i] <= min) 
                min = dist[i], min_index = i;

        // Mark the picked vertex as visited 
        visited[min_index] = true; 
  
        // Update dist value for neighbours of picked vertex
        for (int v = 0; v < cost_matrix_.size(); v++) 
  
            if (!visited[v] && cost_matrix_[min_index][v] < INT_MAX && 
                dist[min_index] + cost_matrix_[min_index][v] < dist[v]) 
            { 
                parent[v] = min_index; 
                dist[v] = dist[min_index] + cost_matrix_[min_index][v]; 
            }  
    }

    vector<Pose> path = findPathHelper(parent, end_pose);
    return path;
}

void KnightBoard::printBoard(Pose &knight_position) {
    for (int i = 0; i < size_; i++) {
        for (int j = 0; j < size_; j++) {
            if (board_[i][j].pose == knight_position){
                std::cout <<"K";
            }
            else{
                switch (board_[i][j].barrier_type) {
                    case BarrierType::FREE_SPACE:
                        std::cout <<".";
                        break;
                    case BarrierType::ROCK:
                        std::cout <<"R";
                        break;
                    case BarrierType::WATER:
                        std::cout <<"W";
                        break;
                    case BarrierType::BARRIER:
                        std::cout <<"B";
                        break;
                    case BarrierType::LAVA:
                        std::cout <<"L";
                        break;
                    case BarrierType::TELEPORT:
                        std::cout <<"T";
                        break;
                    default:
                        std::cout <<"?";

                }
            }
            std::cout <<" ";
        }
        std::cout << std::endl;
    }
}




