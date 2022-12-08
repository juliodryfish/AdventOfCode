#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <numeric>
#include <utility>
#include <stack>
#include <unordered_map>
#include <cctype>

using Trees_t = std::array<std::array<int, 99>, 99>;

int main() {

    Trees_t trees;
    std::ifstream input_file("../input.txt");
    std::string line;

    int row = 0;
    while(std::getline(input_file, line)) {
        std::istringstream input_stream(line);
        for(int column = 0; column < 99; ++column) {
            trees[row][column] = line[column] - '0';
        }
        row++;
    }

    int result = 0;
    for(row = 0; row < 99; ++row) {
        for(int column = 0; column < 99; ++column) {
            auto at = [&trees](int r, int c) -> int { return trees[r][c];};
            auto current = at(row, column);
            if((row == 0 || column == 0) || (row == 99 - 1 || column == 99 - 1)) {
                result++;
                continue;
            } else{
                int v = 0;
                for(int inc = 1; column + inc < 99; ++inc) { // Down
                    if(at(row, column + inc) >= current) { // not visible
                        v++;
                        break;
                    }
                }
                for(int inc = 1; column - inc >= 0; ++inc) { // Up
                    if(at(row, column - inc) >= current) { // not visible
                        v++;
                        break;
                    }
                }
                for(int inc = 1; row + inc < 99; ++inc) { // Right
                    if(at(row + inc, column) >= current) { // not visible
                        v++;
                        break;
                    }
                }
                for(int inc = 1; row - inc >= 0; ++inc) { // Left
                    if(at(row - inc, column) >= current) { // not visible
                        v++;
                        break;
                    }
                }
                if(v != 4) result++;
            }
        }
    }
    std::cout << result << std::endl;

    return 0;
}