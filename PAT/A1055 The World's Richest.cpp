//
// Created by shaob on 2020/2/26.
//


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;
#define MAX_PEOPLE_NUM 100024
int N = 0; // MAX 100000 people
int K = 0; // MAX 1000 query
struct People {
    char name[16] = {'\0'};
    int age = 0;
    int net_worth = 0;
} people[MAX_PEOPLE_NUM];

bool cmp(const People &a, const People &b) {
    if (a.net_worth != b.net_worth) {
        return a.net_worth > b.net_worth;
    } else if (a.age != b.age) {
        return a.age < b.age;
    } else {
        return strcmp(a.name, b.name) < 0;
    }
}

int pat_solver() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%s%d%d", people[i].name, &people[i].age, &people[i].net_worth);
    }
    sort(people, people + MAX_PEOPLE_NUM, cmp);
    vector<People> wealth_rank;
    for (int j = 0; j < K; ++j) {
        int M = 0; // max output
        int Amin = -1, Amax = 300; // age range
        scanf("%d %d %d", &M, &Amin, &Amax);
        printf("Case #%d:\n", j + 1);
        // 考虑只查询100个人，而人数可以达到100000，所以就push 100个人次。这个优化非常巧妙
        for (auto p: people) {
            if (p.age >= Amin && p.age <= Amax) {
                wealth_rank.push_back(p);
            }
            if (wealth_rank.size() > 101) {
                break;
            }
        }
        if (wealth_rank.empty()) {
            printf("None\n");
        } else {
            for (int i = 0; i < min(M, int(wealth_rank.size())); ++i) {
                printf("%s %d %d\n", wealth_rank[i].name, wealth_rank[i].age, wealth_rank[i].net_worth);
            }
        }
        wealth_rank.clear();
    }
}