//
// Created by shaob on 2020/3/5.
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

using namespace std;
#define MaxSize 0x3fffffff
typedef long long LL;

/*
 * 以 30710 为例
 * ① 考虑个位的情况
 * xxxx1 共有 0000 -> 3070 共 3071种方案。特别的，对于末尾为1的情况，如 30711 共有 3071 + 1种方案。
 * ② 考虑十位的情况
 * xxx1y ，共有 000 -> 306 共 307种情况，对于y而言，可以从 0取到9 因此共 3070 zhon
 */

int pat_solver() {
    int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
    scanf("%d", &n);
    while(n / a) {
        left = n / (a * 10), now = n / a % 10, right = n % a;
        if(now == 0) ans += left * a;
        else if(now == 1) ans += left * a + right + 1;
        else ans += (left + 1) * a;
        a = a * 10;
    }
    printf("%d", ans);
    return 0;
}

/*
测试样例



*/