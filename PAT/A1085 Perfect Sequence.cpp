//
// Created by shaob on 2020/2/28.
//


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;
int N, p;
long a[100000];

int pat_solver() {
    scanf("%d%d", &N, &p);
    for (int i = 0; i < N; ++i) {
        scanf("%ld", &a[i]);
    }
    sort(a, a + N);
    int len = 0;
    int max_id = 0;
    for (int j = 0; j < N; ++j) {
        max_id = upper_bound(a - j, a + N, (long long) (p * a[j])) - a;
        len = max(len, max_id - j);
    }
    printf("%d", len);
    return 0;
}