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
    
    // Yes I'm lazy, fight me. (x2)
    data[0].push('B');
    data[0].push('L');
    data[0].push('D');
    data[0].push('T');
    data[0].push('W');
    data[0].push('C');
    data[0].push('F');
    data[0].push('M');

    data[1].push('N');
    data[1].push('B');
    data[1].push('L');

    data[2].push('J');
    data[2].push('C');
    data[2].push('H');
    data[2].push('T');
    data[2].push('L');
    data[2].push('V');

    data[3].push('S');
    data[3].push('P');
    data[3].push('J');
    data[3].push('W');

    data[4].push('Z');
    data[4].push('S');
    data[4].push('C');
    data[4].push('F');
    data[4].push('T');
    data[4].push('L');
    data[4].push('R');

    data[5].push('W');
    data[5].push('D');
    data[5].push('G');
    data[5].push('B');
    data[5].push('H');
    data[5].push('N');
    data[5].push('Z');

    data[6].push('F');
    data[6].push('M');
    data[6].push('S');
    data[6].push('P');
    data[6].push('V');
    data[6].push('G');
    data[6].push('C');
    data[6].push('N');

    data[7].push('W');
    data[7].push('Q');
    data[7].push('R');
    data[7].push('J');
    data[7].push('F');
    data[7].push('V');
    data[7].push('C');
    data[7].push('Z');

    data[8].push('R');
    data[8].push('P');
    data[8].push('M');
    data[8].push('L');
    data[8].push('H');

    std::ifstream input_file("../input.txt");
    std::string line;
    while(std::getline(input_file, line)) {
        std::string a, b, c;
        int qt, src, dst;
        std::istringstream input_stream(line);
        input_stream >> a >> qt >> b >> src >> c >> dst;
        std::stack<char> aux;
        for(auto i = 0; i < qt; ++i) {
            auto top = data[src - 1].top();
            data[src - 1].pop();
            aux.push(top);
        }
        while(aux.size()) { // :clown:
            auto top = aux.top();
            aux.pop();
            data[dst - 1].push(top);
        }
    }

    for(auto i = 0; i < data.size(); ++i) {
        std::cout << data[i].top();
    }
    std::cout << std::endl;

    return 0;
}