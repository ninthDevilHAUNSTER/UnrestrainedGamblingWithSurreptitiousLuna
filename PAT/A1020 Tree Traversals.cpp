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
#include <queue>
#include <algorithm>

using namespace std;
#define MaxSize 0x3fffffff

/*
 * 又是一个老话题了。二叉树的建立。顺便把二叉树的代码复习一下。
 */

int N;
int postVisit[30];
int inVisit[30];
vector<int> result;
struct node {
    int data = 0;
    node *lchild = nullptr;
    node *rchild = nullptr;
};

node *PostAddInCreateTree(int postL, int postR, int inL, int inR) {
    if (postL > postR) {
        return nullptr;
    }
    node *root = new node;
    root->data = postVisit[postR];
    int k;
    for (k = inL; k <= inR; ++k) {
        if (inVisit[k] == postVisit[postR]) break;
    }
    int numLeft = k - inL;
    root->lchild = PostAddInCreateTree(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = PostAddInCreateTree(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

void layerVisit(node *root) {
    queue<node *> Q;
    node *p = new node;
    if (root != nullptr) {
        Q.push(root);
    } else {
        return;
    }
    int num = 0;
    while (!Q.empty()) {
        p = Q.front();
        printf("%d", Q.front()->data);
        num++;
        if (num < N) printf(" ");
        Q.pop();
        if (p->lchild != nullptr) Q.push(p->lchild);
        if (p->rchild != nullptr) Q.push(p->rchild);
    }
}

int pat_solver() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &postVisit[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &inVisit[i]);
    }
    node *root = PostAddInCreateTree(0, N - 1, 0, N - 1);
    layerVisit(root);
    return 0;
}