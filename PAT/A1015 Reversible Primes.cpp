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

bool isPrime(LL num) {
    assert(num > 0);
    if (num == 1)
        return false;
    LL sqr = LL(sqrt(1.00 * num));
    for (int i = 2; i <= sqr; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

queue<int> input;

LL toDec(int base) {
    assert(base <= 10);
    LL rt_value = 0;
    while (!input.empty()) {
        rt_value = input.front() + rt_value * base;
        input.pop();
    }
    return rt_value;
}

int pat_solver() {
    LL num;
    int radix;
    while (scanf("%lld", &num) != EOF) {
        if (num < 0) break;
        scanf("%d", &radix);
        if (isPrime(num)) {
            do {
                input.push(num % radix);
                num /= radix;
            } while (num != 0);
            if (isPrime(toDec(radix))) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else {
            printf("No\n");
        }
    }
    return 0;
}