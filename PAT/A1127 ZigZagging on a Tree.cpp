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

vector<int> inOrder;
vector<int> postOrder;

struct node {
    int value = -1;
    node *left = nullptr, *right = nullptr;
};

node *InPostBuildTree(int inBegin, int inEnd, int postBegin, int postEnd) {
    if (postBegin > postEnd) {
        return nullptr;
    }
    node *root = new node;
    int v = postOrder[postEnd];
    root->value = v;
    int k = inBegin;
    while (inOrder[k] != v) k++;
    int numLeft = k - inBegin;
    root->left = InPostBuildTree(inBegin, k - 1, postBegin, postBegin + numLeft - 1);
    root->right = InPostBuildTree(k + 1, inEnd, postBegin + numLeft, postEnd - 1);
    return root;
}

vector<int> result[32];
int layer = 0;

void zigzaggingOrder(node *root) {
    // 曲折遍历，层序遍历加难版本，先左后右的顺序。
    // 思路1,层序遍历，结果入result vector，之后决定输出，需要多开一个空间.
//    思路2,BFS,
// 但是，最重要的是，无论哪种方法，都不能边边里边输出。
    if (root == nullptr) return;
    queue<node *> Queue;
    Queue.push(root);
    Queue.push(nullptr);
    while (!Queue.empty()) {
        node *v = Queue.front();
        Queue.pop();
        if (v == nullptr) {
            if (Queue.empty()) {
                continue;
            } else {
                layer++;
                Queue.push(nullptr);
            }
        } else {
            result[layer].push_back(v->value);
            if (v->left != nullptr) Queue.push(v->left);
            if (v->right != nullptr) Queue.push(v->right);
        }
    }
}

void showResult() {
    bool isFirst = true;
    for (int j = 0; j <= layer; ++j) {
        if (j % 2 == 0) {
            for (int i = int(result[j].size()) - 1; i >= 0; --i) {
                if (isFirst) {
                    printf("%d", result[j][i]);
                    isFirst = false;
                } else {
                    printf(" %d", result[j][i]);
                }
            }
        } else {
            for (int i : result[j]) {
                if (isFirst) {
                    printf("%d", i);
                    isFirst = false;
                } else {
                    printf(" %d", i);
                }
            }
        }
    }
}

int pat_solver() {
    int N, _1;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_1);
        inOrder.push_back(_1);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_1);
        postOrder.push_back(_1);
    }
    node *root = InPostBuildTree(0, N - 1, 0, N - 1);
    zigzaggingOrder(root);
    showResult();

    return 0;
}

/*
测试样例



*/