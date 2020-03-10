//
// Created by shaob on 2020/3/10.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <cassert>
#include <cmath>
#include <unordered_map>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff

/*
 * 排序题
 *
 */
int P, M, N;// P 网上测试学生人数，M，完成其中考试的人数，N完成期末考试的人数
/*
 * Gp  == p
 * Gm == M
 * Gf == N
 */
#define MaxSize 10010
unordered_map<int, string> id2name;
unordered_map<string, int> name2id;
int id = -1;

int insert2map(const string &s) {
    if (name2id.find(s) != name2id.end()) {
        return name2id[s];
    } else {
        id++;
        name2id[s] = id;
        id2name[id] = s;
        return id;
    }
}

struct student {
    string name{};
    int id = -1;
    int Gp = -1;
    int Gm = -1;
    int Gf = -1;
    bool valid = false;
    double G = -1;
};
student studentList[MaxSize];

void updateStudentGrade(student &s) {
    if (s.Gm > s.Gf) s.G = round(s.Gm * 0.4 + s.Gf * 0.6); // 经过实验，这里得取整
    else s.G = s.Gf;
}

bool cmp(const student &s1, const student &s2) {
    if (s1.valid != s2.valid) {
        return s1.valid;
    } else if (s1.G != s2.G) {
        return s1.G > s2.G;
    } else {
        return s1.name < s2.name;
    }
}

int pat_solver() {
    scanf("%d%d%d", &P, &M, &N);
    string buffer;
    int _g;
    for (int i = 0; i < P; ++i) {
        cin >> buffer >> _g;
        int stId = insert2map(buffer);
        studentList[stId].id = stId;
        studentList[stId].name = buffer;
        studentList[stId].Gp = _g;
    }
    for (int j = 0; j < M; ++j) {
        cin >> buffer >> _g;
        int stId = insert2map(buffer);
        studentList[stId].id = stId;
        studentList[stId].name = buffer;
        studentList[stId].Gm = _g;
    }
    for (int k = 0; k < N; ++k) {
        cin >> buffer >> _g;
        int stId = insert2map(buffer);
        studentList[stId].id = stId;
        studentList[stId].name = buffer;
        studentList[stId].Gf = _g;
    }
    for (int i = 0; i <= id; ++i) {
        studentList[i].valid = studentList[i].Gp >= 200;
        if (studentList[i].valid) updateStudentGrade(studentList[i]);
    }
    sort(studentList, studentList + id + 1, cmp);
    for (int l = 0; l <= id; ++l) {
        if (studentList[l].valid && studentList[l].G >= 60) {
            printf("%s %d %d %d %d\n", studentList[l].name.c_str(),
                   studentList[l].Gp, studentList[l].Gm,
                   studentList[l].Gf, int(studentList[l].G));
        } else {
            return 0;
        }
    }

    return 0;
}

/*
测试样例



*/