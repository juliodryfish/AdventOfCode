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

using Stack_t = std::stack<char>;
using Stacks_t = std::array<Stack_t, 9>;

int main() {
    Stacks_t data;
    
    // Yes I'm lazy, fight me.
    data[0].push('B');data[1].push('N');data[2].push('J');data[3].push('S');data[4].push('Z');data[5].push('W');data[6].push('F');data[7].push('W');data[8].push('R');
    data[0].push('L');data[1].push('B');data[2].push('C');data[3].push('P');data[4].push('S');data[5].push('D');data[6].push('M');data[7].push('Q');data[8].push('P');
    data[0].push('D');data[1].push('L');data[2].push('H');data[3].push('J');data[4].push('C');data[5].push('G');data[6].push('S');data[7].push('R');data[8].push('M');
    data[0].push('T');                  data[2].push('T');data[3].push('W');data[4].push('F');data[5].push('B');data[6].push('P');data[7].push('J');data[8].push('L');
    data[0].push('W');                  data[2].push('L');                  data[4].push('T');data[5].push('H');data[6].push('V');data[7].push('F');data[8].push('H');
    data[0].push('C');                  data[2].push('V');                  data[4].push('L');data[5].push('N');data[6].push('G');data[7].push('V');
    data[0].push('F');                                                      data[4].push('R');data[5].push('Z');data[6].push('C');data[7].push('C');
    data[0].push('M');                                                                                          data[6].push('N');data[7].push('Z');


    std::ifstream input_file("../input.txt");
    std::string line;
    while(std::getline(input_file, line)) {
        std::string a, b, c;
        int qt, src, dst;
        std::istringstream input_stream(line);
        input_stream >> a >> qt >> b >> src >> c >> dst;
        for(auto i = 0; i < qt; ++i) {
            auto top = data[src - 1].top();
            data[src - 1].pop();
            data[dst - 1].push(top);
        }
    }

    for(auto i = 0; i < data.size(); ++i) {
        std::cout << data[i].top();
    }
    std::cout << std::endl;

    return 0;
}