//
// Created by shaob on 2020/2/29.
//

#include <iostream>
#include <cstdio>

double A[100010];

int pat_solver() {
    int _;
    double sum = 0;
    scanf("%d", &_);
    for (int i = 0; i < _; ++i) {
        scanf("%lf", &A[i]);
    }
    for (int j = 0; j < _; ++j) {
        sum += A[j] *j * (_ + 1 - j);
    }
    printf("%.2lf", sum);
    return 0;
}