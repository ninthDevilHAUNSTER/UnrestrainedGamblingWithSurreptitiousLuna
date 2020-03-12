//
// Created by shaob on 2020/3/12.
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

vector<int> hashSet;
int MSize, N, M;

int getHashLocation(int key, int bias) {
    return (key + bias * bias) % MSize;
}

bool isPrime(int x) {
    if (x <= 1)
        return false;
    int sqr = int(sqrt(1.00 * x));
    for (int i = 2; i <= sqr; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int nextPrime(int x) {
    while (!isPrime(x)) {
        x++;
    }
    return x;
}


/*
 * MSize table size;
 * N input numbers num
 * M keys tobe found
 *
 * input MSize,N,M <=10000;
 */

int pat_solver() {
    scanf("%d%d%d", &MSize, &N, &M);
    MSize = nextPrime(MSize);
    hashSet.resize(MSize);
    fill(hashSet.begin(), hashSet.end(), -1);
    int _i;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_i);
        bool canInsertFlag = false;
        for (int j = 0; j < MSize; ++j) {
            if (hashSet[getHashLocation(_i, j)] == -1) {
                hashSet[getHashLocation(_i, j)] = _i;
                canInsertFlag = true;
                break;
            }
        }
        if (!canInsertFlag) printf("%d cannot be inserted\n", _i);
    }
    int cnt = 0;
    for (int k = 0; k < M; ++k) {
        scanf("%d", &_i);
        for (int j = 0; j <= MSize; ++j) { // 为啥这边是到 Msize 啊，不是应该Msize -1 嘛?
            cnt++;
            if (hashSet[getHashLocation(_i, j)] == -1 || hashSet[getHashLocation(_i, j)] == _i) {
                break;
            }
        }
    }
    printf("%.1f", 1.00 * cnt / M);
    return 0;
}

/*
测试样例



*/