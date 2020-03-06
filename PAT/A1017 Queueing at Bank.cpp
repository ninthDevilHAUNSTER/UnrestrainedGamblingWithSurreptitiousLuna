//
// Created by shaob on 2020/3/5.
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

using namespace std;
#define MaxSize 0x3fffffff

struct DateTime {
    int HH, MM, SS;

    DateTime() {
        HH = 0;
        MM = 0;
        SS = 0;
    };

    DateTime(int _h, int _m, int _s) : HH(_h), MM(_m), SS(_s) {};
};

int DateTime2Int(string s) {
    tm *p = new tm;
    s = "2020-3-5 " + s;
    strptime(s.c_str(), "%Y-%m-%d %H:%M:%S", p);
    time_t t = mktime(p);
    return t;
}

string Int2DateTime(int timeStamp) {
    char buffer[80];
    time_t t(timeStamp + 8 * 3600);
    tm *p = gmtime(&t);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", p);
    string rt = buffer;
    return rt;
}

int N, K; /// N 顾客数，K 开放的窗口数。
int open_time = DateTime2Int("08:00:00");
int close_time = DateTime2Int("17:00:01");

struct service {
    int start_time = 0;
    int service_time = 0;
    int real_time = 0;
    string DateTime;

    service() = default;

    service(int _s, int _t, int _r) : start_time(_s), service_time(_t), real_time(_r) {};
};

vector<service> Queue;

bool cmp(const service &a, const service &b) {
    return a.real_time < b.real_time;
}

bool cmp2(const service &a, const service &b) {
    /// 让到下一个时间点最快的人排到最后，方便直接pop_back()
    return a.start_time + a.service_time > b.start_time + b.service_time;
}

int endTime[111];

int pat_solver() {
    int sum = 0;
    scanf("%d%d", &N, &K);
    string _s;
    int _t = 0, _r = 0;
    for (int i = 0; i < N; ++i) {
        cin >> _s >> _t;
        int t = DateTime2Int(_s);
        if (t < open_time) {
            sum += open_time - t;
            _r = t;
            t = open_time;
        } else {
            _r = t;
        }
        if (t >= close_time) continue;
        Queue.emplace_back(t, _t * 60, _r);
        Queue.back().DateTime = _s;
    }
    sort(Queue.begin(), Queue.end(), cmp);
    for (auto i:Queue) {
        printf("%d %d %s %d\n", i.start_time, i.service_time, (i.DateTime).c_str(), i.real_time);
    }
    vector<service> window;
    int index = 0;
    int nowTime = open_time;// 咱们开门啦~
    for (int j = 0; j < Queue.size(); ++j) {
        int idx = -1, minEndTime = 0x3ffffff;
        for (int i = 0; i < K; ++i) {
            if (endTime[i] < minEndTime) {
                minEndTime = endTime[i];
                idx = j;
            }
        }
        if(endTime[idx] <= Queue[j].real_time){

        }
    }

    /*
    while (index < Queue.size()) {
        assert(nowTime <= close_time + 10);
        while (!window.empty() && window.back().service_time + window.back().start_time <= nowTime) { /// 服务完毕，弹出最后一个人
            window.pop_back();
        }
        while (index < Queue.size() && Queue[index].start_time <= nowTime && window.size() < K) {
            sum += nowTime - Queue[index].start_time;
            window.push_back(Queue[index++]);
            sort(window.begin(), window.end(), cmp2);
        }
        nowTime = Queue.empty() ? Queue.back().service_time + Queue.back().start_time : nowTime + 1; /// 时间正在流失...
    }
    */


    /*
    /// 队列操作
    queue<service> window;
    int index = 0;
    int nowTime = open_time;// 咱们开门啦~
    while (index < Queue.size()) {
        assert(nowTime <= close_time + 10); /// 我感觉我的问题出在了front 上，不一定是front，可能受后面几个。
        while (!window.empty() && window.front().service_time + window.front().start_time <= nowTime) {
            service c = window.front();
            sum += nowTime - c.start_time;
            window.pop();
        }
        while (index < Queue.size() && index < Queue[index].start_time <= nowTime && window.size() <= K) {
            window.push(Queue[index++]);
        }
        nowTime += Queue.empty() ? Queue.front().service_time : 1; /// 时间正在流失...
    }
    */
    printf("%.1lf", 1.00 * sum / Queue.size() / 60);
    return 0;
}

/*
测试样例



*/