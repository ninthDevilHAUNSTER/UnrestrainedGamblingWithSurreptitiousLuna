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

bool isCompleteBT(node *x) {
    queue<node *> Q;
    Q.push(x);
    while (!Q.empty()) {
        node *v = Q.front();
        Q.pop();
        if (v->rchild != nullptr && v->lchild != nullptr) {
            Q.push(v->lchild);
            Q.push(v->rchild);
        } else if (v->lchild == nullptr && v->rchild != nullptr) {
            return false; // 左子树空右子树非空，直接返回错，不多BB
        } else {
            if (v->lchild != nullptr && v->rchild == nullptr) {
                // 左子树非空，右子树空，则该节点必须为最后一个非叶节点
                Q.push(v->lchild);
            }
            // 否则，该节点一定是叶子节点。对此，如果该节点如果不是叶子节点直接返回false；
            while (!Q.empty()) {
                v = Q.front();
                Q.pop();
                if (v->lchild != nullptr || v->rchild != nullptr)
                    return false;
            }
        }
    }
    return true;
}

void layerOrder(node *x) {
    queue<node *> Q;
    Q.push(x);
    bool _1flag = true;
    while (!Q.empty()) {
        node *v = Q.front();
        if (_1flag) {
            printf("%d", v->v);
            _1flag = false;
        } else {
            printf(" %d", v->v);
        }
        Q.pop();
        if (v->lchild != nullptr) Q.push(v->lchild);
        if (v->rchild != nullptr) Q.push(v->rchild);
    }
}

int pat_solver() {
    int _, __;
    scanf("%d", &_);
    for (int i = 0; i < _; ++i) {
        scanf("%d", &__);
        numList.push_back(__);
    }
    node *root = create();
    layerOrder(root);
    printf("\n");
    if (isCompleteBT(root)) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}

/*
测试样例



*/
