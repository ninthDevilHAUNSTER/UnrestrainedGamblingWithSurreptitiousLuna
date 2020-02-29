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

struct Student {
    int id = 0;
    char name[10] = {'\0'};
    int grade = 0;
} stu_list[10024];

bool cmp1(const Student a, const Student b) {
    // C =1
    return a.id < b.id;
}

bool cmp2(const Student a, const Student b) {
    // C =2
    int s = strcmp(a.name, b.name);
    if (s != 0) {
        return s < 0;
    } else {
        return a.id < b.id;
    }
}

bool cmp3(const Student a, const Student b) {
    // C =3
    if (a.grade != b.grade) {
        return a.grade < b.grade;
    } else {
        return a.id < b.id;
    }
}

int pat_solver() {
    int N = 0, C = 1;
    scanf("%d %d", &N, &C);
    for (int i = 0; i < N; ++i) {
        scanf("%d %s %d", &stu_list[i].id, stu_list[i].name, &stu_list[i].grade);
    }
    if (C == 1) {
        sort(stu_list, stu_list + N, cmp1);
    } else if (C == 2) {
        sort(stu_list, stu_list + N, cmp2);
    } else {
        sort(stu_list, stu_list + N, cmp3);
    }
    for (int j = 0; j < N - 1; ++j) {
        printf("%06d %s %d\n", stu_list[j].id, stu_list[j].name, stu_list[j].grade);
    }
    int j = N - 1;
    printf("%06d %s %d", stu_list[j].id, stu_list[j].name, stu_list[j].grade);
    return 0;
}