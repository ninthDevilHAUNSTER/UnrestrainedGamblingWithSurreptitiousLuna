//
// Created by shaob on 2020/3/4.
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

using namespace std;
#define MaxSize 0x3fffffff

struct node {
    bool is_parent = false;
    vector<int> child;
} family[110];

int N, M; // N 点个数 M 非叶节点个数
int depthNum[110] = {0};
pair<int, int> opt;

void DFS(int id, int depth) {
    depthNum[depth]++; // 这里叶节点和非叶节点都要加一的喔，他问的是层上的节点数不是叶子数
    for (auto c: family[id].child) {
        DFS(c, depth + 1);
    }
}

int pat_solver() {
    int _, __, ___;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        scanf("%d %d", &_, &__);
        family[_].is_parent = true;
        for (int j = 0; j < __; ++j) {
            scanf("%d", &___);
            family[_].child.push_back(___);
        }
    }
    DFS(1, 1);
    for (int k = 0; k < 110; ++k) {
        if (depthNum[k] > opt.first) {
            opt.first = depthNum[k];
            opt.second = k;
        }
    }
    printf("%d %d", opt.first, opt.second);
    return 0;
}

/*
测试样例



*/