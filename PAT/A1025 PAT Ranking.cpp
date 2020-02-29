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
#define MAX_LOC_NUM 128
#define MAX_STU_NUM 30010
struct Student {
    char id[15] = {'\0'};
    int score = 0;
    int loc = 0;
    int loc_rank = 0;
    int total_rank = 0;
};

// VEC 的拼接
// std::vector<int> v3;
//v3.insert(v3.end(),v1.begin(),v1.end());
//v3.insert(v3.end(),v2.begin(),v2.end());

// 排行数组（是不是开的太大了）;按照学生ID直接映射。其中second[0] 指的是总排行，second[i] 表示在对应考场的排行
int N = 0;
int K = 0;
vector<Student> student_list;

bool cmp1(const Student &a, const Student &b) {
    if (a.score != b.score) {
        return a.score > b.score;
    } else {
        return strcmp(a.id, b.id) < 0;
    }
}

int pat_solver() {
    int _stu_index = 0;
    int st_count = 0;
    scanf("%d", &N);
    vector<Student> s_vector;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &K);
        st_count += K;
        for (int j = 0; j < K; ++j, ++_stu_index) {
            Student _stu;
            scanf("%s %d", _stu.id, &_stu.score);
            _stu.loc = i;
            s_vector.push_back(_stu);
        }
        sort(s_vector.begin(), s_vector.end(), cmp1);
        //mk_rank
        s_vector[0].loc_rank = 1;
        for (int k = 1; k < K; ++k) {
            if (s_vector[k].score == s_vector[k - 1].score) {
                s_vector[k].loc_rank = s_vector[k - 1].loc_rank;
            } else {
                s_vector[k].loc_rank = k + 1;
            }
        }
        student_list.insert(student_list.end(), s_vector.begin(), s_vector.end());
        s_vector.clear();
    }
    sort(student_list.begin(), student_list.end(), cmp1);
    //mk_rank
    student_list[0].total_rank = 1;
    for (int k = 1; k < st_count; ++k) {
        if (student_list[k].score == student_list[k - 1].score) {
            student_list[k].total_rank = student_list[k - 1].total_rank;
        } else {
            student_list[k].total_rank = k + 1;
        }
    }
    printf("%d\n", st_count);
    for (auto a : student_list) {
        printf("%s %d %d %d\n", a.id, a.total_rank, a.loc, a.loc_rank);
    }
    return 0;
}