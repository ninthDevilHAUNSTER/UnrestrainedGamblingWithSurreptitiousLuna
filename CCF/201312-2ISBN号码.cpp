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

struct ISBN {
    int number1;
    int number2;
    int number3;
    int rec;
};

int csp_solver() {

    char input[13];
    int i;
    for (i = 0; i < 13; i++) {
        cin >> input[i];
    }
    int sum = 0;
    sum += (input[0] - '0');
    for (i = 2; i <= 4; i++) {
        sum += ((input[i] - '0') * i);
    }
    for (i = 6; i <= 10; i++) {
        sum += ((input[i] - '0') * (i - 1));
    }
    int x = sum % 11;
    if (x == 10 && input[12] == 'X') {
        cout << "Right";
        return 0;
    } else if (x == input[12] - '0') {
        cout << "Right";
        return 0;
    }
    input[12] = 0;
    if (x == 10)cout << input << "X";
    else cout << input << x;
    return 0;
}

/*
测试样例


0-670-82162-4

*/