#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <utility>
#include <array>
#include <unordered_set>
#include <set>
int main() {
    enum direction_t { UP = 'U', DOWN = 'D', RIGHT = 'R' , LEFT = 'L'}; 

    std::ifstream input_file("../input.txt");
    std::string line;    
    std::set<std::array<int,2>> footprint;
    
    std::array<int,2> t = {0, 0};
    std::array<std::array<int, 2>, 10> rope;
    std::fill(std::begin(rope), std::end(rope), std::array<int, 2>{0, 0});

    auto & h = rope[0]; auto & head_x = h[0]; auto & head_y = h[1];

    footprint.insert(t);
    while(std::getline(input_file, line)) {
        std::istringstream ss(line);
        char direction;
        int steps;
        ss >> direction >> steps;

        for(int i = 0; i < steps; ++i) {

            switch(direction) {
                case    UP: head_y++;
                break;
                case  DOWN: head_y--;
                break;
                case  LEFT: head_x--;
                break;
                case RIGHT: head_x++;
                break;
            }
            for(int node = 1; node < rope.size(); ++node) {
                auto & nx = rope[node][0];
                auto & ny = rope[node][1];

                bool check = false;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if(nx + dx == rope[node - 1][0] && ny + dy == rope[node - 1][1]) {
                            check = true;
                        }
                    }
                } 

                if(check == false) {
                    if(rope[node - 1][0] > nx) nx++;
                    else if(rope[node - 1][0] < nx) nx--;

                    if(rope[node - 1][1] > ny) ny++;
                    else if(rope[node - 1][1] < ny) ny--;
                }
            }
            
            footprint.insert(rope[9]);
        }
    }

    std::cout << footprint.size() << std::endl;

    return 0;
}