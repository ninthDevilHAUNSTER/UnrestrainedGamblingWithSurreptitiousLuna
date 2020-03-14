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

vector<int> preOrder, postOrder;

/*
 * 给前序和后序，然后判断中序遍历是否唯一，并输出任意一个中序遍历
 *
 * 这题晚上慢慢啃....感觉不是很能弄懂...
 *
 */
struct node {
    int value = -1;
    node *left = nullptr, *right = nullptr;

    node() = default;
};


bool isUnique = true;
vector<int> in;

node *PrePost2Tree(node *root, int preBegin, int preEnd, int postBegin, int postEnd) {
    if (preBegin > preEnd) {
        in.push_back(preOrder[preBegin]);
        return nullptr;
    } else {
        if (preOrder[preBegin] == postOrder[postEnd]) {
            int i = preBegin + 1;
            while (i <= preEnd && preOrder[i] != postOrder[postEnd - 1]) i++;
            if (i - preBegin > 1) {
                root->left = PrePost2Tree(root->left, preBegin + 1, i - 1, postBegin, postEnd + (i - preBegin - 1) - 1);
            } else {
                isUnique = false;
            }
            in.push_back(postOrder[postBegin]);
            root->right = PrePost2Tree(root->right, i, preBegin, postBegin + (i - preBegin - 1), postEnd - 1);
        }
        return root;
    }
}

int N;

int pat_solver() {
    scanf("%d", &N);
    int _;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_);
        preOrder.push_back(_);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_);
        postOrder.push_back(_);
    }
    node *root = nullptr;


    return 0;
}

/*
测试样例



*/