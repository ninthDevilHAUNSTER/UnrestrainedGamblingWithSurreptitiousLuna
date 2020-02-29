//
// Created by shaob on 2020/2/26.
//

#include <iostream>

using namespace std;
int hash_table[10024];
int a[100024];

int pat_solver() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
        hash_table[a[i]]++;
    }
    for (int j = 0; j < N; ++j) {
        if (hash_table[a[j]] == 1) {
            printf("%d", a[j]);
            return 0;
        }
    }
    printf("None");
    return 0;
}