//
// Created by shaob on 2020/3/13.
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

int N, m, n;

int findMN() {
    int sqr = int(sqrt(1.00 * N));
    for (int i = sqr; i >= 1; --i) {
        if (N % i == 0) {
            m = max(i, N / i);
            n = min(i, N / i);
            return 1;
        }
    }
    return -1;
}

int A[10010][10010];
vector<int> input;

int cmp(int i, int j) {
    return i > j;
}

int pat_solver() {
    scanf("%d", &N);
    assert(findMN() != -1);
    int _;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_);
        input.push_back(_);
    }
    if (N == 1) {
        printf("%d", _);
        return 0;
    }
    sort(input.begin(), input.end(), cmp);
    int now = 0;
    int U = 1, D = m, L = 1, R = n;
    int j = 1, i = 1;
    while (now < input.size()) {
        while (now < N && j < R) {
            A[i][j] = input[now++];
            j++;
        }
        while (now < N && i < D) {
            A[i][j] = input[now++];
            i++;
        }
        while (now < N && j > L) {
            A[i][j] = input[now++];
            j--;
        }
        while (now < N && i > U) {
            A[i][j] = input[now++];
            i--;
        }
        U++, D--, L++, R--;
        i++, j++;
        if (now == N - 1) {
            A[i][j] = input[now++];
        }
    }
    for (int k = 1; k <= m; ++k) {
        for (int l = 1; l <= n; ++l) {
            printf("%d", A[k][l]);
            (l < n) ? printf(" ") : printf("\n");
        }
    }

    return 0;
}

/*
测试样例



*/