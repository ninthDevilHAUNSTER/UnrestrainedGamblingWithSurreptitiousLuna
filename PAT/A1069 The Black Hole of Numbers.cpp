//
// Created by shaob on 2020/2/29.
//

#include <iostream>
// 输出两个递增序列的中位数
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp1(const int &a, const int &b) {
    return a < b;
}

bool cmp2(const int &a, const int &b) {
    return a > b;
}

vector<int> gen_vec(int num) {
    vector<int> vec;
    do {
        vec.push_back(num % 10);
        num /= 10;
    } while (num != 0);
    while (vec.size() < 4) vec.push_back(0);
    return vec;
}

void black_hole(vector<int> &v) {
    int small = 0, big = 0;
    sort(v.begin(), v.end(), cmp1);
    small = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
    big = v[0] + v[1] * 10 + v[2] * 100 + v[3] * 1000;
    printf("%04d - %04d = %04d\n", big, small, big - small);
    if (big - small == 6174 || small == big) {
        return;
    } else {
        int num = big - small;
        vector<int> vec = gen_vec(num);
        black_hole(vec);
    }
}

int pat_solver() {
    int _;
    vector<int> input;
    scanf("%d", &_);
    input = gen_vec(_);
    black_hole(input);
    return 0;
}