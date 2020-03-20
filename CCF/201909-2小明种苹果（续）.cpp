//
// Created by shaob on 2020/3/20.
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
#include <unordered_set>
#include <unordered_map>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff

int T, D, E;
vector<int> treeDropCnt;

int ccf_solver() {
    int N, M;
    scanf("%d", &N);
    treeDropCnt.resize(N + 1, 0);
    int dropCnt = 0;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &M);
        int input, init;
        scanf("%d", &init);
        for (int j = 2; j <= M; ++j) {
            scanf("%d", &input);
            if (input > 0) {
                // 重新统计了个数
                if (input < init) {
                    // 发生了掉落
//                    dropCnt += init - input;
                    treeDropCnt[i] = 1;
                    init = input;
                }
            } else {
                init += input;
            }
        }
        sum += init;
    }
    int groupCnt = 0;
    for (int i = 0; i < N; i++) {
        int normalize = i + N;
        if (treeDropCnt[(normalize) % N] == 1 &&
            treeDropCnt[(normalize + 1) % N] == 1 &&
            treeDropCnt[(normalize + 2) % N] == 1) {
            groupCnt++;
        }
        if(treeDropCnt[(normalize) % N] == 1) dropCnt++;
    }
    printf("%d %d %d", sum, dropCnt, groupCnt);
    return 0;
}

/*
测试样例
5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0


*/