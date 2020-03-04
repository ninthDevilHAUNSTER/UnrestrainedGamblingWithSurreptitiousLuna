//
// Created by shaob on 2020/3/4.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
#define MaxSize 100010

struct node {
    double data = -1.0;
    vector<int> child;
} node[MaxSize];
int N;
double P, r;
double sum;

void DFS(int visit_id, int layer) {
    if (node[visit_id].data != -1.0) {
        sum += node[visit_id].data * pow(r*0.01+1, layer);
        return;
    }
    for (auto id: node[visit_id].child) {
        DFS(id, layer+1);
    }
}

int pat_solver() {
    scanf("%d %lf %lf", &N, &P, &r);
    int _, _c;
    double _p;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_);
        if (_ != 0) {
            for (int j = 0; j < _; ++j) {
                scanf("%d", &_c);
                node[i].child.push_back(_c);
            }
        } else {
            scanf("%lf", &_p);
            node[i].data = _p;
        }
    }
    DFS(0, 0);
    printf("%.01lf", sum*P);
    return 0;
}

/*
测试样例

10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3


*/