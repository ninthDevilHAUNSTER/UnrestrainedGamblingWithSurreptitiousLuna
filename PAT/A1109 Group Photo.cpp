//
// Created by shaob on 2020/3/8.
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
#define MaxSize 0x3fffffff

struct people {
    int height = MaxSize;
    char name[10] = "\0";
    int id = -1;
} Group[10010];
int N, K;
vector<string> result(10010);

int cmp0(const people &a, const people &b) {
    if (a.height != b.height) {
        return a.height > b.height;
    } else {
        return strcmp(a.name, b.name) < 0;
    }
}

int cmp1(const people &a, const people &b) {
    return a.height < b.height;
}

/*
 * 推到重来，写的我自己都乱了
int cmp2(int begin, int end, int size) {
    int mid = begin + size / 2; // 因为我的下标是0开始的，所以是size /2
    int index = end;



    assert(begin == end && end == mid);
    return 0;
}
 */

int pat_solver() {
    scanf("%d%d", &N, &K);
    char _n[10];
    int _h;
    for (int i = 0; i < N; ++i) {
        scanf("%s%d", _n, &_h);
        Group[i].height = _h;
        strcpy(Group[i].name, _n);
        Group[i].id = i;
    }
    sort(Group, Group + N, cmp0);
    int start = 0, row = K, m = 0;
    while (row) {
        if (row == K) {
            m = N - N / K * (K - 1); // 最后一排
        } else {
            m = N / K; // m 代表单排人数个数
        }
        result[m / 2] = Group[start].name; // 中间的小伙纸
        int j = m / 2 - 1;
        for (int i = start + 1; i < start + m; ++ ++i) {
            result[j--] = Group[i].name;
        }
        j = m / 2 + 1;
        for (int k = start + 2; k < start + m; ++ ++k) {
            result[j++] = Group[k].name;
        }
        printf("%s", result[0].c_str());
        for (int l = 1; l < m; ++l) {
            printf(" %s", result[l].c_str());
        }
        printf("\n");
        start += m;
        row--;
    }
    return 0;
}

/*
测试样例



*/