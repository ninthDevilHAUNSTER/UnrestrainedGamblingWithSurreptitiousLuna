//
// Created by shaob on 2020/2/26.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int hashtable[1005];

int pat_solver() {
    scanf("%d%d", &N, &M);
    int _m;
    int a = -1;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_m);
        hashtable[_m]++;
    }
    for (int j = 0; j < min(M, 1005); ++j) {
        if (M - j < 0) continue;
        if ((j == M - j && hashtable[j] >= 2) || (j !=  M - j && hashtable[j] >= 1 && hashtable[M - j] >= 1)) {
            a = min(j, M - j);
        }
    }
    a == -1 ? printf("No Solution") : printf("%d %d", a, M - a);
    return 0;
}