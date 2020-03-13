//
// Created by shaob on 2020/3/13.
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


int N;
vector<int> heap;
vector<int> tmpPath;
bool isHeap = true;
bool isMaxHeap = true;

void DFS(int x) {
    if (x * 2 > N) {
        if (x <= N) {
            for (int i = 0; i < tmpPath.size(); ++i) {
                printf("%d", heap[tmpPath[i]]);
                if (i < tmpPath.size() - 1)printf(" "); else printf("\n");
                if (i > 1) {
                    if (isMaxHeap && heap[tmpPath[i]] > heap[tmpPath[i - 1]]) isHeap = false;
                    if (!isMaxHeap && heap[tmpPath[i]] < heap[tmpPath[i - 1]]) isHeap = false;
                }
            }
        }
    } else {
        tmpPath.push_back(x * 2 + 1); // 这个是题目的意思，应该是i先左后右其实
        DFS(x * 2 + 1);
        tmpPath.pop_back();
        tmpPath.push_back(x * 2);
        DFS(x * 2);
        tmpPath.pop_back();
    }

}

int pat_solver() {
    scanf("%d", &N);
    heap.resize(N * 3);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &heap[i]);
    }
    isMaxHeap = heap[1] > heap[2];
    tmpPath.push_back(1);
    DFS(1);
    !isHeap ? printf("Not Heap") : (isMaxHeap ? printf("Max Heap") : printf("Min Heap"));
    return 0;
}

/*
测试样例



*/