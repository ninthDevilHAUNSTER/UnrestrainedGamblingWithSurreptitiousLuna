//
// Created by shaob on 2020/2/25.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
#define MaxSize 100005
int dis[MaxSize];//dis 表示第1个节点到第i+1个节点的路程。
int sum = 0;// 一圈的综合
int N = 0;;
int M = 0;

int pat_solver() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        int tmp = 0;
        scanf("%d", &tmp);
        sum += tmp;
        dis[i] = sum;
    }
    scanf("%d", &M);
    for (int j = 0; j < M; ++j) {
        int left = 0, right = 0;
        scanf("%d%d", &left, &right);
        if (right < left) {
            swap(right, left);
        }
        int d = dis[right - 1] - dis[left - 1];
        printf("%d\n", min(d, sum - d));
    }
    return 0;
}
