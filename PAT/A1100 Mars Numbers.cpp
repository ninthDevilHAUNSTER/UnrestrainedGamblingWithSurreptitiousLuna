//
// Created by shaob on 2020/3/1.
//


#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<int, string> num2mars;
map<string, int> mars2num;

string number[27] = {
        "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec", // 0-D
        "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou", // 1x - Dx
        ""
};

int __init__() {
    for (int i = 0; i < 169; ++i) {
        if (i <= 12) {
            num2mars[i] = number[i];
            mars2num[number[i]] = i;
        } else {
            string m;
            int ge = (i % 13 == 0) ? 26 : i % 13;
            int shi = (i / 13 == 0) ? 13 : i / 13;
            if (ge == 26) {
                m = number[13 + shi];
            } else {
                m = number[13 + shi] + " " + number[ge];
            }
            num2mars[i] = m;
            mars2num[m] = i;
        }
    }
//    for (auto i:num2mars) {
//        printf("%d :: %s\t|\t", i.first, i.second.c_str());
//        if (i.first % 12 == 0)printf("\n");
//    }
    return 0;
}

int pat_solver() {
    __init__();
    char z[20];
    string s;
    int _;
    scanf("%d\n", &_);
    for (int i = 0; i < _; ++i) {
        cin.getline(z, 20);
        s = z;
        if (s[0] >= '0' && s[0] <= '9') {
            cout << num2mars[stoi(s)] << endl;
        } else {
            cout << mars2num[s] << endl;
        }
    }
}