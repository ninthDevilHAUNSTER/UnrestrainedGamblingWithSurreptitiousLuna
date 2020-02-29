//
// Created by shaob on 2020/2/25.
//

#include <ctime>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

time_t timestamp2second(const string &timestamp) {
    // 各种时间戳转日期
    tm *datetime = new tm;
    strptime(timestamp.c_str(), "%Y-%m-%d %H:%M:%S", datetime);
    return mktime(datetime);
}

string second2timestamp(const long long second) {
    auto *datetime = new tm; // 一定要分配空间。
    char s[100];
    time_t t = second;
    datetime = gmtime(&t);
    strftime(s, sizeof(s), "%Y-%m-%d %H:%H:%S", datetime); // 此处写格式
    return s;
}

void todo_func() {
    printf("%ld\n", timestamp2second("2020-3-1 15:30:28"));
    printf("%s\n", (second2timestamp(1583047828)).c_str());
}


struct Record {
    string name = "";
    long int come_time = 0;
    long int leave_time = 0;

    Record() = default;

    Record(const string &_name,
           const string &_come_datetime,
           const string &_leave_datetime) {
        name = _name;
        come_time = timestamp2second("2020-03-01 " + _come_datetime);
        leave_time = timestamp2second("2020-03-01 " + _leave_datetime);
    }
};

vector<Record> recVector;

int pat_solver() {
    int N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        string a, b, c;
        cin >> a >> b >> c;
        Record tmp(a, b, c);
        recVector.push_back(tmp);
    }
    long int earlyTime = 9999999999, latestTime = 0;
    int earlyId = -1, latestId = -1;
    for (auto j = 0; j < N; ++j) {
        if (recVector[j].come_time < earlyTime) {
            earlyTime = recVector[j].come_time;
            earlyId = j;
        }
        if (recVector[j].leave_time > latestTime) {
            latestTime = recVector[j].leave_time;
            latestId = j;
        }
    }
    printf("%s %s", (recVector[earlyId].name).c_str(), (recVector[latestId].name).c_str());
// 感觉自己写的，好骚啊。
    return 0;
}