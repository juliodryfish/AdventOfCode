#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <utility>
#include <array>

int main() {
    std::ifstream input_file("../input.txt");
    std::string line;
    std::array<int, 6> cycles = {20, 60, 100, 140, 180, 220};

    int result = 0;
    int cycle = 1;
    int X = 1;
    while(std::getline(input_file, line)) {
        std::string instruction = line.substr(0, 4);
        for(int c = 0; c < 2; ++c) {
            auto it = std::find(std::begin(cycles), std::end(cycles), cycle); 

            if(it != std::end(cycles)) result += (*it) * X;
            cycle++;

            if(!instruction.compare("noop")) break;
            if(c) X += std::stoi(line.substr(5));
        }
    }
    std::cout << result << std::endl;
    return 0;
}