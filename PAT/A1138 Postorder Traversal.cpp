//
// Created by shaob on 2020/3/10.
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

/*
 *  给前序和中序序列，输出后序的第一个节点
 *  后序的第一个节点，应该是前序序列的
 */

struct node {
    int value = 0;
    node *left = nullptr, *right = nullptr;
};

vector<int> preOrder;
vector<int> inOrder;
int N;
bool printFlag = false;

void PreIn2Post(int preL, int preR, int inL, int inR) {
    if (preL > preR || printFlag) {
        return;
    }
    node *s = new node;
    s->value = preOrder[preL];
    int k = inL;
    while (inOrder[k] != preOrder[preL]) k++;
    int leftLen = k - inL;
    PreIn2Post(preL + 1, preL + leftLen, inL, k - 1);
    PreIn2Post(preL + leftLen + 1, preR, k + 1, inR);
    if(!printFlag){
        /*
         * Question 为啥这里就一定是后续遍历的第一个节点呢？
         */
        printf("%d", s->value);
        printFlag = true;
    }
    return ;
}

int pat_solver() {
    scanf("%d", &N);
    int _s;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_s);
        preOrder.push_back(_s);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_s);
        inOrder.push_back(_s);
    }
    PreIn2Post(0, N - 1, 0, N - 1);


    return 0;
}

/*
测试样例



*/