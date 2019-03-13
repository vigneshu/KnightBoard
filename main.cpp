#pragma once
#include "KnightBoard.h"
#include "board_structures.h"
#include "utils.h"

#include <vector>
#include <memory>
#include <iostream>

Pose inputPose(){
    int x,y;
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    Pose p(x, y);
    return p;
}

    // Sequence seq;
    // seq.seq.push_back(startPose);
    // seq.seq.push_back(endPose);
    // // Valid sequence
    // bool is_valid = kb.getKnight().isValidSequence(seq);
    // if (is_valid) {
    // std::cout<< "Valid sequence"<< std::endl;
    // }
    // else {
    //     std::cout<< "Not a valid sequence"<< std::endl;    
    // }

Sequence inputSequence(){
    char ch = 'y';
    Sequence seq;
    int x, y;
    while (ch == 'y' || ch == 'Y'){
        std::cout << "x: ";
        std::cin >> x;
        std::cout << "y: ";
        std::cin >> y;
        std::cout << "continue? (y/n): ";
        std::cin >> ch;
        seq.seq.push_back(Pose(x,y));
    }
    return seq;
}

int main(int argc, char** argv) {
    KnightBoard kb("map.txt");
    char choice = 'Y';
    while (choice!='Q'){
        vector<Pose> path;
        Sequence seq;
        Pose startPose, endPose;
        bool is_valid;
        std::cout << "Please input the map in map.txt and then use this " << std::endl;
        std::cout << "Refrain from entering invalid inputs " << std::endl;
        std::cout << "1. Shortest Path " << std::endl;
        std::cout << "2. Longest Path " << std::endl;
        std::cout << "3. Valid Sequence " << std::endl;
        std::cout << "Q. Quit " << std::endl;        
        std::cin >> choice;
        switch(choice) {
        case '1':
            // Shortest path
            std::cout << "Enter start position "<<std::endl;
            startPose = inputPose();
            std::cout << "Enter end position "<<std::endl;
            endPose = inputPose();
            path = kb.findShortestPath(startPose, endPose);
            std::cout<<std::endl<<std::endl<<std::endl;
            if (path.size() > 0){
                path.push_back(endPose);
                utils::printPath(path);
            }
            else{
                std::cout << "No path found "<<std::endl;
            }
            std::cout<<std::endl<<std::endl<<std::endl;
            break;
        case '2':
            // Longest path
            std::cout << "Enter start position "<<std::endl;
            startPose = inputPose();
            std::cout << "Enter end position "<<std::endl;
            endPose = inputPose();        
            path = kb.findLongestPath(startPose, endPose);
            std::cout<<std::endl<<std::endl<<std::endl;
            if (path.size() > 0){
                path.push_back(endPose);
                utils::printPath(path);
            }
            else{
               std::cout << "No path found "<<std::endl;
            }
            std::cout<<std::endl<<std::endl<<std::endl;
            break;
        case '3':
            std::cout<< "**********PLEASE NOTE*********"<< std::endl;
            std::cout<< "Refer map.txt to check against map"<< std::endl;
            seq = inputSequence();
            is_valid = kb.getKnight().isValidSequence(seq);
            std::cout<<std::endl<<std::endl<<std::endl;
            if (is_valid) {
                std::cout<< "Valid sequence"<< std::endl;
            }
            else {
                std::cout<< "Not a valid sequence"<< std::endl;    
            }                    
            std::cout<<std::endl<<std::endl<<std::endl;
            break;
        case 'Q':
        case 'q':
            break;
        default:
            std::cout<< "Invalid choice "<<std::endl;
        }
    }
    return 0;
}
