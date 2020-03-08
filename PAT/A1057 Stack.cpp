//
// Created by shaob on 2020/3/7.
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

using namespace std;
#define MaxSize 100489
#define BlockSize 317 // sqrt(100489)

stack<int> Stack;
int Table[MaxSize];// 记录当前元素存在的个数
int Blocks[BlockSize];// 记录每一块中存在元素的个数
//int indexTable = 0;
/*
 * 给栈增加一个操作，PeekMedian 能直接获取栈内的中位数。
 * 采用分块查找的思想
 */

void push(int element) {
    Blocks[element / BlockSize]++;
    Table[element]++;
    Stack.push(element);
}

int pop() {
    int x = Stack.top();
    Blocks[x / BlockSize]--;
    Table[x]--;
    Stack.pop();
    return x;
}

int peekMedia(int pos) {
    /*
     * pos ==> 中间位置
     */
    int current = 0;
    int blockId = 0;
    while (Blocks[blockId] + current < pos) { // 查找块
        current += Blocks[blockId++];
    }
    int num = blockId * BlockSize;
    while (Table[num] + current < pos) { // 查找块内
        current += Table[num++];
    }
    return num;
}

int N;

int pat_solver() {
    fill(Table, Table + MaxSize, 0);
    fill(Blocks, Blocks + BlockSize, 0);
    char buffer[30];
    int _;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", buffer);
        if (strcmp(buffer, "Push") == 0) {
            scanf("%d", &_);
            push(_);
        } else if (strcmp(buffer, "Pop") == 0) {
            if (Stack.empty()) {
                printf("Invalid\n");
                continue;
            }
            printf("%d\n", pop());
        } else if (strcmp(buffer, "PeekMedian") == 0) {
            if (Stack.empty()) {
                printf("Invalid\n");
                continue;
            }
            int pos = Stack.size() % 2 == 1 ? ((int(Stack.size()) + 1) / 2) : (int(Stack.size()) / 2);
            printf("%d\n", peekMedia(pos));
        }
    }
    return 0;
}

/*
测试样例



*/