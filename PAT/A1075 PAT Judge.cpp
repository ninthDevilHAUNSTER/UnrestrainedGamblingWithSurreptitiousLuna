//
// Created by shaob on 2020/2/26.
//
// 一些小细节以及特殊的边界情况要考虑到位


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int N = 0; // total user 10000
int K = 0; // total problem 5
int M = 0; // total submission 100000
int p[8] = {-1}; // full mark of i-th problem;

struct User {
    int uid = 0; // 5 digit
    int s[6] = {-1}; // 0 代表保存了总分;
    bool flag = false; // 0 代表保存了总分;
    int rank = 1;
    int ac = 0;
} user[10010];

bool cmp(const User &a, const User &b) {
    if (a.s[0] != b.s[0]) {
        return a.s[0] > b.s[0];
    }
    if (a.ac != b.ac) {
        return a.ac > b.ac;
    } else {
        return a.uid < b.uid;
    }
}

void make() {
    // 算总分
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            if (user[i].s[j] != -1) {
                user[i].s[0] += user[i].s[j];
            }
            if (user[i].s[j] == p[j]) {
                user[i].ac++;
            }
        }
    }
}

void __init__() {
    for (int i = 1; i <= N; ++i) {
        fill(user[i].s, user[i].s + 6, -1);
        user[i].s[0] = 0;
        user[i].uid = i;
        user[i].flag = false;
    }
}

int pat_solver() {
    scanf("%d%d%d", &N, &K, &M);
    __init__();
    for (int i = 1; i <= K; ++i) {
        scanf("%d", &p[i]);
    }
    for (int j = 0; j < M; ++j) {
        int _id = 0, _p = 0, _s = 0;
        scanf("%05d %d %d", &_id, &_p, &_s);
        if (_s != -1) {
            user[_id].flag = true; // 提交后把flag设置为1.
        }
        if (_s == -1 && user[_id].s[_p] == -1) {
            // 就算编译没过，分数也是会变为0分的。便于输出
            user[_id].s[_p] = 0;
        }
        if (_s > user[_id].s[_p]) { // 获得更高的分（就算是得了0分，也要覆盖）
            user[_id].s[_p] = _s;
        }
    }
    make();
    sort(user, user + N + 1, cmp);
    for (int k = 1; k < N; ++k) {
        if (user[k].s[0] == user[k - 1].s[0]) {
            user[k].rank = user[k - 1].rank;
        } else {
            user[k].rank = k + 1;
        }
    }
    for (int l = 0; l < N; ++l) {
        if (!user[l].flag) { // 这里不能用总分判断。
            continue;
        } else {
            printf("%d %05d", user[l].rank, user[l].uid);
            for (int i = 0; i <= K; ++i) {
                if (user[l].s[i] == -1) {
                    printf(" -");
                } else {
                    printf(" %d", user[l].s[i]);
                }
            }
            printf("\n");
        }
    }
}

