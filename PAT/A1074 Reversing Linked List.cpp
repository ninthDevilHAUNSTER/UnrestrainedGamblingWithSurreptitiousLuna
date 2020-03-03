//
// Created by shaob on 2020/3/3.
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
#include <algorithm>
#include <cassert>

using namespace std;
#define MaxSize 0x3fffffff

struct Node {
    int add = 0;
    int data = 0; // order
    int next = -1;
    int order = MaxSize;

    Node() = default;

    Node(int _a, int _d, int _n) : add(_a), data(_d), next(_n) {};
} static_chain[100010];

vector<int> mk_order_node;

int first_add, N, K;

void reverse(int begin, int end) {
    assert(end < K - 1);
    /*
     * begin = 0; end = K-1;
     */
    Node current_node = static_chain[first_add];
    while (current_node.order < begin) {
        current_node = static_chain[current_node.next];
    }
}

bool cmp(const Node &a, const Node &b) {
    return a.order < b.order;
}

void printf_static_chain() {
    Node current_node = static_chain[first_add];
    while (current_node.next != -1) {
        printf("%06d %d %06d\n", current_node.add, current_node.data, current_node.next);
        current_node = static_chain[current_node.next];
    }
    printf("%06d %d -1\n", current_node.add, current_node.data);
}

int pat_solver() {
    scanf("%05d %d %d", &first_add, &N, &K);
    int _a, _d, _n;
    for (int i = 0; i < N; ++i) {
        scanf("%05d %d %05d", &_a, &_d, &_n);
        static_chain[_a].add = _a;
        static_chain[_a].data = _d;
        static_chain[_a].next = _n;
//        mk_order_node.push_back(_a);
    }
    int order = 0;
    Node current_node = static_chain[first_add];
    while (current_node.next != -1) {
        current_node.order = order;
        order++;
        current_node = static_chain[current_node.next];
    }
    N = order;
    sort(static_chain, static_chain + 100010, cmp);
//    printf_static_chain();
    // 看了答案案才知道，这原来是一种“逃课”的玩法...
    // 分成K小块
    for (int j = 0; j < N / K; ++j) { // K 是从1开始计算的。
        for (int i = (j + 1) * K - 1; i > j * K; --i) {
            // if K == 5;
            // 相当于 4 3 2 1  输出; 第0号节点在下面考虑
            printf("%05d %d %05d\n", static_chain[i].add, static_chain[i].data, static_chain[i - 1].add);
        }
        printf("%05d %d ", static_chain[j * K].add, static_chain[j * K].data); // o号节点的前两个信息


        if (j + 1 >= N / K) {
            if (N % K) {
                // 如果正好是最后一块
                printf("-1\n");
            } else {
                // 如果后面还有尾巴
                // 如图中 样例 j + 1 == 2 ; 6/4 == 1 ;
                printf("%05d\n", static_chain[(j + 1) * K].add);
                for (int i = N / K * K; i < N; ++i) {
                    printf("%05d %d ", static_chain[i].add, static_chain[i].data);
                    if (i < N - 1) {
                        printf("%05d\n", static_chain[i - 1].add);
                    } else {
                        printf("-1\n");
                    }
                }
            }
        } else {
            // 如果是中间块，则输出下一块第一个的首地址
            printf("%05d\n", static_chain[(j + 2) * K - 1].add);
        }
    }
    return 0;
}
