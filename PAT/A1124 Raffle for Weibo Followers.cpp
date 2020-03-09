//
// Created by shaob on 2020/3/9.
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

int M, N, S; // total number of forwards , skip number of winners , index of 1st winner

unordered_map<string, int> RaffleList;

int pat_solver() {
    scanf("%d%d%d", &M, &N, &S);
    bool isOutput = false;
    string name;
    int real_i = 1;
    for (int i = 1; i <= M; ++i) {
        cin >> name;
        if (real_i - S >= 0 && (real_i - S) % N == 0) {
            if (RaffleList.find(name) == RaffleList.end()) {
                RaffleList[name] = 1;
                isOutput = true;
                cout << name << endl;
            } else {
                continue;
            }
        }
        real_i++;
    }
    if (!isOutput) cout << "Keep going...";
    return 0;
}

/*
测试样例



*/