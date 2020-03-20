//
// Created by shaob on 2020/3/20.
//
// 做不出...太难了。题目是看懂了。代码写不来。

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
#include <unordered_set>
#include <unordered_map>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff
typedef long long LL;
int N, M; // 点数，边数

struct Node {
    vector<int> chain;
};
int t, k;

void handlerGetBlock() {

}

void handlerNewBlock() {

}

void handlerCheckBlock() {

}

int timeSchedule(int time) {
    handlerGetBlock();
    handlerNewBlock();
    handlerCheckBlock();
}

bool handleInput(char buffer[], int &ui, int &ti, int &value) {
    int renew_cnt = 0;
    int tlb[3] = {0};
    for (int i = 0; i <= strlen(buffer); i++) {
        if (buffer[i] == ' ') renew_cnt++;
        tlb[renew_cnt] *= 10;
        tlb[renew_cnt] += buffer[i] - '0';
    }
    if (renew_cnt == 2) {
        ui = tlb[0];
        ti = tlb[1];
        value = tlb[2];
        return true;
    } else {
        ui = tlb[0];
        ti = tlb[1];
        return false;
    }
}

int ccf_solver() {
    scanf("%d%d", &N, &M);
    int ui, vi;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &ui, &vi);
    }
    scanf("%d%d", &t, &k);
    int ti, value;
    for (int j = 0; j < k; ++j) {
        int nowTime = 0;
        char buffer[100];
        cin.getline(buffer, 100);
        handleInput(buffer, ui, ti, value);
        cout << ui << " " << ti << " " << value;
    }
    return 0;
}

/*
测试样例



*/