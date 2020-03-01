//
// Created by shaob on 2020/2/29.
//

#include <iostream>
#include <set>
#include <algorithm>

#define MaxSize 175762
using namespace std;
vector<int> stu2course[MaxSize]; // 统计发现，vector比set更省内存也更快。

int name2hash(const char s[]) {
    int id = 0;
    for (int i = 0; i < 3; ++i) {
        id = id * 26 + (s[i] - 'A');
    }
    id = id * 10 + s[3] - '0';
    return id;
}

int N, K;

int pat_solver() {
    scanf("%d%d", &N, &K);
    int cid, cnt;
    char s[5];
    for (int i = 0; i < K; ++i) {
        scanf("%d%d", &cid, &cnt);
        for (int j = 0; j < cnt; ++j) {
            scanf("%s", s);
            stu2course[name2hash(s)].push_back(cid);
        }
    }
    for (int k = 0; k < N; ++k) {
        scanf("%s", s);
        int id = name2hash(s);
        sort(stu2course[id].begin(), stu2course[id].end());
        printf("%s %zu", s, stu2course[id].size());
        for (auto e: stu2course[id]) {
            printf(" %d", e);
        }
        printf("\n");
    }
    return 0;
}