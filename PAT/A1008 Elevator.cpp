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

int pat_solver(){
    int a, now = 0, sum = 0;
    cin >> a;
    while(cin >> a) {
        if(a > now)
            sum = sum + 6 * (a - now);
        else
            sum = sum + 4 * (now - a);
        now = a;
        sum += 5;
    }
    cout << sum;
    return 0;
}

/*
测试样例



*/