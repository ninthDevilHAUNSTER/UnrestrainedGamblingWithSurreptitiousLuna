//
// Created by shaob on 2020/2/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> result;
//vector<int> chain;
vector<int> sum;
int N, M;

int pat_solver() {
    scanf("%d%d", &N, &M);
    int __;
    sum.push_back(0);
    for (auto i = 0; i < N; ++i) {
        scanf("%d", &__);
        sum.push_back(sum.back() + __);
    }
    int end = 0;
    for (int j = 1; j < sum.size(); ++j) {
        end = lower_bound(sum.begin() + j - 1, sum.end(), M + sum[j - 1]) - sum.begin();
        if (sum[end] - sum[j - 1] == M)
            result.emplace_back(j, end);
    }
    if (!result.empty()) {
        for (auto a: result) {
            printf("%d-%d\n", a.first, a.second);
        }
    } else {
        int bestBIAS = 0x3fffffff, currentBIAS = 0;
        for (int j = 1; j < sum.size(); ++j) {
            end = lower_bound(sum.begin() + j - 1, sum.end(), M + sum[j - 1]) - sum.begin();
            if (end >= sum.size()) break;
            currentBIAS = sum[end] - sum[j - 1];
            if (currentBIAS < bestBIAS) {
                bestBIAS = currentBIAS;
                result.clear();
                result.emplace_back(j, end);
            } else if (currentBIAS == bestBIAS) {
                result.emplace_back(j, end);
            }
        }
        for (auto a: result) {
            printf("%d-%d\n", a.first, a.second);
        }
    }
    return 0;
}
