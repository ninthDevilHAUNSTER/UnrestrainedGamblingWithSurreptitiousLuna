//
// Created by shaob on 2020/2/25.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

struct student {
    string name;
    char gender{};
    string ID;
    int grade{};

    student() = default;

    student(string _name, char _gender, string _ID, int grade) :
            name(std::move(_name)), gender(_gender), ID(std::move(_ID)), grade(grade) {}
};

vector<student> StudentVector;

int pat_solver() {
    int N;
    string a, c;
    char b;
    int d;
    int diff = -1, maleScore = 0xffff, femaleScore = -1, maleId = -1, femaleId = -1;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        cin >> a >> b >> c >> d;
        student s(a, b, c, d);
        StudentVector.push_back(s);
    }
    for (int j = 0; j < N; ++j) {
        student s = StudentVector[j];
        if (s.gender == 'F') {
            // female
            if (s.grade > femaleScore) {
                femaleId = j;
                femaleScore = s.grade;
            }
        } else {
            // male
            if (s.grade < maleScore) {
                maleId = j;
                maleScore = s.grade;
            }
        }
    }
    if (femaleId == -1) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", (StudentVector[femaleId].name).c_str(),
               (StudentVector[femaleId].ID).c_str());
    }
    if (maleId == -1) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", (StudentVector[maleId].name).c_str(),
               (StudentVector[maleId].ID).c_str());
    }
    if (maleScore == 0xffff or femaleScore == -1) {
        printf("NA");
    } else {
        printf("%d", femaleScore - maleScore);
    }
}