#include <limits>
#include <algorithm>
#include <iostream>

#include "KnightBoard.h"
#include "utils.h"

#define INT_MAX std::numeric_limits<int>::max()

KnightBoard::KnightBoard(std::string file_path) {
    board_ = utils::get_board_from_file(file_path);
    size_ = board_.size();
    Knight knight_temp(board_);
    knight_ = knight_temp;
}

Knight KnightBoard::getKnight() {
    return knight_;
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
  return tiles;
}

Pose KnightBoard::getPositionFromIndex(const int index) {
    return Pose(index / size_, index % size_);
}

int KnightBoard::getIndexFromPosition(const Pose &pose) {
    return size_* pose.x + pose.y;
}

vector<vector<int> > KnightBoard::getCostMatrix(int sign_multiplier){
  vector< vector<int> > adjacency_matrix(size_*size_, vector<int>(size_*size_));
  for(int row = 0; row < size_* size_; row++) {
    for(int col = 0; col < size_* size_; col++) {
        Pose source = getPositionFromIndex(row);
        Pose dest = getPositionFromIndex(col);
        if (knight_.isValidJump(source, dest)) {
            
            switch (board_[dest.x][dest.y].barrier_type){
                case BarrierType::FREE_SPACE:
                    adjacency_matrix[row][col] = 1 * sign_multiplier;
                    break;
                case BarrierType::WATER:
                    adjacency_matrix[row][col] = 2  * sign_multiplier;
                    break;
                case BarrierType::LAVA:
                    adjacency_matrix[row][col] = 5 * sign_multiplier;
                    break;
                case BarrierType::TELEPORT:
                    for (auto teleport_pose: getTeleportTiles()) {
                        int teleport_index = getIndexFromPosition(teleport_pose);
                        if (teleport_pose == dest) {
                            if (adjacency_matrix[row][teleport_index] != 1 * sign_multiplier)
                                adjacency_matrix[row][teleport_index] = INT_MAX;
                        }
                        else if (teleport_pose == source){
                            if (adjacency_matrix[row][teleport_index] != 1 * sign_multiplier)
                                adjacency_matrix[row][teleport_index] = INT_MAX;
                        }
                        else {
                            adjacency_matrix[row][teleport_index] = 1 * sign_multiplier;
                        }
                    }
                    break;
                case BarrierType::ROCK:
                case BarrierType::BARRIER:
                    adjacency_matrix[row][col] = INT_MAX;
                    break;
            }    
        }
        else {
            if (adjacency_matrix[row][col] != 1 * sign_multiplier)
                adjacency_matrix[row][col] = INT_MAX;
        }
                    
    }
    }
    // printHelper(adjacency_matrix);
    return adjacency_matrix;
}

void KnightBoard::printHelper(vector< vector<int> > vec){
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            int val = vec[i][j];
            if (val == INT_MAX){
                val = -1;
            }
            std::cout<< val<< " (" << i<< "," <<j <<") ";
            }
            std::cout<<std::endl;
        }
}
vector<Pose> KnightBoard::findPathHelper(vector<int> &parent_indices, Pose &end_pose) {
    int src = 0; 
    int cur_pose_index = getIndexFromPosition(end_pose);

    vector<Pose> path;
    while(true){
        int parent_index = parent_indices[cur_pose_index];
        if (parent_index == -1){
            break;
        }
        path.push_back(getPositionFromIndex(parent_index));
        cur_pose_index = parent_index;
    }
    std::reverse(path.begin(),path.end());
    return path;
}

vector<Pose> KnightBoard::findLongestPath(Pose &start_pose, Pose &end_pose) {
    cost_matrix_ = getCostMatrix(-1);
    return findPath(start_pose, end_pose);
}

vector<Pose> KnightBoard::findShortestPath(Pose &start_pose, Pose &end_pose) {
    cost_matrix_ = getCostMatrix();
    return findPath(start_pose, end_pose);
}

vector<Pose> KnightBoard::findPath(Pose &start_pose, Pose &end_pose) {
    // check if start pose is barrier
    vector<Pose> path;
    if (board_[start_pose.x][start_pose.y].barrier_type == BarrierType::ROCK ||
         board_[start_pose.x][start_pose.y].barrier_type == BarrierType::BARRIER){
        return path;
    } else if (start_pose == end_pose) {
        path.push_back(start_pose);
        return path;
    }
    
    vector<int> dist(cost_matrix_.size(), INT_MAX);
    vector<bool> visited(cost_matrix_.size(), false);
    vector<int> parent_indices(cost_matrix_.size(), -1);
    int start_pose_index = getIndexFromPosition(start_pose);
    parent_indices[start_pose_index] = -1;
    dist[start_pose_index] = 0;
    for (int iteration = 0; iteration < cost_matrix_.size(); iteration++) {
        // Pop the minimum unvisted value
        int min = INT_MAX, min_index;
        bool flag = false;
        for (int i = 0; i < cost_matrix_.size(); i++) {
            if (visited[i] == false && dist[i] < min) {
                min = dist[i];
                min_index = i;
                flag = true;
            }
        }
        // Mark the picked vertex as visited 
        visited[min_index] = true; 
  
        // Update dist value for neighbours of picked vertex
        for (int v = 0; v < cost_matrix_.size(); v++) {
  
            if (!visited[v] && cost_matrix_[min_index][v] < INT_MAX && 
                dist[min_index] + cost_matrix_[min_index][v] < dist[v]) 
            { 
                parent_indices[v] = min_index; 
                dist[v] = dist[min_index] + cost_matrix_[min_index][v]; 
            }  
        }
    }
    path = findPathHelper(parent_indices, end_pose);
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




