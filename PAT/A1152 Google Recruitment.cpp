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

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff

bool isPrime(int x) {
    if (x <= 1)
        return false;
//    int sqr = int(sqrt(1.00 * x));
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int L, K;
string input;

/*
 * L number of digits of the given number
 * K the prime to be found
 */

int pat_solver() {
    cin >> L >> K;
    cin >> input;
    for (int i = 0; i <= L - K; ++i) { // [0..K]
        if (isPrime(stoi(input.substr(i, K)))) {
            cout << input.substr(i, K);
            return 0;
        }
    }
    cout << 404;
    return 0;
}

/*
测试样例



*/