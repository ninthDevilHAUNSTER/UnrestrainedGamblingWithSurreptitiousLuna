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

using namespace std;
#define MaxSize 0x3fffffff

struct node {
    int next = 0;
    int flag = false;
} LinkList[100010];
int first_node_L1, first_node_L2, N;

int pat_solver() {
    scanf("%05d %05d %d", &first_node_L1, &first_node_L2, &N);
    int _a, _n;
    char _s;
    for (int i = 0; i < N; ++i) {
        scanf("%05d %c %05d", &_a, &_s, &_n);
        LinkList[_a].next = _n;
    }
    for (int j = first_node_L1; j != -1; j = LinkList[j].next) {
        LinkList[j].flag = true;
    }
    for (int j = first_node_L2; j != -1; j = LinkList[j].next) {
        if (LinkList[j].flag) {
            printf("%05d", j);
            return 0;
        }
    }
    printf("-1");
    return 0;
}