#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <utility>
#include <cctype>

using CompartmentA_t = std::string;
using CompartmentB_t = std::string;
using Rucksack_t = std::pair<CompartmentA_t, CompartmentB_t>;
using Rucksacks_t = std::vector<Rucksack_t>;

int main() {

    std::ifstream input_file("../input.txt");
    Rucksacks_t data;
    std::string line;

    while(std::getline(input_file, line)) {
        if(line.empty()) {
            //...
        } else {
            data.push_back(std::make_pair(
                line.substr(0, line.length()/2), line.substr(line.length()/2)
                )
            );
        }
    }

    int sum = 0;

    std::for_each(std::begin(data), std::end(data), [&sum](auto & element) {
        auto & v1 = element.first;
        auto & v2 = element.second;

        std::vector<char> v_intersection;
        
        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());
        std::set_intersection(v1.begin(), v1.end(),
                            v2.begin(), v2.end(),
                            std::back_inserter(v_intersection));

        auto & c = v_intersection[0];
        if(std::islower(c)) {
            sum += c - 96;
        } else {
            sum += c - 64 + 26;
        }
    });

    std::cout << sum << std::endl;

    return 0;
}