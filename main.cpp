#pragma once
#include "KnightBoard.h"
#include "board_structures.h"
#include "utils.h"

#include <vector>
#include <memory>
#include <iostream>

int main(int argc, char** argv) {
  // vector<vector<Cell> > board = utils::get_board_from_file("map.txt");
  std::cout<<"sss"<<std::endl;
  KnightBoard kb("map.txt");
  std::cout<<"sss"<<std::endl;
  Pose knightPose(0, 0);
  Pose startPose(0, 0);
  Pose endPose(1, 1);
  std::cout<<"sss"<<std::endl;


  Sequence seq;
  seq.seq.push_back(startPose);
  seq.seq.push_back(endPose);
  // Level 1
  bool is_valid = kb.getKnight().isValidSequence(seq);
  if (is_valid) {
    std::cout<< "valid seq"<< std::endl;
  }
  else {
    std::cout<< "not valid seq"<< std::endl;    
  }
  
  // Level 2, Level 3 and Level 4
  vector<Pose> path = kb.findPath(startPose, endPose);
  utils::printPath(path);
  // kb.printBoard(knightPose);
  std::cout<<"ss!!!s"<<std::endl;
  return 0;
}



/*

          for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {


            	switch (board[i][j].barrier_type) {
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
                            // std::cout <<(int) board[i][j].barrier_type;

                    }
                    std::cout <<" ";

            }
            std::cout<<std::endl;
        }
*/