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

/*
 * 找单身狗
 */

#define MaxSize 50010
#define MaxIDSize 100010

int another_half[MaxIDSize];
bool isAttend[MaxIDSize];
int N, M;
set<int> singleSet;
vector<int> inputVec;

int pat_solver() {
    fill(another_half, another_half + MaxIDSize, -1);
    fill(isAttend, isAttend + MaxIDSize, false);
    scanf("%d", &N);
    int _1, _2;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &_1, &_2);
        another_half[_1] = _2;
        another_half[_2] = _1;
    }
    scanf("%d", &M);
    for (int j = 0; j < M; ++j) {
        scanf("%d", &_1);
        isAttend[_1] = true;
        inputVec.push_back(_1);
    }
    for (auto i:inputVec) {
        if (another_half[i] == -1 || !isAttend[another_half[i]]) {
            singleSet.insert(i);
        }
    }
    printf("%zu\n", singleSet.size());
    int flag = true;
    for (auto i:singleSet) {
        if(flag){
            printf("%05d", i);
            flag = false;
        }else{
            printf(" %05d",i);
        }
    }


    return 0;
}

/*
测试样例



*/