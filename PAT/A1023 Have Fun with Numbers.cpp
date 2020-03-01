//
// Created by shaob on 2020/2/29.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct BG {
    int d[50]{};
    int len;

    BG() {
        fill(d, d + 50, 0);
        len = 0;
    }

    explicit BG(char s[]) {
        len = strlen(s);
        for (int i = 0; i < len; ++i) {
            d[i] = s[len - 1 - i] - '0';
        }
    }
};

BG add(BG &a, BG &b) {
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

int pat_solver() {
    char s[50];
    scanf("%s", s);
    BG a(s);
    BG a2 = add(a, a);
    int hash[10] = {0};
    if (a.len != a2.len) {
        printf("No\n");
    } else {
        for (int j = 0; j < a.len; ++j) {
            hash[a.d[j]]++;
            hash[a2.d[j]]--;
        }
        bool flag = true;
        for (int i : hash) {
            if (i != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    for (int i = a2.len - 1; i >= 0; --i) {
        printf("%d", a2.d[i]);
    }
    return 0;
}