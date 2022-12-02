#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <utility>

enum Move {RockA = 'A', PaperA = 'B', ScissorA = 'C',RockB = 'X', PaperB = 'Y', ScissorB = 'Z'};
enum Decision {Lose = 'X', Draw = 'Y', Win = 'Z'};
using play_t = std::pair<Move, Decision>;
using plays_t = std::vector<play_t>;

int main() {

    plays_t moves;
    int total = 0;

    std::ifstream input_file("../input.txt");


    std::string line;
    while(std::getline(input_file, line))
    {
        if(line.empty()) {
            //...
        } else {
            std::istringstream input_stream(line);
            char a, b;
            input_stream >> a;
            input_stream >> b;
            moves.push_back(std::make_pair(static_cast<Move>(a), static_cast<Decision>(b)));
        }
    }

    std::for_each(moves.begin(), moves.end(), [&total](play_t p){
        auto & move = p.first;
        auto & decision = p.second;

        switch (move) {
            case Move::RockA:
                if(decision == Decision::Win) total += (6 + 2);
                if(decision == Decision::Draw) total += (3 + 1);
                if(decision == Decision::Lose) total += (0 + 3);
            break;
            case Move::PaperA:
                if(decision == Decision::Win) total += (6 + 3);
                if(decision == Decision::Draw) total += (3 + 2);
                if(decision == Decision::Lose) total += (0 + 1);
            break;
            case Move::ScissorA:
                if(decision == Decision::Win) total += (6 + 1);
                if(decision == Decision::Draw) total += (3 + 3);
                if(decision == Decision::Lose) total += (0 + 2);
            break;
            default:
            break;
        }
    });

    std::cout << "total: " << total << std::endl;

    return 0;
}