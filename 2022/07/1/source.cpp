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
#include <unordered_map>
#include <cctype>


int main() {
    std::unordered_map<std::string, int> directories;
    std::deque<std::string> tree;

    std::ifstream input_file("../input.txt");
    std::string line;

    while(std::getline(input_file, line)) {
        std::stringstream ss(line);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end; // end-of-stream iterator
        std::vector<std::string> cmd(begin, end);

        if(!cmd[1].compare("ls") || !cmd[0].compare("dir")) {
            continue; // ignore these commands
        } else if(!cmd[1].compare("cd")) {
            if(!cmd[2].compare("..")) {
                // leave current folder
                tree.pop_front();
            } else { // got to new folder
                std::string path;
                std::for_each(std::begin(tree), std::end(tree), [&path](auto & dir){
                    path += dir;
                });
                tree.push_front(path + cmd[2]);
                directories[tree.front()] = 0;
            }
        } else { // file
            std::for_each(std::begin(tree), std::end(tree), [&](auto & dir){
                directories[dir] += std::stoi(cmd[0]); // add the file size of all folders
            });
        }
    }

    int result = 0;
    std::for_each(std::begin(directories), std::end(directories), [&result](auto & dir){
        auto & size = dir.second;
        if(size <= 100000) result += size;
    });

    std::cout << result  << std::endl;
    return 0;
}