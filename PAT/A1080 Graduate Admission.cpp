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
#include <queue>

#define MAX_STU_NUM 40016
#define MAX_SCH_NUM 128
#define MAX_APP_CHOICE 5
using namespace std;

struct Student {
    int id = -1;
    int GE = 0;
    int GI = 0;
    int app_school[MAX_APP_CHOICE] = {-1};
    int GA = 0;
    int rank = 0;
} stu_list[MAX_STU_NUM];

bool cmp(const Student &a, const Student &b) {
    if (a.GA != b.GA) {
        return a.GA > b.GA;
    } else if (a.GE != b.GE) {
        return a.GE > b.GE;
    } else {
        return a.id < b.id;
    }
}

int N, M, K;
int school_limit[MAX_SCH_NUM];
vector<int> school_roll_list[MAX_SCH_NUM];

void __init__() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &school_limit[i]);
    }
    for (int j = 0; j < N; ++j) {
        scanf("%d %d", &stu_list[j].GE, &stu_list[j].GI);
        stu_list[j].GA = stu_list[j].GE + stu_list[j].GI;
        stu_list[j].id = j;
        for (int i = 0; i < K; ++i) {
            scanf("%d", &stu_list[j].app_school[i]);
        }
    }
}

void mk_rank() {
    /*
     * 排名
     */
    for (int i = 1; i < N; ++i) {
        if (stu_list[i].GI == stu_list[i - 1].GI && stu_list[i].GE == stu_list[i - 1].GE) {
            stu_list[i].rank = stu_list[i - 1].rank;
        } else {
            stu_list[i].rank = i; // 这里的排名是从0开始的，方便计数
        }
    }
}

void mk_school() {
    for (int i = 0; i < N; i++) {
        Student s = stu_list[i];
        for (int j = 0; j < K; j++) {
            int a = s.app_school[j];
            int vt_size = school_roll_list[a].size();
            if (school_limit[a] == 0) continue;
            if (vt_size < school_limit[a] || stu_list[school_roll_list[a].back()].rank == s.rank) {
                school_roll_list[a].push_back(s.id);
                break;
            }
        }
    }
}

void show_result() {
    int index = 0;
    for (auto &a :school_roll_list) { // 我再也不用range for 了（真香—）
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); ++i) {
            if (i == 0) {
                printf("%d", a[i]);
            } else {
                printf(" %d", a[i]);
            }
        }
        printf("\n");
        index++;
        if (index >= M) {
            break;
        }
    }
}

int pat_solver() {
    __init__();
    sort(stu_list, stu_list + N, cmp);
    mk_rank();
    mk_school();
    show_result();
    return 0;
}

/*
5 5 3
0 0 0 5 5
100 100 0 1 2
100 99 1 2 0
99 100 2 1 0
99 99 1 0 2
98 98 2 0 1

 */