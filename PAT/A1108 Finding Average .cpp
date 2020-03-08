//
// Created by shaob on 2020/3/8.
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
#define MaxSize 0x3fffffff

vector<double> legal_input;

int N;

bool isLegal(char s[]) {
    int decimal_place = 0;
    bool is_in_decimal_place = false;
    for (int i = 0; i < strlen(s); ++i) {
        if (i == 0 && s[0] == '-') continue;
        if (s[i] == '.' && !is_in_decimal_place) {
            is_in_decimal_place = true;
            continue;
        }
        if (s[i] > '9' || s[i] < '0') {
            return false;
        }
        if (is_in_decimal_place) {
            decimal_place++;
            if (decimal_place >= 3) return false;
        }
    }
}

int pat_solver() {
    char buffer[1024];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%1023s", buffer);
        if (isLegal(buffer)) {
            double number = atof(buffer);
            if (number > 1000 || number < -1000) {
                printf("ERROR: %s is not a legal number\n", buffer);
            } else {
                legal_input.push_back(atof(buffer));
            }
        } else {
            printf("ERROR: %s is not a legal number\n", buffer);
        }
    }
    double sum = 0;
    for (auto a: legal_input) {
        sum += a;
    }
    int cnt = legal_input.size();

    if (cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else if (cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}

/*
测试样例



*/