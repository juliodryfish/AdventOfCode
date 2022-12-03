#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>
#include <numeric>
#include <utility>
#include <cctype>

using Rucksack_t = std::string;
using Group_t = std::array<Rucksack_t, 3>;
using Groups_t = std::vector<Group_t>;

int main() {

    std::ifstream input_file("../input.txt");
    Groups_t data;

    std::string str1;
    std::string str2;
    std::string str3;

    while(std::getline(input_file, str1) && std::getline(input_file, str2) && std::getline(input_file, str3)) {
        std::array<Rucksack_t, 3> x = {str1, str2, str3};
        data.push_back(x);
    }

    int sum = 0;
    std::for_each(std::begin(data), std::end(data), [&sum](auto & element){
        auto & v1 = element[0];
        auto & v2 = element[1];
        auto & v3 = element[2];

        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());
        std::sort(v3.begin(), v3.end());

        std::vector<char> v_intersection_1;
        std::set_intersection(v1.begin(), v1.end(),
                            v2.begin(), v2.end(),
                            std::back_inserter(v_intersection_1));
        
        std::vector<char> v_intersection_2;
        std::set_intersection(v_intersection_1.begin(), v_intersection_1.end(),
                            v3.begin(), v3.end(),
                            std::back_inserter(v_intersection_2));

        if(std::islower(v_intersection_2[0])) {
            sum += v_intersection_2[0] - 96;
        } else {
            sum += v_intersection_2[0] - 64 + 26;
        }
    });

    std::cout << sum << std::endl;

    return 0;
}