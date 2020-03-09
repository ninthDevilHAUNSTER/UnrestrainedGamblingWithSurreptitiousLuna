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

int N;
set<int> friendNumberSet;
int friendNumberHashTable[50]; // 9999 ==> 36

int calculateFriendNumber(int x) {
    assert(x >= 0);
    int rt = 0;
    do {
        rt += x % 10;
        x /= 10;
    } while (x > 0);
    return rt;
}

int cnt = 0;

int pat_solver() {
    fill(friendNumberHashTable, friendNumberHashTable + 50, 0);
    scanf("%d", &N);
    int _n;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_n);
        int _f = calculateFriendNumber(_n);
        friendNumberHashTable[_f]++;
        if (friendNumberHashTable[_f] >= 1) {
            friendNumberSet.insert(_f);
        }
    }
    printf("%zu\n", friendNumberSet.size());
    int flag = true;
    for (auto i:friendNumberSet) {
        if(flag){
            printf("%d", i);
            flag = false;
        }else{
            printf(" %d",i);
        }
    }

    return 0;
}

/*
测试样例



*/