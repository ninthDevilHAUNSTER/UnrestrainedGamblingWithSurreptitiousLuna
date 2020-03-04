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
    int v = -1;
    int height = 1;
    node *lchild = nullptr;
    node *rchild = nullptr;
};

int getHeight(node *root) {
    if (root == nullptr) return 0;
    else return root->height;
}

int _getBalanceFactor(node *root) {// 骚逼写法...
    return (root->lchild == nullptr ? 0 : root->lchild->height) -
           (root->rchild == nullptr ? 0 : root->rchild->height);
}

int getBalanceFactor(node *root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node *root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void L(node *&root) {
    /*
     * 左旋操作
     * 画图-》更新高度-》root=tmp
     */
    node *tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root; // 这个过程可以自己画图理解
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void R(node *&root) {
    node *tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void _insert(node *&root, int v) {
    /*
     * BST 的插入操作
     */
    if (root == nullptr) {
        root = new node;
        root->v = v;
        return;
    }
    if (root->v < v) {
        _insert(root->lchild, v);
    } else {
        _insert(root->rchild, v);
    }
}

void insert(node *&root, int v) {
    if (root == nullptr) {
        root = new node;
        root->v = v;
        return;
    }
    if (v < root->v) {
        insert(root->lchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) {
                R(root);
            } else if (getBalanceFactor(root->lchild) == -1) {
                L(root->lchild);
                R(root);
            }
        }
    } else {
        insert(root->rchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild) == -1) {
                L(root);
            } else if (getBalanceFactor(root->rchild) == 1) {
                R(root->rchild);
                L(root);
            }
        }
    }
}

vector<int> numList;

node *create() {
    node *root = nullptr;
    for (auto i : numList) {
        insert(root, i);
    }
    return root;
}

int alg_solver() {
    int _, __;
    scanf("%d", &_);
    for (int i = 0; i < _; ++i) {
        scanf("%d", &__);
        numList.push_back(__);
    }
    node *root = create();
    printf("%d", root->v);
    return 0;
}

/*
测试样例



*/