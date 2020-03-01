//
// Created by shaob on 2020/3/1.
//
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define MaxSize 26*26*26*10+16
#define MaxCourseNum 2510
using namespace std;

char name[MaxSize][5];
vector<int> courseList[MaxCourseNum];

int name2hash(const char s[]) {
    int a = 0;
    for (int i = 0; i < 3; ++i) {
        a = a * 26 + s[i] - 'A';
    }
    a = a * 10 + s[3] - '0';
    if (strlen(name[a]) == 0)
        strcpy(name[a], s);
    return a;
}

bool cmp(int s1, int s2) {
    return strcmp(name[s1], name[s2]) < 0;
}

int pat_solver() {
    int N, K, _, __;
    char n[5];
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%s %d", n, &_);
        int id = name2hash(n);
        for (int j = 0; j < _; ++j) {
            scanf("%d", &__);
            courseList[__].push_back(id);
        }
    }
    for (int k = 1; k <= K; ++k) {
        sort(courseList[k].begin(), courseList[k].end(), cmp);
        printf("%d %zu\n", k, courseList[k].size());
        for (auto i : courseList[k]) {
            printf("%s\n", name[i]);
        }
    }
    return 0;
}
