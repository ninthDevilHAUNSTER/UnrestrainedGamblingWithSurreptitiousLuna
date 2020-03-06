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

using namespace std;
#define MaxSize 0x3fffffff

/// 两个最实用的函数，时间戳转日期，和日期转时间戳
// 同样可以秒杀

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

int dateDistance() {
    string input;
    cin >> input;
}

int alg_solver() {
    cout << DateTime2Int("07:55:00") << endl;
    cout << DateTime2Int("07:59:00") << endl;
    cout << Int2DateTime(1583366100) << endl;
    cout << Int2DateTime(1583366340) << endl;
    return 0;
}

/*
测试样例



*/