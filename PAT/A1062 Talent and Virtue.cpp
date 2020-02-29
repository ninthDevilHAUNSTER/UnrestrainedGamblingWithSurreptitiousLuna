//
// Created by shaob on 2020/2/25.
//


#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int L = 0, H = 0; // 及格线，优秀线
int pass = 0; // 及格人数
int MaxSize = 0x3fffffff;

struct Student {
    string id;
    short v_grade = 0;
    short t_grade = 0;
    short level = 0;
    short sum = 0;

    Student() = default;

    Student(string _id, short _v, short _t) :
            id(move(_id)), v_grade(_v), t_grade(_t) {
        sum = _v + _t;
        if (_v < L || _t < L) {
            level = 5;
            pass--;
        } else if (_v >= H && _t >= H) {
            level = 1;
        } else if (_v >= H && _t < H) {
            level = 2;
        } else if (_v < H && _t < H && _v >= _t) {
            level = 3;
        } else {
            level = 4;
        }
    };
};

bool cmp(const Student &a, const Student &b) {
    if (a.level != b.level) {
        return a.level < b.level;
    } else if (a.sum != b.sum) {
        return a.sum > b.sum;
    } else if (a.v_grade != b.v_grade) {
        return a.v_grade > b.v_grade;
    } else {
        return a.id < b.id;
    }
}

vector<Student> student_list;

int pat_solver() {
    scanf("%d%d%d", &n, &L, &H);
    pass = n;
    for (int i = 0; i < n; ++i) {
        string _id;
        short _v, _t;
        cin >> _id;
        scanf("%hd%hd", &_v, &_t);
        Student _s(_id, _v, _t);
        student_list.push_back(_s);
    }
    sort(student_list.begin(), student_list.end(), cmp);
    printf("%d\n", pass);
    for (const auto &a:student_list) {
        if (a.level != 5) {
            printf("%s %hd %hd\n", (a.id).c_str(), a.v_grade, a.t_grade);
        } else {
            break;
        }
    }
    return 0;
}