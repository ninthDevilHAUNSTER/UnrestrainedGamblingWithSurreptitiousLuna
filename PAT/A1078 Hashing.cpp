//
// Created by shaob on 2020/2/29.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <stack>
#include <queue>

typedef long long LL;
using namespace std;

int nextPrime(int num) {
    int sqr = int(sqrt(1.00 * num));
    if (num <= 1) return 2;
    for (int i = 2; i <= sqr; ++i) {
        if (num % i == 0) return nextPrime(++num);
    }
    return num;
}

int M, N;
bool hashTable[10010];

int HashInsert(int num, int bias) {
    if (bias >= M - 1)
        return -1;
    int ans = (num + bias * bias) % M;
    if (hashTable[ans]) {
        hashTable[ans] = false;
        return ans;
    } else {
        return HashInsert(num, ++bias);
    }
}

int pat_solver() {
    fill(hashTable, hashTable + 10010, true);
    scanf("%d%d", &M, &N);
    M = nextPrime(M);
    int _;
    scanf("%d", &_);
    _ = HashInsert(_, 0);
    (_ == -1) ? printf("-") : printf("%d", _);

    for (int i = 1; i < N; ++i) {
        scanf("%d", &_);
        _ = HashInsert(_, 0);
        (_ == -1) ? printf(" -") : printf(" %d", _);
    }
    return 0;
}