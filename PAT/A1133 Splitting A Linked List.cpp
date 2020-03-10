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
 * 重拍链表
 * 要求
 * 所有负数出现在非负数之前
 * 对于非负数，在小于等于K的数字必须出现在大于K的数字之前。
 * 其他按照链表的顺序排列。
 * 思路：三段式，第一加负数，第二次加小于等于K的数字，第三次加大于K的数字
 */

struct node {
    int address = -1;
    int value = -INF;
    int next = -1;

    node() = default;

    node(int _a, int _v, int _n) : address(_a), value(_v), next(_n) {};

    node(int _a, int _v) : address(_a), value(_v) {};
};

node nodeList[100010];

int N, K, start;
vector<node> negativeSegment, zero2KSegment, greaterKSegment;
vector<node> ans;

int pat_solver() {
    scanf("%d%d%d", &start, &N, &K);
    int _a, _v, _n;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d", &_a, &_v, &_n);
        nodeList[_a] = {_a, _v, _n};
    }
    int RA = start;
    while (start != -1) {
        _v = nodeList[start].value;
        _a = nodeList[start].address;
        if (_v < 0)
            ans.emplace_back(_a, _v);
//        if (_v < 0) {
//            negativeSegment.emplace_back(_a, _v);
//        } else if (_v >= 0 && _v <= K) {
//            zero2KSegment.emplace_back(_a, _v);
//        } else {
//            greaterKSegment.emplace_back(_a, _v);
//        }
        start = nodeList[start].next;
    }
    start = RA;
    while (start != -1) {
        _v = nodeList[start].value;
        _a = nodeList[start].address;
        if (_v >= 0 && _v <= K)
            ans.emplace_back(_a, _v);
//        if (_v < 0) {
//            negativeSegment.emplace_back(_a, _v);
//        } else if (_v >= 0 && _v <= K) {
//            zero2KSegment.emplace_back(_a, _v);
//        } else {
//            greaterKSegment.emplace_back(_a, _v);
//        }
        start = nodeList[start].next;
    }
    start = RA;
    while (start != -1) {
        _v = nodeList[start].value;
        _a = nodeList[start].address;
        if (_v > K)
            ans.emplace_back(_a, _v);
//        if (_v < 0) {
//            negativeSegment.emplace_back(_a, _v);
//        } else if (_v >= 0 && _v <= K) {
//            zero2KSegment.emplace_back(_a, _v);
//        } else {
//            greaterKSegment.emplace_back(_a, _v);
//        }
        start = nodeList[start].next;
    }
    for (int j = 0; j < ans.size(); ++j) {
        if (j < ans.size() - 1) {
            printf("%05d %d %05d\n", ans[j].address, ans[j].value,
                   ans[j + 1].address);
        } else {
            printf("%05d %d -1\n", ans[j].address, ans[j].value);
        }
        /*
         * 批评
         * 满脑子骚操作
         * 我要把这段垃圾代码留下！
         */
//    for (int j = 0; j < negativeSegment.size(); ++j) {
//        if (j < negativeSegment.size() - 1) {
//            printf("%05d %d %05d\n", negativeSegment[j].address, negativeSegment[j].value,
//                   negativeSegment[j + 1].address);
//        } else {
//            printf("%05d %d %05d\n", negativeSegment[j].address, negativeSegment[j].value,
//                   zero2KSegment.front().address);
//        }
//    }
//    for (int j = 0; j < zero2KSegment.size(); ++j) {
//        if (j < zero2KSegment.size() - 1) {
//            printf("%05d %d %05d\n", zero2KSegment[j].address, zero2KSegment[j].value,
//                   negativeSegment[j + 1].address);
//        } else {
//            printf("%05d %d %05d\n", zero2KSegment[j].address, zero2KSegment[j].value, greaterKSegment.front().address);
//        }
    }
//    for (int j = 0; j < greaterKSegment.size(); ++j) {
//        if (j < greaterKSegment.size() - 1) {
//            printf("%05d %d %05d\n", greaterKSegment[j].address, greaterKSegment[j].value,
//                   greaterKSegment[j + 1].address);
//        } else {
//            printf("%05d %d -1\n", greaterKSegment[j].address, greaterKSegment[j].value);
//    }

    return 0;
}

/*
测试样例



*/