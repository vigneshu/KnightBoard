#pragma once
#include "KnightBoard.h"
#include "board_structures.h"
#include "utils.h"

#include <vector>
#include <memory>
#include <iostream>

int main(int argc, char** argv) {
  KnightBoard kb("map.txt");
  Pose knightPose(0, 0);
  Pose startPose(0,0);
  Pose endPose(1,1);


  Sequence seq;
  seq.seq.push_back(startPose);
  seq.seq.push_back(endPose);
  // Valid sequence
  bool is_valid = kb.getKnight().isValidSequence(seq);
  if (is_valid) {
    std::cout<< "Valid sequence"<< std::endl;
  }
  else {
    std::cout<< "Not a valid sequence"<< std::endl;    
  }
  
  // Shortest path
  vector<Pose> path = kb.findShortestPath(startPose, endPose);
  if (path.size() > 0){
    path.push_back(endPose);
    utils::printPath(path);
  }
  else{
    std::cout << "No path found "<<std::endl;
  }

  // Longest path
  path = kb.findLongestPath(startPose, endPose);
  if (path.size() > 0){
    path.push_back(endPose);
    utils::printPath(path);
  }
  else{
    std::cout << "No path found "<<std::endl;
  }
  return 0;
}
