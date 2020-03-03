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
    int add = 0;
    int key = 0;
    int next = 0;
    int flag = false;
} LinkList[100010];
int fst_node_add, N;

int cmp(const node &a, const node &b) {
    if (!a.flag || !b.flag) {
        return a.flag > b.flag; // 1 > 0;  把false扔到后面去
    } else {
        return a.key < b.key;
    }
}

int pat_solver() {
    scanf("%d %05d", &N, &fst_node_add);
    int _a, _k, _n;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &_a, &_k, &_n);
        LinkList[_a] = {_a, _k, _n};
    }
    for (int k = fst_node_add; k != -1; k = LinkList[k].next) {
        LinkList[k].flag = true;
    }
    sort(LinkList, LinkList + 100010, cmp);
    node fst_node = LinkList[0];
    if (!fst_node.flag) {
        printf("0 -1");
        return 0;
    }
    int cnt = 0;
    for (cnt = 0; LinkList[cnt].flag; cnt++) {
        LinkList[cnt].next = LinkList[cnt + 1].flag ? LinkList[cnt + 1].add : -1;
    }
    printf("%d %05d\n", cnt, LinkList[0].add);
    for (int j = 0; j < cnt; ++j) {
        printf("%05d %d ", LinkList[j].add, LinkList[j].key);
        LinkList[j].next == -1 ? printf("-1") : printf("%05d\n", LinkList[j].next);
    }
    return 0;
}