//
// Created by shaob on 2020/3/6.
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

using namespace std;
#define MaxSize 401

int N, K, P;
vector<int> fac;

/*
 * 给定数字N，寻找K个数字的p方和等于这个数字，并寻找底数序列最大的方案。
 */

vector<int> ans, tmp;/// 最佳底数序列，目前底数序列
int maxfacSum = -1;

void DFS(int index, int nowK, int sum, int facSum) {
    /*
     * index :: 当前访问的fac下标
     * nowK :: 目前选中元素的个数
     * sum :: 目前选中元素的和（p方和)
     * facSum :: 底数和
     *
     * 这是DFS的搜索，不是遍历，和遍历有点的区别是在于
     * 我们是从一个点往下开始搜（ fac[N-1] )
     * 每个点有两种操作，一种是把这个点加入后继续搜索，另一种是寻找不加入这个点，转而寻找这个点前面的节点进行搜索。
     *
     * 之前我写成了遍历，导致超时，实际上如果遍历的话非常容易走回头路。
     *
     */
    if (sum > N || nowK > K) {
//        tmp.pop_back();
        return;
    }
    if (sum == N && nowK == K) {
        if (facSum > maxfacSum) {
            ans = tmp;
            maxfacSum = facSum;
        }
        return;
    }
    if (index > 0) {
        assert(index > 0);
        tmp.push_back(index);
        DFS(index, nowK + 1, sum + fac[index], facSum + index); // 选择当前数字（可重复）的情况
        tmp.pop_back();
        DFS(index - 1, nowK, sum, facSum); // 不选当前数字的情况
    }
}


int pat_solver() {
    scanf("%d%d%d", &N, &K, &P);
    for (int i = 0; i < 1 + pow(N, 1.00 / P); ++i) {
        fac.push_back(pow(i, P));
    }
    DFS(int(fac.size() - 1), 0, 0, 0);
    if (maxfacSum == -1)printf("Impossible");
    else {
        printf("%d = %d^%d", N, ans[0], P);
        for (int i = 1; i < ans.size(); ++i) {
            printf(" + %d^%d", ans[i], P);
        }
    }
    return 0;
}

/*
测试样例



*/