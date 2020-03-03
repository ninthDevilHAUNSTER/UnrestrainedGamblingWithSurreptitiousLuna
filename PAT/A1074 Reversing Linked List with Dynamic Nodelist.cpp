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

struct Node {
    Node *next = nullptr;
    int data = 0;
    int add = 0;
    int next_add = 0;
};

struct static_node {
    int add = 0;
    int data = 0; // order
    int next = -1;
    int order = MaxSize;

    static_node() = default;

    static_node(int _a, int _d, int _n) : add(_a), data(_d), next(_n) {};
} static_chain[100010];

int first_add, N, K;

void printf_list(Node *head) {
    printf("\n");
    for (Node *p = head->next; p != nullptr; p = p->next) {
        printf("%05d %d %05d\n", p->add, p->data, p->next_add);
    }
}

void reverse_list(Node *start, Node *end) {
    Node *p, *q;
    p = start->next;
    start->next = nullptr;
    while (p != end) {
        q = p->next;
        p->next = start->next;
        start->next = p;
        p = q;
    }
}


int pat_solver() {
    // 我们为什么要用链表呢？
    scanf("%05d %d %d", &first_add, &N, &K);
    int _a, _d, _n;
    for (int i = 0; i < N; ++i) {
        scanf("%05d %d %05d", &_a, &_d, &_n);
        static_chain[_a].add = _a;
        static_chain[_a].data = _d;
        static_chain[_a].next = _n;
//        mk_order_node.push_back(_a);
    }
    static_node current_node = static_chain[first_add];
    static Node *head = new Node;
    Node *s = head;
    for (int j = 0; j < N; ++j) {
        Node *p = new Node;
        p->add = current_node.add;
        p->next_add = current_node.next;
        p->data = current_node.data;
        s->next = p;
        s = p;
        current_node = static_chain[current_node.next];
    }
    s->next = nullptr;
    Node *begin = head, *end = head;
    for (int k = 0; k < N / K; ++k) {
        for (int i = 0; i < K; ++i) {
            end = end->next;
        }
        reverse_list(begin, end->next);
        begin = end;
    }
    if (N % K != 0) {
        reverse_list(begin->next, nullptr);
    }

    printf_list(head);
    return 0;
}
