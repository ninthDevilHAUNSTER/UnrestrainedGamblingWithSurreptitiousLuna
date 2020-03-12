//
// Created by shaob on 2020/3/12.
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
#include <cmath>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff

/*
 * 给一个BST和两个节点U,V。
 * 查找以U,V为后代的最深的节点.
 */

struct node {
    node *left = nullptr;
    node *right = nullptr;
    node *father = nullptr;
    int value = -1;
    int childLocation = -1; // -1 左孩子，1右孩子，0根节点

    node(int _v, node *_f, bool isR) : value(_v), father(_f), childLocation(isR) {};
};

node *create(node *root, node *father, int value, int isR) {
    if (root == nullptr) {
        root = new node(value, father, isR);
    } else {
        if (value < root->value) {
            root->left = create(root->left, root, value, -1);
        } else {
            root->right = create(root->right, root, value, 1);
        }
    }
    return root;
}

node *findNode(node *root, int x) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->value == x) {
        return root;
    } else if (root->value < x) {
        return findNode(root->left, x);
    } else {
        return findNode(root->right, x);
    }
}

//int _findAncestor(node *U, node *V, int &A) {
//    if (U < V) { // 左侧
//        // 方法1 让U变大
//        if (U->childLocation == -1) _findAncestor(U->father, V, A);
//        // 方法2 让V变小
//        if (V->childLocation == 1) _findAncestor(U, V->father, A);
//    }
//}

int findAncestor(node *root, int u, int v, int &A) {
    /*
     * 判断存不存在，不是只要扫描先序序列就行了么。。。
     */
    node *U = findNode(root, u);
    node *V = findNode(root, v); // 这里可以降一些复杂度
    if (U == nullptr && V == nullptr) {
        return -3;
    } else if (V == nullptr) {
        return -2;
    } else if (U == nullptr) {
        return -1;
    }
    return 1;
//    if (u < v) {
//        // u 一定在 v 的左侧
//    }
}


void findRes(node *root, int u, int v, bool flag) {
    if (root == nullptr) return;
    if (root->value == u) {
        printf("%d is an ancestor of %d.\n", u, v);
        return;
    } else if (root->value == v) {
        printf("%d is an ancestor of %d.\n", v, u);
        return;
    } else if (u > root->value && v < root->value) {
        if (flag)
            printf("LCA of %d and %d is %d.\n", u, v, root->value);
        else
            printf("LCA of %d and %d is %d.\n", v, u, root->value);
        return;
    } else if (u > root->value && v > root->value) findRes(root->right, u, v, flag);
    else findRes(root->left, u, v, flag);
}

#include <unordered_set>

int M, N;
unordered_set<int> pre;

int pat_solver() {
    scanf("%d%d", &M, &N);
    node *root = nullptr;
    int _i;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_i);
        pre.insert(_i);
        root = create(root, nullptr, _i, 0);
    }
    for (int j = 0; j < M; ++j) {
        int u, v;
        scanf("%d%d", &u, &v);
        bool b1 = pre.find(u) == pre.end();
        bool b2 = pre.find(v) == pre.end();
        if (b1 && b2) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (b1) {
            printf("ERROR: %d is not found.\n", u);
        } else if (b2) {
            printf("ERROR: %d is not found.\n", v);
        } else {
            bool flag = true;
            if (u <= v) {
                flag = false;
                swap(u, v);
            }
            findRes(root, u, v, flag);
        }
    }

    return 0;
}

/*
测试样例



*/

map<int, bool> mp;
int others() {
    /*
     * 小姐姐的方法也太巧妙了吧。
     * 让我这个超时党无Fuck说
     */

    int m, n, u, v, a = 0;
    scanf("%d %d", &m, &n);
    vector<int> preVector(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &preVector[i]);
        mp[preVector[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        for(int j = 0; j < n; j++) {
            a = preVector[j];
            if ((a >= u && a <= v) || (a >= v && a <= u)) break;
        }
        if (!mp[u] && !mp[v])
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (!mp[u] || !mp[v])
            printf("ERROR: %d is not found.\n", !mp[u] ? u : v);
        else if (a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}