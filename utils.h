#include "board_structures.h"

#include <string>
#include <vector>
#include <fstream>


namespace utils{

    vector<vector<Cell>> get_board_from_file(std::string path) {
        std::ifstream infile(path);
        vector<vector<Cell>> board;
        std::string line;
        int row = 0, col = 0;
        char ch;
        while (std::getline(infile, line))
        {
            std::istringstream iss(line);
            vector<string> cells = split(line, " ");
            vector<Cell> row;
            for (cell: cells) {
                switch (cell) {
                        case ".":
                            row.push_back(BarrierType.FREE_SPACE);
                            break;
                        case "R":
                            row.push_back(BarrierType.ROCK);
                            break;
                        case "W":
                            row.push_back(BarrierType.WATER);
                            break;
                        case "B":
                            row.push_back(BarrierType.BARRIER);
                            break;
                        case "L":
                            row.push_back(BarrierType.LAVA);
                            break;
                        case "T":
                            row.push_back(BarrierType.TELEPORT);
                            break;
                        default:
                            throw;
                    }
            }
            board.push_back(row);
            row++;
            col = 0;
        }       

        return board;
    }

    vector<string> split (string s, string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
    }    
}