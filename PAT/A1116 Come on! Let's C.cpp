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

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff
#define MaxSize 10010
int N;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    int sqr = int(sqrt(1.00 * n));
    for (int i = 2; i <= sqr; ++i) {
        if (i % sqr == 0)return false;
    }
    return true;
}

bool isSearched[MaxSize];
bool isAttend[MaxSize];
struct account {
    int id = -1;
    int rank = 1;
};
vector<account> input;

int pat_solver() {
    fill(isAttend, isAttend + MaxSize, false);
    fill(isSearched, isSearched + MaxSize, false);
    scanf("%d", &N);
    int _;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &_);
        isAttend[_] = true;
        input.push_back({_, i});
    }
//    sort(input.begin(), input.end(), cmp);
    /*
     * mkrank
     */


    scanf("%d", &N);
    for (int j = 0; j < N; ++j) {
        scanf("%d", &_);
        if (isAttend[_]) {
            if (!isSearched[_]) {
                int index = 0;
                while (input[index].id != _) index++;
                if (_ == input.begin()->id) {
                    printf("%04d: Mystery Award\n", _);
                    isSearched[_] = true;
                } else if (isPrime(input[index].rank)) {
                    printf("%04d: Minion\n", _);
                } else {
                    printf("%04d: Chocolate\n", _);
                }
                isSearched[_] = true;
            } else {
                printf("%04d: Checked\n", _);
            }
        } else {
            printf("%04d: Are you kidding?\n", _);
        }
    }
    return 0;
}

/*
测试样例



*/
