//
// Created by shaob on 2020/3/20.
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
#include <unordered_set>
#include <unordered_map>

using namespace std;
// 之后练一下unorder_set的用法？
#define INF 0x3fffffff
#define inf 0x3fffffff
typedef long long LL;

int n;
int RANK[5]; // 0,1,2,3,4

struct Node {
    LL x = 0;
    LL y = 0;
//    mutable int cnt{};

    bool operator==(const Node &B) const {
        return (x == B.x) && (y == B.y);
    }

    bool operator<(const Node &B) const {
        return (x <= B.x) && (y <= B.y);
    }

    Node() = default;

    Node(LL _1, LL _2) : x(_1), y(_2) {};
};

struct record_hash {
    size_t operator()(const struct Node &_r) const {
        LL tmp = _r.x + _r.y * 13; // 问就是魔法
        return std::hash<LL>()(tmp);
    }
};

//unordered_set<Node, record_hash> Net;
set<pair<int, int>> Net;

bool find(int _x, int _y) {
    return !(Net.find(pair<int, int>(_x, _y)) == Net.end());
}

int getRank(pair<int, int> o) {
    int rt = 0;
    rt += find(o.first + 1, o.second + 1);
    rt += find(o.first - 1, o.second - 1);
    rt += find(o.first + 1, o.second - 1);
    rt += find(o.first - 1, o.second + 1);
    return rt;
}

int ccf_solver() {
    scanf("%d", &n);
    LL _1, _2;
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &_1, &_2);
        Net.insert(pair<int, int>(_1, _2));
    }
    for (auto &node : Net) {
        if (find(node.first + 1, node.second) && find(node.first - 1, node.second) &&
            find(node.first, node.second + 1) && find(node.first, node.second - 1)) {
            RANK[getRank(node)]++;
        }
    }
    for (auto i:RANK) {
        printf("%d\n", i);
    }
    return 0;
}

/*
测试样例



*/