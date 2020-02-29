//
// Created by shaob on 2020/2/25.
//

#include <iostream>
#include <cstdio>

using namespace std;

int pat_solver() {
    double max[3] = {-1, -1, -1};
    int r[3] = {0, 0, 0};
    char id2char[3] = {'W', 'T', 'L'};
    double result[3];
    for (int k = 0; k < 3; ++k) {
        for (double &i : result) {
            scanf("%lf", &i);
        }
        for (int j = 0; j < 3; ++j) {
            if (result[j] > max[k]) {
                r[k] = j;
                max[k] = result[j];
            }
        }
    }
    printf("%c %c %c %.2f", id2char[r[0]], id2char[r[1]], id2char[r[2]],
           (max[0] * max[1] * max[2] * 0.65 - 1) * 2.0);
    return 0;
}