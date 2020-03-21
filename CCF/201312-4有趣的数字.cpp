//
// Created by shaob on 2020/3/21.
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
#include <unordered_set>
#include <unordered_map>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff

class BigNumber {
    char buffer[1024]{};
    int len{};

    explicit BigNumber(char _buffer[]) {
        for (int i = 0; i < strlen(_buffer); i++) {
            buffer[i] = _buffer[i];
        }
        len = strlen(_buffer);
    }

};

int csp_solver() {

    return 0;
}

/*
测试样例



*/
