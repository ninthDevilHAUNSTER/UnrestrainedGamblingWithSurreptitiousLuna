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
    char name[16] = {'\0'};
    char id[24] = {'\0'};
    int grade = 0;
} stu_list[1000];

int N = 0;
int g1 = 0, g2 = 0;

bool cmp(const Student &a, const Student &b) {
    return a.grade > b.grade;
}

int pat_solver() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s %s %d", stu_list[i].name, stu_list[i].id, &stu_list[i].grade);
    }
    scanf("%d %d", &g1, &g2);
    sort(stu_list, stu_list + N, cmp);
    bool print_flag = false;
    for (int j = 0; j < N; ++j) {
        if (stu_list[j].grade >= g1 && stu_list[j].grade <= g2) {
            printf("%s %s\n", stu_list[j].name, stu_list[j].id);
            print_flag = true;
        }
    }
    if (!print_flag) {
        printf("NONE\n");
    }
    return 0;

}