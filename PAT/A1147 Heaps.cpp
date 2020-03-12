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
#include <cassert>
#include <cmath>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff

//Your job is to tell if a given complete binary tree is a heap.
int M, N;
/*
 * M number of trees to test
 * N number of keys in each tree
 */

vector<int> tree;

void postOrder(int i = 1) {
    if (i >= tree.size()) return;
    postOrder(i * 2);
    postOrder(i * 2 + 1);
    printf("%d%s", tree[i], i == 1 ? "\n" : " ");
}

bool isMaxHeap(int x = int(tree.size()) - 1) {
    for (int j = 1; j <= (tree.size() - 1) / 2; j++) {
        int left = j * 2, right = j * 2 + 1;
        if (tree[j] < tree[left] || (right < tree.size() && tree[j] < tree[right])) return false;
    }
    return true;
}

bool isMinHeap() {
    for (int j = 1; j <= (tree.size() - 1) / 2; j++) {
        int left = j * 2, right = j * 2 + 1;
        if (tree[j] > tree[left] || (right < tree.size() && tree[j] > tree[right])) return false;
    }
    return true;
}

int pat_solver() {
    scanf("%d%d", &M, &N);
    int _i;
    assert(N >= 2);
    tree.resize(N + 1); // 节点下标从1开始
    tree[0] = -INF;
    for (int i = 0; i < M; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &_i); // N distinct integer keys
            tree[j] = _i;
        }
        bool isMaxHeapFlag = tree[1] > tree[2];
        bool isHeapFlag = false;
        assert(tree[1] != tree[2]);
        isHeapFlag = isMaxHeapFlag ? isMaxHeap() : isMinHeap();
        if (isHeapFlag) {
            if (isMaxHeapFlag) {
                printf("Max Heap\n");
            } else {
                printf("Min Heap\n");
            }
        } else {
            printf("Not Heap\n");
        }
        postOrder();
    }
    return 0;
}

/*
测试样例



*/