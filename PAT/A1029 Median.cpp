//
// Created by shaob on 2020/2/28.
//

#include <iostream>
// 输出两个递增序列的中位数
#include <vector>

using namespace std;

vector<int> vec1, vec2;

int pat_solver() {
    int _, __;
    scanf("%d", &_);
    for (int i = 0; i < _; ++i) {
        scanf("%d", &__);
        vec1.push_back(__);
    }
    scanf("%d", &_);
    for (int i = 0; i < _; ++i) {
        scanf("%d", &__);
        vec2.push_back(__);
    }
    vec1.push_back(0x3fffffff);
    vec2.push_back(0x3fffffff);
    int loc = (vec1.size() + vec2.size() - 1) / 2;
    auto v1 = vec1.begin();
    auto v2 = vec2.begin();
    for (int j = 0; j < loc - 1; ++j) {
        (*v1 < *v2) ? v1++ : v2++;
    }
    (*v1 < *v2) ? printf("%d", *v1) : printf("%d", *v2);
    return 0;
}