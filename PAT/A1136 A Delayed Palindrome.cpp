//
// Created by shaob on 2020/2/29.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct BG {
    int d[1024]{};
    int len;

    BG() {
        fill(d, d + 1024, 0);
        len = 0;
    }

    explicit BG(char s[]) {
        len = strlen(s);
        for (int i = 0; i < len; ++i) {
            d[i] = s[len - 1 - i] - '0';
        }
    }
};

BG add(BG a, BG b) {
    BG c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; ++i) {
        int tmp = a.d[i] + b.d[i] + carry;
        carry = tmp / 10;
        c.d[c.len++] = tmp % 10;
    }
    if (carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}

bool isPalindromic(const BG &a) {
    for (int i = 0; i < a.len / 2; ++i) {
        if (a.d[i] != a.d[a.len - i - 1]) {
            return false;
        }
    }
    return true;
}

BG R(BG a) {
    for (int i = 0; i < a.len / 2; ++i) {
        swap(a.d[i], a.d[a.len - i - 1]);
    }
    return a;
}

void printfBG(const BG &a) {
    for (int i = a.len - 1; i >= 0; --i) {
        printf("%d", a.d[i]);
    }
}

int K;

int pat_solver() {
    char s[1024];
    scanf("%s", s);
    BG A(s);
    if (isPalindromic(A)) {
        printfBG(A);
        printf(" is a palindromic number.");
        return 0;
    }
    int i;
    for (i = 1; i <= 10; ++i) {
        BG RA = R(A);
        printfBG(A);
        printf(" + ");
        printfBG(RA);
        printf(" = ");
        A = add(A, R(A));
        printfBG(A);
        printf("\n");
        if (isPalindromic(A)) {
            printfBG(A);
            printf(" is a palindromic number.");
            return 0;
        }
    }
    printf("Not found in 10 iterations.");
    return 0;
}