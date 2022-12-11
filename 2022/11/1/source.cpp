#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

struct Monkey{
    int id;
    int inspect;
    int if_true;
    int if_false;
    int inspects;
    std::vector<int> items;
    std::string operation[2];
};

int main() {
    std::vector<Monkey> monkeys;

    Monkey m;
    m.inspects = 0;
    // Yes, I know this is insane. I'm insane. I'm going insane. Send help.
    m.id = 0;
    m.inspect = 2;
    m.if_true = 4;
    m.if_false = 7;
    m.items.push_back(84);
    m.items.push_back(66);
    m.items.push_back(62);
    m.items.push_back(69);
    m.items.push_back(88);
    m.items.push_back(91);
    m.items.push_back(91);
    m.operation[0] = "*";
    m.operation[1] = "11";
    monkeys.push_back(m);
    m.items.clear();

    m.id = 1;
    m.inspect = 7;
    m.if_true = 3;
    m.if_false = 6;
    m.items.push_back(98);
    m.items.push_back(50);
    m.items.push_back(76);
    m.items.push_back(99);
    m.operation[0] = "*";
    m.operation[1] = "old";
    monkeys.push_back(m);
    m.items.clear();

    m.id = 2;
    m.inspect = 13;
    m.if_true = 4;
    m.if_false = 0;
    m.items.push_back(72);
    m.items.push_back(56);
    m.items.push_back(94);
    m.operation[0] = "+";
    m.operation[1] = "1";
    monkeys.push_back(m);
    m.items.clear();

    m.id = 3;
    m.inspect = 3;
    m.if_true = 6;
    m.if_false = 5;
    m.items.push_back(55);
    m.items.push_back(88);
    m.items.push_back(90);
    m.items.push_back(77);
    m.items.push_back(60);
    m.items.push_back(67);
    m.operation[0] = "+";
    m.operation[1] = "2";
    monkeys.push_back(m);
    m.items.clear();

    m.id = 4;
    m.inspect = 19;
    m.if_true = 1;
    m.if_false = 7;
    m.items.push_back(69);
    m.items.push_back(72);
    m.items.push_back(63);
    m.items.push_back(60);
    m.items.push_back(72);
    m.items.push_back(52);
    m.items.push_back(63);
    m.items.push_back(78);
    m.operation[0] = "*";
    m.operation[1] = "13";
    monkeys.push_back(m);
    m.items.clear();

    m.id = 5;
    m.inspect = 17;
    m.if_true = 2;
    m.if_false = 0;
    m.items.push_back(89);
    m.items.push_back(73);
    m.operation[0] = "+";
    m.operation[1] = "5";
    monkeys.push_back(m);
    m.items.clear();

    m.id = 6;
    m.inspect = 11;
    m.if_true = 2;
    m.if_false = 5;
    m.items.push_back(78);
    m.items.push_back(68);
    m.items.push_back(98);
    m.items.push_back(88);
    m.items.push_back(66);
    m.operation[0] = "+";
    m.operation[1] = "6";
    monkeys.push_back(m);
    m.items.clear();

    m.id = 7;
    m.inspect = 5;
    m.if_true = 1;
    m.if_false = 3;
    m.items.push_back(70);
    m.operation[0] = "+";
    m.operation[1] = "7";
    monkeys.push_back(m);
    m.items.clear();

    for(int i = 0; i < 20; ++i) {
        std::for_each(std::begin(monkeys), std::end(monkeys), [&monkeys](auto & monkey){
            std::for_each(std::begin(monkey.items), std::end(monkey.items), [&monkey, &monkeys](auto item){
                monkey.inspects++;
                if(!monkey.operation[0].compare("+")) {
                    if(!monkey.operation[1].compare("old")) {
                        item = item + item;
                    } else {
                        item = item + std::stoi(monkey.operation[1]);
                    }
                } else { // "*"
                    if(!monkey.operation[1].compare("old")) {
                        item = item * item;
                    } else {
                        item = item * std::stoi(monkey.operation[1]);
                    }
                }
                item = std::floor(item / 3);
                (item % monkey.inspect) ? monkeys[monkey.if_false].items.push_back(item) : monkeys[monkey.if_true].items.push_back(item);
            }); monkey.items.clear();
        });
    }

    std::sort(std::begin(monkeys), std::end(monkeys), [](auto & a, auto & b){ return a.inspects > b.inspects; });
    int result = monkeys[0].inspects * monkeys[1].inspects;

    std::cout << result << std::endl;    

    return 0;
}