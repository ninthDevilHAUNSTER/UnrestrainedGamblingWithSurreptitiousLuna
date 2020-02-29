//
// Created by shaob on 2020/2/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define MaxSize 1024
using namespace std;

#include <unordered_map>

unordered_map<int, double> poly1, poly2, poly3;

void __init__() {
    for (int i = 0; i < MaxSize; ++i) {
        poly1[i] = poly2[i] = poly3[i] = 0.0;
    }
    for (int i = 0; i < MaxSize; ++i) {
        poly3[MaxSize + i] = 0.0;
    }
}

int pat_solver() {
    __init__();
    int tmp, _k;
    double _ai;
    scanf("%d", &tmp);
    for (int i = 0; i < tmp; ++i) {
        scanf("%d%lf", &_k, &_ai);
        poly1[_k] = _ai;
    }
    scanf("%d", &tmp);
    for (int i = 0; i < tmp; ++i) {
        scanf("%d%lf", &_k, &_ai);
        poly2[_k] = _ai;
    }

    for (int j = 0; j < MaxSize; ++j) {
        if (poly1[j] != 0.0) {
            for (int i = 0; i < MaxSize; ++i) {
                if (poly2[i] != 0.0) {
                    poly3[j + i] += poly1[j] * poly2[i];
                }
            }
        }
    }
    int count = 0;
    for (int l = 0; l < MaxSize * 2; ++l) {
        if (poly3[l] != 0.0) {
            count++;
        }
    }
    printf("%d", count);
    for (int k = MaxSize * 2; k > -1; --k) {
        if (poly3[k] != 0.0) {
            printf(" %d %.1f", k, poly3[k]);
        }
    }
    return 0;
}