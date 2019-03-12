#pragma once
#include "board_structures.h"

#include <string>
#include <vector>
#include <fstream>


namespace utils{
    vector<vector<Cell> > get_board_from_file(std::string path) {
        std::fstream infile(path.c_str());
        vector<vector<Cell> > board;
        std::string line;
        int row_index = 0, col_index = 0;
        char ch;
        while (std::getline(infile, line))
        {
            vector<Cell> row;
            for (ch: line) {
                Cell cell(Pose(row_index, col_index), BarrierType::FREE_SPACE);
                switch (ch) {
                        case '.':
                            cell.barrier_type = BarrierType::FREE_SPACE;
                            break;
                        case 'R':
                            cell.barrier_type = BarrierType::ROCK;
                            break;
                        case 'W':
                            cell.barrier_type = BarrierType::WATER;
                            break;
                        case 'B':
                            cell.barrier_type = BarrierType::BARRIER;
                            break;
                        case 'L':
                            cell.barrier_type = BarrierType::LAVA;
                            break;
                        case 'T':
                            cell.barrier_type = BarrierType::TELEPORT;
                            break;
                        default:
                            throw;
                    }
                    row.push_back(cell);
                    col_index++;
            }
            board.push_back(row);
            row_index++;
            col_index = 0;
        }       

        return board;
    }  
}