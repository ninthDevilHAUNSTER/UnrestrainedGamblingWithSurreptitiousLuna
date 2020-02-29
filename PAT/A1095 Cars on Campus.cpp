//
// Created by shaob on 2020/2/26.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define MAX_REC 10010

int datetime2timestamp(int hh, int mm, int ss) {
    return ss + mm * 60 + hh * 3600;
}

void timestamp2datetime(int h) {
    int hh = 0;
    int mm = 0;
    int ss = 0;
    hh = h / 3600;
    ss = h % 60;
    mm = (h - 3600 * hh) / 60;
    printf("%02d:%02d:%02d", hh, mm, ss);
}


bool string2in(char s[]) {
    return strcmp(s, "in") == 0;
}

struct Car {
    char id[9] = {'\0'};
    int time = 0;
    bool in = true;
} all[MAX_REC], valid[MAX_REC];

int N, M;

void init() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        int _h, _m, _s;
        char s[5];
        scanf("%s %d:%d:%d %s", all[i].id, &_h, &_m, &_s, s);
        all[i].time = datetime2timestamp(_h, _m, _s);
        all[i].in = string2in(s);
        /// for DEBUG
    }
}

bool cmp1(const Car &a, const Car &b) {
    return strcmp(a.id, b.id) ? strcmp(a.id, b.id) < 0 : a.time < b.time;
}

bool cmp2(const Car &a, const Car &b) {
    return a.time < b.time;
}

int real_N = 0;
map<string, int> park_time;// 停车时间
int max_park_time = -1;

void mk_valid() {
    int r_i = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (!strcmp(all[i].id, all[i + 1].id) && all[i].in && !all[i + 1].in) {
            valid[r_i++] = all[i];
            valid[r_i++] = all[i + 1];
            // 更新的操作欠考虑了，一辆车可以停多次。
            if (park_time.count(all[i].id) == 0) {
                park_time[all[i].id] = all[i + 1].time - all[i].time;
            } else {
                park_time[all[i].id] += all[i + 1].time - all[i].time;
            }
            max_park_time = max(max_park_time, park_time[all[i].id]);
        }
    }
    real_N = r_i;
}

void mk_query() {
    int current_car = 0; // 第一辆车必然是进来的。这是规矩
    int _h, _m, _s;
    int now = 0;
    int query_time = 0;
    for (int j = 0; j < M; ++j) {
        scanf("%d:%d:%d", &_h, &_m, &_s);
        query_time = datetime2timestamp(_h, _m, _s);
        while (now < real_N && valid[now].time <= query_time) {
            valid[now].in ? current_car++ : current_car--;
            now++;
        }
        printf("%d\n", current_car);
    }
}

void mk_result() {
    for (const auto &a : park_time) {
        if (a.second == max_park_time) {
            printf("%s ", a.first.c_str());
        }
    }
    timestamp2datetime(max_park_time);
}

int pat_solver() {
    init();
    sort(all, all + N, cmp1);
    mk_valid();
    sort(valid, valid + real_N, cmp2);
    mk_query();
    mk_result();
    return 0;
}

/*
 * 一些小总结：
 *
 * 首先就是欠考虑的一点，车可以停多次。
 * 然后，下标不要跳，从0到N-1
 *
 */