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

/*
测试样例



*/
int N;

bool judge(int &index) {
    index++;
    if (index % 7 == 0) return true;
    int n = index;
    while (n > 0) {
        if (n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}

int ccf_solver() {
    scanf("%d", &N);
    int R[4] = {0};
    int index = 0;
    while (index < N) {
        if (judge(index)) {
            R[(index - 1) % 4]++;
            N++;
        }
    }
    printf("%d\n%d\n%d\n%d", R[0], R[1], R[2], R[3]);
    return 0;
}