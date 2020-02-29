//
// Created by shaob on 2020/2/28.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
vector<int> raw1, raw2;
vector<int> on_step;


bool MergeSort(vector<int> &raw) {
    bool rt_flag = false;
    int n = 2;
    bool first_flag = true;
    for (; n / 2 <= raw.size(); n *= 2) {
        if (!first_flag && raw == on_step) {
            rt_flag = true;
        }
        for (int i = 0; i < raw.size(); i += n) {
            sort(raw.begin() + i, min(raw.end(), raw.begin() + n + i));
        }
        first_flag = false;
        if (rt_flag) {
            return true;
        }
    }
    return false;
}

bool InsertSort(vector<int> &raw) {
    bool rt_flag = false;
    bool first_flag = true;
    for (int i = 1; i < raw.size(); ++i) {// 代表前i个元素已经排序完毕.
        if (!first_flag && raw == on_step) {
            rt_flag = true;
        }
        // START 插入排序
        int tmp = raw[i], pos = i;
        while (pos > 0 && tmp < raw[pos - 1]) {
            raw[pos] = raw[pos - 1];
            pos--;
        }
        raw[pos] = tmp;
        first_flag = false;
        // END 插入排序
        if (rt_flag) {
            return true;
        }
    }
    return false;
}

void printArray(const vector<int> &v) {
    for (auto i = 0; i < v.size(); i++) {
        int a = v[i];
        if (i == v.size() - 1) {
            printf("%d", a);
        } else {
            printf("%d ", a);
        }
    }
}

int pat_solver() {
    scanf("%d", &N);
    int _;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_);
        raw1.push_back(_);
        raw2.push_back(_);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_);
        on_step.push_back(_);
    }
    if (InsertSort(raw1)) {
        printf("Insertion Sort\n");
        printArray(raw1);
    } else {
        printf("Merge Sort\n");
        MergeSort(raw2);
        printArray(raw2);
    }

    return 0;
}
//Insertion Sort
//1 2 3 5 7 8 9 4 6 0