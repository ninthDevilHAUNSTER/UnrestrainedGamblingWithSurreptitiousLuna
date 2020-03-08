//
// Created by shaob on 2020/3/8.
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
#define inf 0x3fffffff

/*
 * 判断二叉树是否为完全二叉树，若是则输出最后一个节点，若否则输出叶节点
 */
struct node {
    int left = -1;
    int right = -1;
    bool isRoot = true;

    node() = default;
} BTree[25];

int N, root;

bool isCompleteBT(int x, int &result) {
//    int null_node = inf;
    queue<int> Q;
    Q.push(x);
//    Q.push(null_node);
    while (!Q.empty()) {
        int v = Q.front();
//        cout << v << "\t";
//        visit(v);
        Q.pop();
        if (BTree[v].right != -1 && BTree[v].left != -1) {
            Q.push(BTree[v].left);
            Q.push(BTree[v].right);
        } else if (BTree[v].left == -1 && BTree[v].right != -1) {
            return false; // 左子树空右子树非空，直接返回错，不多BB
        } else {
            if (BTree[v].left != -1 && BTree[v].right == -1) {
                // 左子树非空，右子树空，则该节点必须为最后一个非叶节点
                Q.push(BTree[v].left);
            }
            // 否则，该节点一定是叶子节点。对此，如果该节点如果不是叶子节点直接返回false；
            while (!Q.empty()) {
                v = Q.front();
                result = v;
                Q.pop();
                if (BTree[v].left != -1 || BTree[v].right != -1)
                    return false;
            }
        }
    }
    return true;
}


int pat_solver() {
    scanf("%d\n", &N);
    string l, r;
    for (int i = 0; i < N; ++i) {
        cin >> l >> r;
        if (l != "-") {
            BTree[i].left = stoi(l);
            BTree[stoi(l)].isRoot = false;
        }
        if (r != "-") {
            BTree[i].right = stoi(r);
            BTree[stoi(r)].isRoot = false;
        }
    }
    for (int j = 0; j < N; ++j) {
        if (BTree[j].isRoot) {
            root = j;
            break;
        }
    }
    int result = 0;
    if (isCompleteBT(root, result)) {
        printf("YES %d", result);
    } else {
        printf("NO %d", root);
    }

    return 0;
}

/*
测试样例



*/