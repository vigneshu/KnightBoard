#include "KnightBoard.h"
#include "utils.h"

#include <vector>
#include <memory>
#include <iostream>

int main(int argc, char** argv) {
  vector<vector<Cell> > board = utils::get_board_from_file("map.txt");
  // KnightBoard kb(8);
  // Pose knightPose(0, 0);
  // kb.printBoard(knightPose);

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