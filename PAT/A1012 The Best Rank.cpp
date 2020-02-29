//
// Created by shaob on 2020/2/25.
//
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


struct Student {
    int id = -1;
    short grade[4] = {0}; // C M E A;
    short rank[4] = {0}; //
} student_list[2048]; // 最多两千名学生。

int now; // 用于cmp函数
char int2CMEA[4] = {'A', 'C', 'M', 'E'};
int id2ListNode[1000000];

bool cmp(const Student &A, const Student &B) {
    return A.grade[now] > B.grade[now];
}

int pat_solver() {
    fill(id2ListNode, id2ListNode + 1000000, -1);
    int M, N;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d%hd%hd%hd", &student_list[i].id, &student_list[i].grade[1],
              &student_list[i].grade[2], &student_list[i].grade[3]);
        student_list[i].grade[0] = student_list[i].grade[1] + student_list[i].grade[2] + student_list[i].grade[3];
        id2ListNode[student_list[i].id] = i;
    }
    for (int j = 0; j <= 3; ++j) {
        now = j;
        sort(student_list, student_list + 2048, cmp);
        student_list[0].rank[now] = 1;
        for (int i = 1; i < N; ++i) {
            if (student_list[i].grade[now] == student_list[i - 1].grade[now]) {
                // 如果分相同，则排名相同
                student_list[i].rank[now] = student_list[i - 1].rank[now];
            } else {
                student_list[i].rank[now] = 1 + i;/// 千万不能写成这样。 1 + Rank[student_list[i].id][now] ;
            }
        }
    }
    int visit_id = 0;
    for (int k = 0; k < M; ++k) {
        scanf("%d", &visit_id);
        if (id2ListNode[visit_id] == -1) {
            printf("N/A\n");
        } else {
            int sid = 0;
            for (int j = 0; j < N; ++j) {
                if (student_list[j].id == visit_id) {
                    sid = j;
                }
            }
            int rank = student_list[sid].rank[0];
            int courseID = 0;
            for (int i = 0; i <= 3; ++i) {
                if (rank > student_list[sid].rank[i]) {
                    rank = student_list[sid].rank[i];
                    courseID = i;
                }
            }
            printf("%d %c\n", rank, int2CMEA[courseID]);
        }
    }
    return 0;
}





