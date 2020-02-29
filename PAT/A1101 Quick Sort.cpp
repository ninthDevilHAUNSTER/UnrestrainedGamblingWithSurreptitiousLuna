//
// Created by shaob on 2020/2/29.
//

#include <iostream>
// 输出两个递增序列的中位数
#include <vector>
#include <string>

using namespace std;
#define MAX_RANGE 1000000007
#define MAX_SIZE 15
long long s[MAX_SIZE];
long long left_max[MAX_SIZE], right_min[MAX_SIZE];
vector<int> result_vec;
int N;

int pat_solver() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &s[i]);
    }
    left_max[0] = -1;
    right_min[N - 1] = 0x3fffffff;
    for (int j = 1; j < N; ++j) {
        left_max[j] = max(s[j - 1], left_max[j - 1]);
    }
    for (int j = N - 2; j >= 0; --j) {
        right_min[j] = min(s[j + 1], right_min[j + 1]);
    }
    for (int k = 0; k < N; ++k) {
        if (left_max[k] < s[k] && right_min[k] > s[k]) {
            result_vec.push_back(s[k]);
        }
    }
    printf("%zu\n", result_vec.size());
    if (result_vec.empty()) {
        printf("\n");
    } else {
        for (int i = 0; i < result_vec.size(); i++) {
            (i == result_vec.size() - 1) ? printf("%d", result_vec[i]) : printf("%d ", result_vec[i]);
        }
    }
    return 0;
}