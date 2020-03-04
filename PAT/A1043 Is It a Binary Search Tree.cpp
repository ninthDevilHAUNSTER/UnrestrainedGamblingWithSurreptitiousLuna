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
#define INF 0x3fffffff

struct node {
    int data = INF;
    node *lchild = nullptr;
    node *rchild = nullptr;
};


void BST_insert(node *&r, int data) {
    if (r == nullptr) {
        r = new node;
        r->data = data;
    } else {
        if (data < r->data) BST_insert(r->lchild, data);
        else BST_insert(r->rchild, data);
    }
}

int N;
vector<int> input;
vector<int> result;

void PreOrder(node *pNode) {
    if (pNode == nullptr)return;
    result.push_back(pNode->data);
    if (pNode->lchild != nullptr) PreOrder(pNode->lchild);
    if (pNode->rchild != nullptr) PreOrder(pNode->rchild);
}

void MPreOrder(node *pNode) {
    if (pNode == nullptr)return;
    result.push_back(pNode->data);
    if (pNode->rchild != nullptr) MPreOrder(pNode->rchild);
    if (pNode->lchild != nullptr) MPreOrder(pNode->lchild);
}

int num = 0;

void PostOrder(node *pNode) {
    if (pNode == nullptr) return;
    if (pNode->lchild != nullptr) PostOrder(pNode->lchild);
    if (pNode->rchild != nullptr) PostOrder(pNode->rchild);
    printf("%d", pNode->data);
    if (num < N - 1) printf(" ");
    num++;
}

void MPostOrder(node *pNode) {
    if (pNode == nullptr) return;
    if (pNode->rchild != nullptr) MPostOrder(pNode->rchild);
    if (pNode->lchild != nullptr) MPostOrder(pNode->lchild);
    printf("%d", pNode->data);
    if (num < N - 1) printf(" ");
    num++;
}


int pat_solver() {
    node *root= nullptr;
    scanf("%d", &N);
    int _;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_);
        BST_insert(root, _);
        input.push_back(_);
    }
    PreOrder(root);
    if (result == input) {
        printf("YES\n");
        PostOrder(root);
        return 0;
    } else {
        result.clear();
        MPreOrder(root);
        if (result == input) {
            printf("YES\n");
            MPostOrder(root);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

/*
测试样例



*/