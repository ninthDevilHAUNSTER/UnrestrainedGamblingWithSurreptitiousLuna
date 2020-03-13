//
// Created by shaob on 2020/3/13.
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

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff


struct registerCard {
    int level = 0; // 0
    int test_site = 0; // 1--3
    int test_date = 0; // 4--9
    int test_number = 0; // 10--12
    string raw_id{};

    explicit registerCard(string &s) {
        if (s[0] == 'T') {
            level = 3;
        } else if (s[0] == 'A') {
            level = 2;
        } else if (s[0] == 'B') {
            level = 1;
        }
        test_site = stoi(s.substr(1, 3));
        test_date = stoi(s.substr(4, 2)) * 365 + stoi(s.substr(6, 2)) * 30 + stoi(s.substr(8, 2));
        test_number = stoi(s.substr(9, 3));
        raw_id = move(s);
    }

    registerCard() = default;
};

int N, M;

struct student {
    registerCard id{};
    int score = -1;

    student() = default;

    student(string &s, int _i) {
        score = _i;
        id = registerCard(s);
    }

    bool operator<(const student &b) const {
        if (score != b.score) {
            return score > b.score;
        } else {
            return id.raw_id < b.id.raw_id;
        }
    }
};

/*
 * 1: 按成绩非递增输出给定等级上的小伙纸
 *相同顺序则按姓名升序。
 *
 * 2: 输出给定考场中参加考试人员的数量
 * Nt Ns
 * （总人数，总成绩）
 * 3: 输出输出给定日期的参加考试人员的数量
 * Site Nt （总人数） 按照Nt降序排列，若有重复，则按site号升序排列
 */
vector<student> input;
set<student> case1Result;

struct siteCnt {
    int site = -1;
    int cnt = 0;

};

#include <unordered_map>

unordered_map<int, int> case3Map;
vector<int> case3Result;
int LEVEL;

bool cmp3(int i, int j) {
    if (case3Map[i] != case3Map[j]) {
        return case3Map[i] > case3Map[j];
    } else {
        return i < j;
    }
}


int pat_solver() {
    scanf("%d%d", &N, &M);
    string _s;
    int _sc;
    for (int i = 0; i < N; ++i) {
        cin >> _s >> _sc;
        input.emplace_back(_s, _sc);
    }
    for (int j = 1; j <= M; ++j) {
        cin >> _sc >> _s;
        printf("Case %d: %d %s\n", j, _sc, _s.c_str());
        if (_sc == 1) {
            if (_s[0] == 'T') {
                LEVEL = 3;
            } else if (_s[0] == 'A') {
                LEVEL = 2;
            } else if (_s[0] == 'B') {
                LEVEL = 1;
            }
            for (auto &s:input) {
                if (s.id.level == LEVEL) {
                    case1Result.insert(s);
                }
            }
            if (case1Result.empty()) {
                printf("NA\n");
                LEVEL = 0;
                continue;
            }
            for (auto &s : case1Result) {
                printf("%s %d\n", s.id.raw_id.c_str(), s.score);
            }
            case1Result.clear();
        } else if (_sc == 2) {
            int test_site = stoi(_s);
            int Nt = 0, Ns = 0;
            for (auto &s:input) {
                if (s.id.test_site == test_site) {
                    Nt++;
                    Ns += s.score;
                }
            }
            Nt == 0 ? printf("NA\n") : printf("%d %d\n", Nt, Ns);
        } else if (_sc == 3) {
            int test_date = stoi(_s.substr(0, 2)) * 365 + stoi(_s.substr(2, 2)) * 30 + stoi(_s.substr(4, 2));
            for (auto &s:input) {
                if (s.id.test_date == test_date) {
                    if (case3Map.find(s.id.test_site) == case3Map.end()) {
                        case3Map[s.id.test_site] = 1;
                        case3Result.push_back(s.id.test_site);
                    } else {
                        case3Map[s.id.test_site]++;
                    }
                }
            }
            sort(case3Result.begin(), case3Result.end(), cmp3);
            if (case3Result.empty()) {
                printf("NA\n");
            } else {
                for (auto i:case3Result) {
                    printf("%03d %d\n", i, case3Map[i]);
                }
            }
            case3Result.clear();
            case3Map.clear();
        }
    }
    return 0;
}

/*
测试样例

CASE 1: 1 A
A107180908108 100
A107180908021 98
A112180318002 98
CASE 2: 2 107
3 260
CASE 3: 3 180908
107 2
123 2
102 1
CASE 4: 2 999
NA

Case 1: 1 A
A107180908108 100
A107180908021 98
A112180318002 98
Case 2: 2 107
3 260
Case 3: 3 180908
107 2
123 2
102 1
Case 4: 2 999
NA

*/