//
// Created by shaob on 2020/3/12.
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


int N; // number of testees
struct student {
    string id; // B basic A advance T top | unique
    int score = -1; // [0,100]
    string school; // 6 english
};
unordered_map<string, pair<double, int> > schoolScore; // 主键：学校，值<学生成绩，学生人数>

struct output {
    int rank; // 1 start
    string school; // to小写
    double tws; // B / 1.5 + A + T * 1.5
    int ns; // number of testees who belong to this institution
    output(int _r, string _s, double _t, int _n) : rank(_r), school(move(_s)), tws(_t), ns(_n) {};
};

vector<output> result;

bool cmp(const output &a, const output &b) {
    if (a.tws != b.tws) {
        return a.tws > b.tws;
    } else if (a.ns != b.ns) {
        return a.ns < b.ns;
    } else {
        return a.school < b.school;
    }
}

void mkRank() {
    int _rank = 2;
    for (int i = 1; i < result.size(); i++, _rank++) {
        if (result[i].tws == result[i - 1].tws) {
            result[i].rank = result[i - 1].rank;
        } else {
            result[i].rank = _rank;
        }
    }
}

double getWeight(const string &s) {
    if (s[0] == 'A') {
        return 1.00;
    } else if (s[0] == 'B') {
        return 2.00 / 3;
    } else if (s[0] == 'T') {
        return 1.50;
    } else {
        static_assert(true, "");
    }
    static_assert(true, "");
    return -1;
}

int pat_solver() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        string _id, _school;
        int _s;
        double rs;
        cin >> _id >> _s >> _school;
        for (char &_:_school) {
            _ = tolower(_); // 屁话真多
        }
        if (schoolScore.find(_school) == schoolScore.end()) {
            schoolScore[_school] = pair<double, int>(getWeight(_id) * _s, 1);
        } else {
            schoolScore[_school].first = schoolScore[_school].first + getWeight(_id) * _s;
            schoolScore[_school].second++;
        }
    }
    for (const auto &s:schoolScore) { // 备注：这里必须取整，用floor和round或者int都能AC
        result.emplace_back(1, s.first, floor(s.second.first), s.second.second);
    }
    sort(result.begin(), result.end(), cmp);
    mkRank();
    printf("%zu\n", result.size());
    for (const auto &s:result) {
        printf("%d %s %.0f %d\n", s.rank, (s.school).c_str(), s.tws, s.ns);
    }
    return 0;
}

/*
测试样例



*/