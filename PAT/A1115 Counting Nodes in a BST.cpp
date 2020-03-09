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

struct node {
    int value = -INF;
    node *left = nullptr;
    node *right = nullptr;
};

node *Insert(node *p, int value) {
    if (p == nullptr) {
        p = new node;
        p->value = value;
    } else {
        if (p->value >= value) {
            p->left = Insert(p->left, value);
        } else {
            p->right = Insert(p->right, value);
        }
    }
    return p;
}

vector<int> layerNodeNum;

void layerVisit(node *p) {
    if (p == nullptr) return;
    queue<node *> Queue;
    node *now = new node;
    Queue.push(p);
    Queue.push(nullptr);
    int current_layer_number = 0;
    while (!Queue.empty()) {
        now = Queue.front();
        Queue.pop();
        if (now == nullptr) {
            layerNodeNum.push_back(current_layer_number);
            current_layer_number = 0;
            if (Queue.empty()) {
                continue;
            } else {
                Queue.push(nullptr);
            }
        } else {
            current_layer_number++;
            if (now->left != nullptr) Queue.push(now->left);
            if (now->right != nullptr) Queue.push(now->right);
        }
    }
}

int maxdepth = -1;
int num[1024] = {0};

void dfs(node *root, int depth) {
    if (root == NULL) {
        maxdepth = max(depth, maxdepth);
        return;
    }
    num[depth]++;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}

int N;

int pat_solver() {
    node *root = nullptr;
    int _v;
    scanf("%d", &N);
    if (N == 0) {
        printf("0 + 0 = 0");
        return 0;
    }
    if (N == 1) {
        printf("1 + 0 = 1");
        return 0;
    }
    if (N == 2) {
        printf("1 + 1 = 2");
        return 0;
    }

    for (int i = 0; i < N; ++i) {
        scanf("%d", &_v);
        root = Insert(root, _v);
    }
    dfs(root, 0);
//    layerVisit(root);
//    int n1 = layerNodeNum.back();
//    layerNodeNum.pop_back();
//    int n2 = layerNodeNum.back();
    printf("%d + %d = %d", num[maxdepth - 1], num[maxdepth - 2], num[maxdepth - 1] +
                                                                 num[maxdepth - 2]);
//    printf("%d + %d = %d", n1, n2, n1 + n2);
    return 0;
}

/*
测试样例



*/