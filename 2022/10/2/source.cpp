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
    std::array<char, 240> screen;
    std::fill(std::begin(screen), std::end(screen), '.');
    auto draw = [&screen](){
        for(int i = 0; i < screen.size(); ++i) {
            if(i % 40 == 0) std::cout << std::endl;
            std::cout << screen[i];
        }
    };

    std::ifstream input_file("../input.txt");
    std::string line;
    int cycle = 1;
    int X = 1;
    while(std::getline(input_file, line)) {
        std::string instruction = line.substr(0, 4);
        for(int c = 0; c < 2; ++c) {
            auto at = cycle - 1;
            screen[at] = (X == (at % 40) || X-1 == (at % 40) || X+1 == (at % 40)) ? '#': '.';
            cycle++;

            if(!instruction.compare("noop")) break;
            if(c) X += std::stoi(line.substr(5));
        }
    }
    
    draw();
    return 0;
}