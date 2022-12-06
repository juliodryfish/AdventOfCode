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

int main() {

    std::ifstream input_file("../input.txt");
    std::string line;
    int result;
    while(std::getline(input_file, line)) {
        for(int index = 0; index < (line.size() - 14); ++index) {
            auto sop = line.substr(index, 14);
            std::sort(sop.begin(), sop.end());
            if(std::unique(sop.begin(), sop.end()) == sop.end()) {
                result = index + 14;
                break;
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}