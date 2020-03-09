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
// 这道题是408的原题，当然你要建树

struct node {
    int left = -1;
    int right = -1;
    string value{};
    bool isRoot = true;
} BTree[24];

void InOrder(int v, bool isFirst) {
    if (!(isFirst || (BTree[v].left == -1 && BTree[v].right == -1))) cout << "(";
    if (BTree[v].left != -1) InOrder(BTree[v].left, false);
    cout << BTree[v].value;
    if (BTree[v].right != -1) InOrder(BTree[v].right, false);
    if (!(isFirst || (BTree[v].left == -1 && BTree[v].right == -1))) cout << ")";
}

int pat_solver() {
    int N, _l, _r;
    string buffer;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        cin >> buffer >> _l >> _r;
        BTree[i].left = _l;
        BTree[i].right = _r;
        BTree[i].value = move(buffer);
        _l != -1 ? BTree[_l].isRoot = false : 0;
        _r != -1 ? BTree[_r].isRoot = false : 0;
    }
    int root = 1;
    while (!BTree[root].isRoot) root++;
    InOrder(root, true);
    return 0;
}

/*
测试样例



*/