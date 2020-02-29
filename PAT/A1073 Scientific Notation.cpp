//
// Created by shaob on 2020/2/25.
//

#include <iostream>
#include <cctype>
#include <string>
#include <utility>

using namespace std;

struct ScientificNum {
    bool flag = false;
    bool bias_flag = false;
    string base;
    string power;

    ScientificNum() = default;

    ScientificNum(string _b, string _p) : base(std::move(_b)), power(std::move(_p)) {}
};

int pat_solver() {
    string input;
    cin >> input;
    ScientificNum num;
    num.flag = input[0] == '+';
    input.erase(input.begin());
    int Epos = input.find('E');
    num.bias_flag = input[Epos + 1] == '+';
    num.base = input.substr(0, Epos);
    if (num.base.find('.') != string::npos)
        num.base.erase(num.base.begin() + num.base.find('.'));
    num.power = input.substr(Epos + 1);
//    cout << num.base << "\t" << stoi(num.power);

    if (!num.flag)
        printf("-");
    if (!num.bias_flag) {
        printf("0.");
        for (int i = 0; i < -stoi(num.power)-1; ++i) {
            printf("0");
        }
        printf("%s", (num.base).c_str());
    } else {
        // 考虑一下长度
        int size_base = num.base.size();
        printf("%s", (num.base).c_str());
    }
    return 0;
}