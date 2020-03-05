//
// Created by shaob on 2020/3/5.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
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
typedef long long ll;
multiset<ll, greater<>> A, B;
multiset<ll, less<>> _A, _B; // 注意了 set会去重，得用Multiset防止去重（这样子效率低下，但是看到这些代码又骚又贱的样子就很让我欢心）

int pat_solver() {
    ll _c, _i;
    scanf("%lld", &_c);
    for (int i = 0; i < _c; ++i) {
        scanf("%lld", &_i);
        _i > 0 ? A.insert(_i) : _A.insert(_i);
    }
    scanf("%lld", &_c);
    for (int i = 0; i < _c; ++i) {
        scanf("%lld", &_i);
        _i > 0 ? B.insert(_i) : _B.insert(_i);
    }
    long long result = 0;
    for (auto _a = A.begin(), _b = B.begin(); _a != A.end() && _b != B.end(); _a++, _b++) {
        result += *_a * *_b;
    }
    for (auto _a = _A.begin(), _b = _B.begin(); _a != _A.end() && _b != _B.end(); _a++, _b++) {
        result += *_a * *_b;
    }
    printf("%lld", result);
    return 0;
}

/*
测试样例
4
-3 -2 3 4
4
-2 -1 2 3

*/