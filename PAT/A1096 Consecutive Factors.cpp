//
// Created by shaob on 2020/2/29.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <stack>
#include <queue>
#include <vector>

typedef long long LL;
using namespace std;

bool isPrime(int num) {
    if (num <= 1)return false;
    int sqr = int(sqrt(1.00 * num));
    for (int i = 2; i <= sqr; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

struct Factor {
    LL num = 0;
    int cnt = 0;
    LL sum = 0;

    Factor(LL _, int __) : num(_), cnt(__) {};

    Factor() = default;
};

vector<Factor> vec;

void findFactors(LL num) {
    int sqr = int(sqrt(1.00 * num));
    for (int i = 2; i <= sqr; ++i) {
        if (isPrime(i)) {
            if (num % i == 0) {
                while (num % i == 0) {
                    if (vec.empty() || vec.back().num != i) {
                        vec.emplace_back(i, 1);
                    } else {
                        vec.back().cnt++;
                    }
                    num /= i;
                }
            }
        }
    }
    if (num != 1) {
        vec.emplace_back(num, 1);
    }
}

int pat_solver() {
    LL m;
    cin >> m;
    findFactors(m);
    // 想太复杂了。
    cout << endl;
    return 0;
}