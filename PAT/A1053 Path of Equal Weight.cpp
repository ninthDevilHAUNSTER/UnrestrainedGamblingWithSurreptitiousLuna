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
typedef long long LL;
struct node {
    int id = -1;
    LL weight = 0;
    vector<int> child;
    bool is_root = true;
} Tree[110];

vector<vector<int>> resultPath;
vector<int> tmpPath;
int N, M;
LL S;


bool cmp(const vector<int> &a, const vector<int> &b) {
//    if (a.size() != b.size()) {
//        return a.size() < b.size();
//    } else {
    for (int i = 0; i < min(a.size(), b.size()); ++i) {
        if (Tree[a[i]].weight != Tree[b[i]].weight) {
            return Tree[a[i]].weight > Tree[b[i]].weight;
        }
    }
//    }
    return true;
}

bool cmp2(int a, int b) {
    return Tree[a].weight > Tree[b].weight;
}

void DFS(int root_id, LL sum) {
    if (sum > S) return;
    if (Tree[root_id].child.empty() && sum == S) {
        tmpPath.push_back(root_id);
        for (int i = 0; i < tmpPath.size(); ++i) {
            printf("%lld", Tree[tmpPath[i]].weight);
            if (i < tmpPath.size() - 1)printf(" ");
        }
        printf("\n");
        tmpPath.pop_back();
    }
    tmpPath.push_back(root_id);
    for (auto c :Tree[root_id].child) {
        DFS(c, sum + Tree[c].weight);
    }
    tmpPath.pop_back();
}

void DFS2(int root_id, LL sum) {
    if (sum > S) return;
    if (Tree[root_id].child.empty() && sum == S) {
        tmpPath.push_back(root_id);
        resultPath.push_back(tmpPath);
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(root_id);
    sort(Tree[root_id].child.begin(), Tree[root_id].child.end(), cmp2);
    for (auto c :Tree[root_id].child) {
        DFS(c, sum + Tree[c].weight);
    }
    tmpPath.pop_back();
}

int pat_solver() {
    scanf("%d %d %lld", &N, &M, &S);
//    tmpPath.resize(N);
    LL _;
    int _id, _num, _c;
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &_);
        Tree[i].weight = _;
        Tree[i].id = i;
    }
    for (int j = 0; j < M; ++j) {
        scanf("%d %d", &_id, &_num);
        for (int i = 0; i < _num; ++i) {
            scanf("%d", &_c);
            Tree[_id].child.push_back(_c);
            Tree[_c].is_root = false;
        }
    }
    int root_id = 0;
    while (!Tree[root_id].is_root) root_id++;
    DFS2(root_id, Tree[root_id].weight);
//    sort(resultPath.begin(), resultPath.end(), cmp);
//    for (const auto &path :resultPath) {
//        for (int i = 0; i < path.size(); ++i) {
//            printf("%lld", Tree[path[i]].weight);
//            if (i < path.size() - 1)printf(" ");
//        }
//        printf("\n");
//    }
    return 0;
}

/*
测试样例



*/