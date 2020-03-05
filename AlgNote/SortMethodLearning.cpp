//
// Created by shaob on 2020/3/4.
//
// 结合 A1098 A1089 来整理一下排序相关的内容
// 像 这两道题中的那样考察排序的下一步序列，应该是一个重点。非常考验考生的基本功吧。
// 恰好我就是那种sort一把刷子刷到底的人。很显然面对这样的问题束手无策。

#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
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
#define MaxSize 0x3fffffff

void printfVec(const vector<int> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        printf("%d", vec[i]);
        (i < vec.size() - 1) ? printf(" ") : printf("\n");
    }
}

void heapSortAdjust(vector<int> &heap, int low, int high) {
    if (low > high) return;
    int child = 2 * low + 1;
    if (child + 1 < high && heap[child + 1] > heap[child]) child++;
    if (child != low) {
        swap(heap[child], heap[low]);
        heapSortAdjust(heap, low, high);
    }
}

int heapStep = 0;

void heapSort(vector<int> query) {
    /*
     *
     */
    heapStep = 0;
    for (int i = int(query.size()) / 2 -1 ; i >= 0; --i) {
        heapSortAdjust(query, i, query.size());
    }
    for (int j = int(query.size()) - 1; j >= 1; --j) {
        swap(query[j], query[0]);
        heapSortAdjust(query, 0, j);
        heapStep++;
        printf("MergeSort %d Step \n", heapStep);
        printfVec(query);
    }

}

void insertSort(vector<int> query) {
    /*
     * 正常来说这里得用引用，不然改的东西回不去。
     */
    for (int i = 1; i < query.size(); ++i) {
//        sort(query.begin(), query.begin() + i); // 简便点这里直接sort了。机试也可以这么玩
        int tmp = query[i], j = i;
        while (j > 0 && query[j - 1] > tmp) { // 实际的操作就是不断推回去。
            query[j] = query[j - 1];
            j--;
        }
        query[j] = tmp;

        printf("InsertSort %d Step \n", i);
        printfVec(query);
    }
}

void mergeSort(vector<int> query) {
    /*
     * 归并的话就是2个，4个这样子合并，中间操作用sort解决，别问我为什么。就是自己菜
     */
    int time = 0;
    for (int step = 0; step / 2 < query.size(); step = step *= 2) {
        for (int i = 0; i < query.size(); i += step) {
            sort(query.begin() + i, query.begin() + min(i + step, int(query.size())));
        }
        time++;
        printf("MergeSort %d Step \n", time);
        printfVec(query);
    }
}

void bubbleSort(vector<int> query) {
    for (int i = 0; i < query.size(); ++i) {
        for (int j = 0; j < query.size() - i - 1; ++j) {
            if (query[j] > query[j + 1]) swap(query[j], query[j + 1]);
        }
        printf("BubbleSort %d Step \n", i);
    }
}

int partition(vector<int> &query, int low, int high) {
    /*
     * 严版的划分
     */
    int piv = query[low];
    while (low < high) {
        while (low < high && piv < query[high]) high--;
        query[low] = query[high];
        while (low < high && piv > query[low]) low++;
        query[high] = query[low];
    }
    query[low] = piv;
    return low;
}

int _fs_time = 0;

void _fastSort(vector<int> &query, int low = 0, int high = 0) {
    /*
     * 我快排的划分部分是按照严版数据结构的，实际上划分算法各家说法不一。
     */
    if (low < high) {
        int mid = partition(query, low, high);
        _fastSort(query, low, mid - 1);
        _fastSort(query, mid + 1, high);
        _fs_time++;
        printf("FastSort %d Step \t mid element is %d\n", _fs_time, query[mid]);
        printfVec(query);
    }
}

void fastSort(vector<int> query) {
    vector<int> q = std::move(query);
    _fastSort(q, 0, int(q.size()) - 1);
}

int alg_solver() {
    vector<int> s = {3, 1, 2, 8, 7, 5, 9, 4, 6, 0};
//    insertSort(s);
    heapSort(s);
    return 0;
}

/*
测试样例



*/