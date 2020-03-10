//
// Created by shaob on 2020/3/10.
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
#include <unordered_map>
#include <cmath>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff
#define MaxSize 10010

int N;
vector<int> subway[MaxSize];
//int net[MaxSize][MaxSize];  这个会爆内存
int isTransferStation[MaxSize];
unordered_map<int, int> line; // Station A -> Station B
int K;

/*
 * 给一个地铁线路，找出最短路径，并打印。只要打印换乘即可。
 * 如果有多个方案，输出换乘线路最少的方案。
 *
 * 多次DJ有点蠢...裸DFS就行
 *
 */
int minCnt = INF, minTransfer = INF; // 经停最少的站，需要换乘的最小次数
int start, destination;
int vis[MaxSize];

vector<int> tmpPath, optPath;


int calTransferTime(vector<int> &v) {
    // 计算换乘站的个数
    int rtNum = 0;
    for (const auto i : v) {
        assert(isTransferStation[i] != -1);
        if (isTransferStation[i] >= 1) {
            rtNum++;
        }
    }
    return rtNum;
}

void DFS(int v, int depth) {
    if (v == destination) {
        int tfTime = calTransferTime(tmpPath);
        if (depth < minCnt || (depth == minCnt && tfTime < minTransfer)) {
            minTransfer = tfTime;
            minCnt = depth;
            optPath = tmpPath;
        }
        return;
    }
    for (auto i:subway[v]) {
        if (vis[i] == 0) {
            vis[i]++;
            tmpPath.push_back(i);
            DFS(i, depth + 1);
            vis[i] = 0;
            tmpPath.pop_back();
        }
    }
}

void printPath() {
    printf("%zu\n", optPath.size() - 1);
    if(optPath.size() - 1 == 0)
        return;
    int lineNum = 0;
    int _end, _start = optPath[0];
    for (int i = 1; i < optPath.size(); i++) {
        if (line[optPath[i - 1] * MaxSize + optPath[i]] != lineNum) {
            if(lineNum != 0 ){
                printf("Take Line#%d from %04d to %04d.\n", lineNum, _start, optPath[i - 1]);
            }
            lineNum = line[optPath[i - 1] * MaxSize + optPath[i]];
            _start = optPath[i - 1];
        }
    }
    printf("Take Line#%d from %04d to %04d.\n", lineNum, _start, destination);
}


int pat_solver() {
    fill(isTransferStation, isTransferStation + MaxSize, -1);
    scanf("%d", &N);
    int _c, _s;
    for (int i = 1; i <= N; ++i) {
        int pre, next;
        scanf("%d%d", &_c, &pre);
        isTransferStation[pre]++;
        for (int j = 1; j < _c; ++j) {
            scanf("%d", &next);
            subway[next].push_back(pre);
            subway[pre].push_back(next);
            line[pre * MaxSize + next] = line[next * MaxSize + pre] = i;
            isTransferStation[next]++;
            pre = next;
        }
    }
    scanf("%d", &K);
    for (int k = 1; k <= K; ++k) {
        scanf("%d%d", &start, &destination);
        fill(vis, vis + MaxSize, 0);
        tmpPath.clear();
        optPath.clear();
        minCnt = INF, minTransfer = INF;
        tmpPath.push_back(start);
        DFS(start, 0);
        printPath();
    }
    return 0;
}

/*
测试样例

4
7 1001 3212 1003 1204 1005 1306 7797
9 9988 2333 1204 2006 2005 2004 2003 2302 2001
13 3011 3812 3013 3001 1306 3003 2333 3066 3212 3008 2302 3010 3011
4 6666 8432 4011 1306
1
3212 1204

*/