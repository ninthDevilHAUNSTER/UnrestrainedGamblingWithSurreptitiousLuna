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
 * 欧拉路径
 *
 * 恰好两个奇数顶点。并且所有欧拉路径从这个点开始，另一个点结束，则称之为欧拉路径。
 *
 * 若具有欧拉路径，但不是欧拉回路的图称之为半欧拉图。
 *
 * 给定一个无向图。按点编号升序输出点的度数，并判断是否由欧拉路径
 *
 * 大概思路：
 *
//不好意思，这个思路不对。。。
// * DFS 遍历全图，遍历的时候把回边给删掉。
// * 如果访问完毕后，所有边都删了，还能回到起点就是欧拉路。
// * 如果所有边都删了但是回不到起点，就是半欧拉。
// * 否则就啥都不行。
 *
 * 看节点的度是多少。（邻接表）
 * 判断连通性，如果不连通，那就一定是菲欧拉图
 *
 */
#define MaxSize 512
int N, M;
vector<int> Graph[MaxSize];
vector<int> du;
int cnt = 0; // 能访问到的点的个数
bool vis[MaxSize];

void DFS(int v) {
    vis[v] = true;
    cnt++;
    for (auto node:Graph[v]) {
        if (!vis[node])
            DFS(node);
    }
}

int pat_solver() {
    scanf("%d%d", &N, &M);
    fill(vis, vis + MaxSize, false);
    int _1, _2;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &_1, &_2);
        Graph[_1].push_back(_2);
        Graph[_2].push_back(_1);
    }
    int even = 0; // 偶数节点个数
    for (int j = 1; j <= N; ++j) {
        if (j != 1)printf(" ");
        printf("%zu", Graph[j].size());
        if (Graph[j].size() % 2 == 0) even++;
    }
    printf("\n");
    DFS(1);
    if (cnt == N && even == N) {
        printf("Eulerian");
    } else if (even == N - 2 && cnt == N) {
        printf("Semi-Eulerian");
    } else {
        printf("Non-Eulerian");
    }


    return 0;
}

/*
测试样例



*/