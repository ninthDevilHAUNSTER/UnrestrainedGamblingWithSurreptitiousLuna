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
    int left = -1;
    int right = -1;
    int data = INF;
} BST[128];
int N;
int input[128];
int input_index = 0;

void inOrder(int root) {
    if (BST[root].left != -1) inOrder(BST[root].left);
    BST[root].data = input[input_index++];
    if (BST[root].right != -1) inOrder(BST[root].right);
}

void layerOrder(int root) {
    if (root == -1)
        return;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int p = q.front();
        printf("%d", BST[p].data);
        input_index++;
        if (input_index < N) printf(" ");
        q.pop();
        if (BST[p].left != -1) q.push(BST[p].left);
        if (BST[p].right != -1) q.push(BST[p].right);
    }

}

int pat_solver() {
    scanf("%d", &N);
    int _l, _r;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &_l, &_r);
        BST[i].left = _l;
        BST[i].right = _r;
    }
    for (int j = 0; j < N; ++j) {
        scanf("%d", &input[j]);
    }
    sort(input, input + N);
    inOrder(0);
    input_index = 0;
    layerOrder(0);
    return 0;
}

/*
测试样例



*/