//
// Created by shaob on 2020/2/25.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int N = 0, b = 2;
int z[100]; // consider more large.
int num = 0;

void fit2base() {
//    快速进制转换的代码
    do {
        z[num++] = N % b;
        N = N / b;
    } while (N != 0);
}

bool judgePalindromic() {
    for (int i = 0; i <= num / 2; ++i) {
        if (z[i] == z[num - i - 1]) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}


int pat_solver() {
    scanf("%d%d", &N, &b);
    fit2base();
    if (judgePalindromic()) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    printf("%d", z[num - 1]);
    for (int i = num-2; i >= 0; --i) {
        printf(" %d", z[i]);
    }
}