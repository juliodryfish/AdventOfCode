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
        auto & str1 = element.first;
        auto & str2 = element.second;

        for(int i = 0; i < str1.length(); ++i) {
            auto & c1 = str1[i];

            for(int k = 0; k < str2.length(); ++k) {
                auto & c2 = str2[k];
                if(c1 == c2) {
                    if(std::islower(c1)) {
                        sum += c1 - 96;
                    } else {
                        sum += c1 - 64 + 26;
                    }
                    goto end;
                }
            }
        }
end:
        (void)0;
    });

    std::cout << sum << std::endl;

    return 0;
}