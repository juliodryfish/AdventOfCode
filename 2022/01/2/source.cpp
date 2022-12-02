#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {

    std::ifstream input_file("../input.txt");
    std::vector<int> data;
    int aux = 0;

    std::string line;
    int i = 0;
    data.push_back(0);
    while(std::getline(input_file, line))
    {
        if(line.empty()) {
            data.push_back(0);
            i++;
        } else {
            std::istringstream input_stream(line);
            int input;
            input_stream >> input;
            data[i] += input;
        }
    }
    
    std::sort(data.begin(), data.end(), [](int a, int b){ return a > b;});
    std::cout << data.back() << std::endl;
    std::cout << data[0] + data[1] + data[2] << std::endl;

    return 0;
}