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
    int order = MaxSize;
} LinkList[100010];
int fst_node_add, N;


int cmp(const node &a, const node &b) {
    /// 这个题不能用简单的一个cmp搞定所有。。。。
    // 得用一个 exsit函数判断节点。
    if (!a.flag || !b.flag) {
        return a.flag > b.flag; // 1 > 0;  把false扔到后面去
    } else if (abs(a.key) != abs(b.key)) {
        return abs(a.key) > abs(b.key);
    } else {
        return a.order < b.order;
    }
}

int pat_solver() {
    scanf("%d %d", &fst_node_add, &N);
    int _a, _k, _n;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &_a, &_k, &_n);
        LinkList[_a] = {_a, _k, _n, false, i + 1};
    }
    for (int k = fst_node_add; k != -1; k = LinkList[k].next) {
        LinkList[k].flag = true;
    }
    sort(LinkList, LinkList + 100010, cmp);
    node fst_node = LinkList[0];
    if (!fst_node.flag) {
        return 0;
    }
    vector<node> valid_vec, remove_vec;
    int index = 0;
    // TODO 特判;
    while (LinkList[index].flag) {
        if (valid_vec.empty() || abs(valid_vec.back().key) != abs(LinkList[index].key)) {
            valid_vec.push_back(LinkList[index]);
        } else {
            remove_vec.push_back(LinkList[index]);
        }
        index++;
    }
    for (int j = 0; j < valid_vec.size(); j++) {
        valid_vec[j].next = valid_vec[j + 1].flag ? valid_vec[j + 1].add : -1;
    }
    for (int j = 0; j < remove_vec.size(); j++) {
        remove_vec[j].next = remove_vec[j + 1].flag ? remove_vec[j + 1].add : -1;
    }
    for (auto i:valid_vec) {
        printf("%05d %d ", i.add, i.key);
        i.next == -1 ? printf("-1\n") : printf("%05d\n", i.next);
    }
    printf("\n");
    for (auto i:remove_vec) {
        printf("%05d %d ", i.add, i.key);
        i.next == -1 ? printf("-1\n") : printf("%05d\n", i.next);
    }

    return 0;
}