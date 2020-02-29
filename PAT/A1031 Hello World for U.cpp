//
// Created by shaob on 2020/2/25.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int pat_solver() {
    string input;
    cin >> input;
    int N = input.length();
    int n1, n3, n2;
    n1 = n3 = (N + 2) / 3;
    n2 = N + 2 - n1 * 2;
    int W[n1][n2];
    fill(W[0], W[0] + n1 * n2, -1);
    int index = 0;
    for (int i = 0; i < n1; ++i, ++index) {
        W[i][0] = index;
    }
    for (int j = 1; j < n2; ++j, ++index) {
        W[n1 - 1][j] = index;
    }
    for (int k = n1 - 2; k >= 0; --k, ++index) {
        W[k][n2 - 1] = index;
    }
    for (int l = 0; l < n1; ++l) {
        for (int i = 0; i < n2; ++i) {
            if (W[l][i] == -1) {
                printf(" ");
            } else {
                cout << input[W[l][i]];
            }
        }
        printf("\n");
    }
    return 0;
}