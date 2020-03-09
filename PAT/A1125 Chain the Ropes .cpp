//
// Created by shaob on 2020/3/9.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <cassert>
#include <cmath>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff

vector<double> chain;
// 有点像哈夫曼编码
double len = 0.0;

int N;

int pat_solver() {
    scanf("%d", &N);
    double _;
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &_);
        chain.push_back(_);
    }
    sort(chain.begin(), chain.end(), greater<>()); // 因为是除以二的，所以最小的两个相加的平均值一定是在下一轮中取到的。
    // 如果没有除二，那就要把它放到循环体内了。
    while (1) {
        len = (*(chain.end() - 2) + *(chain.end() - 1)) / 2;
        if (chain.size() == 2) {
            printf("%d", int(floor(len)));
            break;
        }
        chain.pop_back();
        chain.pop_back();
        chain.push_back(len);
    }
    return 0;
}

/*
测试样例



*/