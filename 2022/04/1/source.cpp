#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <utility>

using Id_t = int;
using Ids_t = std::vector<int>;
using PId_t = std::pair<Ids_t, Ids_t>;
using PIds_t = std::vector<PId_t>;

int main() {

    PIds_t data;
    std::ifstream input_file("../input.txt");
    std::string line;

    while(std::getline(input_file, line)) {
        int r1, r2, r3, r4;
        char x, y, z;
        std::istringstream input_stream(line);
        input_stream >> r1 >> x >> r2 >> y >> r3 >> z >> r4;
        Ids_t i1, i2;
        i1.resize(std::abs(r2 - r1) + 1);
        i2.resize(std::abs(r3 - r4) + 1);
        std::iota(std::begin(i1), std::end(i1), r1);
        std::iota(std::begin(i2), std::end(i2), r3);
        data.push_back(std::make_pair(i1, i2));
    }

    int sum = 0;
    std::for_each(std::begin(data), std::end(data), [&sum](auto & element){
        auto & v1 = element.first;
        auto & v2 = element.second;
        std::vector<char> v_intersection;
        std::set_intersection(v1.begin(), v1.end(),
                            v2.begin(), v2.end(),
                            std::back_inserter(v_intersection));
        auto size = v_intersection.size();
        if(size == v1.size() || size == v2.size()) sum++;
    });

    std::cout << sum << std::endl;

    return 0;
}