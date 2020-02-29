//
// Created by shaob on 2020/2/28.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

int set[15];
int N;
using namespace std;
//int elem = 0;

int pat_solver() {
    scanf("%d\n", &N);
    int sum = 0; // 记录除 0 之外不在本位上的数字
    for (int i = 0; i < N; ++i) {
        scanf("%d", &set[i]);
        if (set[i] == i && set[i] != 0) {
            sum++; // 统计除0之外不在本位上的数字个数
        }
    }
    int swap_t = 0; // 交换次数
    int i = 1; // 这样设计可以让i从上一个位置开始减少时间复杂度。
    while (sum < N-1) {
        if (set[0] == 0) { // 若0换到了0号位但是排序还没有结束，则寻找一个最小的不在本位上的数字
            for (; i < N; ++i) {
                if (set[i] != i) {
                    swap(set[i], set[0]);
                    swap_t++;
                    break;
                }
            }
        }

        while (set[0] != 0) { // 如果0没有换到0号位上，要么是上一种if，要么是排序完毕。
            swap(set[0], set[set[0]]); //将 0 （此时0一定在set[set[0]]
            sum++;
            swap_t++;
        }
//        cout << set[0] << endl;
    }
    printf("%d", swap_t);
    return 0;
}