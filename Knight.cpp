#include "Knight.h"
#include <iostream>

Knight::Knight() {}
Knight::Knight(vector<vector<Cell> > board): board_(board){}

bool Knight::isPoseWithinBounds(Pose pose) {
	return pose.x >= 0 && pose.x < board_.size() && pose.y >= 0 && pose.y < board_.size();
}

bool Knight::isPathBlocked(Pose pose1, Pose pose2) {
	int start_x = pose2.x > pose1.x ? pose1.x:pose2.x;
	int end_x = pose2.x <= pose1.x ? pose1.x:pose2.x;
	int x_diff = end_x - start_x;

	int start_y = pose2.y > pose1.y ? pose1.y:pose2.y;
	int end_y = pose2.y <= pose1.y ? pose1.y:pose2.y;
	int y_diff = end_y - start_y;

	if (x_diff == 2){
		for (int i = start_x; i < end_x; i++){
			if (board_[i][pose1.y].barrier_type == BarrierType::ROCK){
				return false;
			}
		}
		for (int j = start_y; j < end_y; j++){
			if (board_[pose2.x][j].barrier_type == BarrierType::ROCK){
				return false;
			}
		}			
	}
	else if (y_diff == 2) {
		for (int j = start_y; j < end_y; j++){
			if (board_[pose1.x][j].barrier_type == BarrierType::ROCK){
				return false;
			}
		}
		for (int i = start_x; i < end_x; i ++){
			if (board_[i][pose2.y].barrier_type == BarrierType::ROCK){
				return false;
			}
		}	
	}
	return true;
}

bool Knight::isValidJump(Pose pose1, Pose pose2) {
	
	bool result = true;
	// std::cout << "result 1 "<< result <<std::endl;
	result = result && isPoseWithinBounds(pose1);
	// std::cout << "result 2 "<< result <<std::endl;
	result = result && isPoseWithinBounds(pose2);
	// std::cout << "result 3 "<< result <<std::endl;
	result = result && isPathBlocked(pose1, pose2);
	// std::cout << "result 4 "<< result <<std::endl;

    int d_x = abs(pose1.x - pose2.x);
    int d_y = abs(pose1.y - pose2.y);
    bool valid_jump = (d_x == 1 && d_y == 2) || (d_x ==2 && d_y == 1);
	result = result && valid_jump;
	// std::cout << "result 5 "<< result <<std::endl;
	
	return result;
}

bool Knight::isValidSequence(Sequence seq) {
	bool result = true;
	for (int i = 1; i < seq.seq.size(); i ++){
		Pose pose1 = seq.seq[i - 1];
		Pose pose2 = seq.seq[i];
		if(!isValidJump(pose1, pose2)){
			result = false;
			break;
		}
	}
	return result;
}
