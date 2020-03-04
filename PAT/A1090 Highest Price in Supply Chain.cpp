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
#define MaxSize 100010

struct node {
    vector<int> child;
} node[MaxSize];
int N;
double P, r;
pair<double, int> opt(-1, 0);

void DFS(int visit_id, int layer) {
    if (node[visit_id].child.empty()) {
        double sum = layer;
        if (sum > opt.first) {
            opt.first = sum;
            opt.second = 1;
        } else if (opt.first == sum) {
            opt.second++;
        }
        return;
    }
    for (auto id: node[visit_id].child) {
        DFS(id, layer + 1);
    }
}

int pat_solver() {
    scanf("%d %lf %lf", &N, &P, &r);
    int _;
    int root_id = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_);
        if (_ == -1) {
            root_id = i;
        } else {
            node[_].child.push_back(i);
        }
    }
    DFS(root_id, 0);
    printf("%.02f %d", pow(1 + 0.01 * r, opt.first) * P, opt.second);
    return 0;
}

/*
测试样例

9 1.80 1.00
1 5 4 4 -1 4 5 3 6


*/