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

node *root = nullptr;

bool isUnique = true;

void PrePost2Tree(int preBegin, int preEnd, int postBegin, int postEnd) {

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


    return 0;
}

/*
测试样例



*/