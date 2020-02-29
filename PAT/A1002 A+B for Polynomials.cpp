//
// Created by shaob on 2020/2/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define MaxSize 1024
using namespace std;

#include <map>

map<int, double> poly1, poly2, poly3;

void __init__() {
    for (int i = 0; i < MaxSize; ++i) {
        poly1[i] = poly2[i] = poly3[i] = 0.0;
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
    int count = 0;
    for (int j = 0; j < MaxSize; ++j) {
        poly3[j] = poly1[j] + poly2[j];
        if (poly3[j] != 0.0) {
            count++;
        }
    }
    printf("%d", count);
    for (int k = MaxSize; k > -1; --k) {
        if (poly3[k] != 0.0) {
            printf(" %d %.1f", k, poly3[k]);
        }
    }
    return 0;
}