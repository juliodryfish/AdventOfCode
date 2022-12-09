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
    
    std::array<int,2> h = {0, 0};
    std::array<int,2> t = {0, 0};
    auto & head_x = h[0]; auto & head_y = h[1];
    auto & tail_x = t[0]; auto & tail_y = t[1];
    footprint.insert(t);
    while(std::getline(input_file, line)) {
        std::istringstream ss(line);
        char direction;
        int steps;
        ss >> direction >> steps;
        for(int i = 0; i < steps; ++i) {
            switch(direction) { // kinda ungly, maybe fix with vector math
                case    UP: head_y++;
                break;
                case  DOWN: head_y--;
                break;
                case  LEFT: head_x--;
                break;
                case RIGHT: head_x++;
                break;
            }
            bool check = false;
            for (int dx = -1; dx <= 1; dx++)
                for (int dy = -1; dy <= 1; dy++)
                    if(tail_x + dx == head_x && tail_y + dy == head_y) check = true;

            if(check == false) {
                if(head_x > tail_x) tail_x++;
                else if(head_x < tail_x) tail_x--;

                if(head_y > tail_y) tail_y++;
                else if(head_y < tail_y) tail_y--;
            }

            footprint.insert(t);
        }
    }
    std::cout << footprint.size() << std::endl;

    return 0;
}