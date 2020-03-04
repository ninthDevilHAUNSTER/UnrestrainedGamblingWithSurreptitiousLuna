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
int N, _;
int input[1024];
int id = 0;
int CBT[1024];

int inOrder(int root) {
    if (root > N) {
        return 0;
    }
    inOrder(root * 2); //l
    CBT[root] = input[id++]; // visit 注意这里的root是从1开始的。
    inOrder(root * 2 + 1); // r
}

int pat_solver() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &input[i]);
    }
    sort(input, input + N);
    inOrder(1);
    for (int j = 1; j <= N; ++j) {
        printf("%d", CBT[j]);
        if (j < N)printf(" ");
    }
    return 0;
}

/*
测试样例


这题，不能用动态二叉树，妥妥超时好吧。

 对于一个完全二叉树。有这样的性质：

 设节点编号为x（从1开始），那么其左孩子节点若存在则必为 2x 右孩子若存在则必维 2x+1

 那么，如果要构建一个完全二叉排序树，那么，给定的N个数字实际上应该递增排序后，
 实际上是二叉排序树的中序遍历序列（二叉排序树中序序列递增）。


*/