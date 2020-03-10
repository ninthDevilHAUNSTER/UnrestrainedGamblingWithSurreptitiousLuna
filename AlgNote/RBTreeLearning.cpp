//
// Created by shaob on 2020/3/10.
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

/*
 * 这道题很重要，非常重要。
 */

struct node {
    int value = -1;
    bool isBlack = true;
    node *left = nullptr, *right = nullptr;

    node() = default;

    explicit node(int _v) : value(abs(_v)), isBlack(_v > 0) {};
};

node *build(node *p, int value) {
    if (p == nullptr) {
        p = new node(value);
        return p;
    }
    if (abs(value) < p->value) {
        p->left = build(p->left, value);
    } else {
        p->right = build(p->right, value);
    }
    return p;
}

int caseNum;

bool judgeCorrectNodeColor(node *p) {
    if (p == nullptr) return true;
    if (!p->isBlack) { // 红色
        if (p->left != nullptr && !p->left->isBlack) return false; // 是否为红色？
        if (p->right != nullptr && !p->right->isBlack) return false;
    }
    return judgeCorrectNodeColor(p->left) && judgeCorrectNodeColor(p->right);
}

int getBlackNodeNumber(node *p) {
    if (p == nullptr) return 0;
    int left = getBlackNodeNumber(p->left);
    int right = getBlackNodeNumber(p->right);
    return p->isBlack ? max(left, right)+1 : max(right, left);
}

bool judgeBlackNodeNumber(node *p) {
    /*
     * 判断左右子树的黑色节点叶子数量是否相同
     */
    if (p == nullptr) return true;
    int left = getBlackNodeNumber(p->left);
    int right = getBlackNodeNumber(p->right);
    if (left != right) return false;
    return judgeBlackNodeNumber(p->left) && judgeBlackNodeNumber(p->right);
}

int alg_solver() {
    scanf("%d", &caseNum);
    int nodeNum, _v;
    for (int i = 0; i < caseNum; ++i) {
        node *p = nullptr;
        scanf("%d", &nodeNum);
        for (int j = 0; j < nodeNum; ++j) {
            scanf("%d", &_v);
            p = build(p, _v);
        }
        if (p == nullptr) {
            printf("No\n");
            continue;
        }
        if (!p->isBlack) {
            printf("No\n");
            continue;
        }
        if (!judgeCorrectNodeColor(p)) {
            printf("No\n");
            continue;
        }
        if (!judgeBlackNodeNumber(p)) {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
    }
    return 0;
}

/*
测试样例



*/