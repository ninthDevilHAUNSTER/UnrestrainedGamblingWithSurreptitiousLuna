//
// Created by shaob on 2020/3/20.
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

struct tree {
    int tree_id = 0;
    int apple_cnt = 0;

    tree(int _1, int _2) : tree_id(_1), apple_cnt(_2) {};

    tree() = default;

    bool operator<(const tree &node) const {
        if (apple_cnt != node.apple_cnt) {
            return apple_cnt < node.apple_cnt;
        } else {
            return tree_id < node.tree_id;
        }
    }
};

vector<tree> Trees;

int SHUGUOoperation() {

}

int ccf_solver() {
    int N, M;
    scanf("%d%d", &N, &M);
    int max_cut_id = 0;
    int max_cut = -1;
    int max_leave_id = 0;
    int max_leave = -1;
    int leaves = 0;
    for (int i = 1; i <= N; ++i) {
        int a[M + 1];
        int current_cut = 0;
        for (int j = 0; j <= M; ++j) {
            scanf("%d", &a[j]);
        }
        for (int k = 1; k <= M; ++k) {
            a[0] += a[k];
            current_cut += -a[k];
        }
        if (a[0] > max_leave) {
            max_leave = a[0];
            max_leave_id = i;
        } else if (a[0] == max_leave) {
            max_leave_id = min(i, max_leave_id);
        }
        if (current_cut > max_cut) {
            max_cut = current_cut;
            max_cut_id = i;
        } else if (a[0] == max_cut) {
            max_cut_id = min(i, max_cut_id);
        }
        leaves += a[0];
    }
//    sort(Trees.begin(), Trees.end());
    printf("%d %d %d", leaves, max_cut_id, max_cut);
    return 0;
}

/*
测试样例



*/