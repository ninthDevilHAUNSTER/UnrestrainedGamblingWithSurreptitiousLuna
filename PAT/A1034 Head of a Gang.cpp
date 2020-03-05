//
// Created by shaob on 2020/3/5.
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
#include <unordered_map>

using namespace std;
#define MaxSize 2048
#define inf 0x3fffffff

unordered_map<string, int> name2id;
unordered_map<int, string> id2name;
int N, K;
int net[MaxSize][MaxSize];
int weight[MaxSize * 2];
bool vis[MaxSize * 2];
int pid = 0;  // 总人数

struct Gang {
    int head = -1;
    int group_num = 0;
    Gang(int _h, int _n) : head(_h), group_num(_n) {};
};

vector<Gang> gangs;

void DFS(int node, int &group_num, int &total_curve_sum, int &head) {
    vis[node] = true;
    group_num++;
    if (weight[node] > weight[head]) {
        head = node;
    }
    for (int i = 0; i < pid; ++i) {
        if (net[node][i] != 0) {
            total_curve_sum += net[node][i];
            net[node][i] = net[i][node] = 0; // 防止回头,非常关键
            if (!vis[i])
                DFS(i, group_num, total_curve_sum, head);
        }
    }
}

void DFSTransfer() {
    for (int i = 0; i < pid; ++i) {
        if (!vis[i]) {
            int group_num = 0;
            int total_curve_sum = 0;
            int head = i;
            DFS(i, group_num, total_curve_sum, head);
            if (total_curve_sum > K && group_num > 2) {
                gangs.emplace_back(head, group_num);
            }
        }
    }

}

bool cmp(const Gang &a, const Gang &b) {
    return id2name[a.head] < id2name[b.head];
}

int pat_solver() {
    fill(net[0], net[0] + MaxSize * MaxSize, 0);
    fill(vis, vis + MaxSize * 2, false);
    scanf("%d%d", &N, &K);
    string _1, _2;
    int _t = 0;
    for (int i = 0; i < N; ++i) {
        cin >> _1 >> _2 >> _t;
        if (name2id.find(_1) == name2id.end()) {
            // 没找到
            name2id[_1] = pid;
            id2name[pid] = _1;
            pid++;
        }
        if (name2id.find(_2) == name2id.end()) {
            // 没找到
            name2id[_2] = pid;
            id2name[pid] = _2;
            pid++;
        }
        net[name2id[_1]][name2id[_2]] += _t;
        net[name2id[_2]][name2id[_1]] += _t;
        weight[name2id[_1]] += _t;
        weight[name2id[_2]] += _t;
    }
    DFSTransfer();
    sort(gangs.begin(), gangs.end(), cmp);
    cout << gangs.size() << endl;
    for (auto g:gangs) {
        cout << id2name[g.head] << " " << g.group_num << endl;
    }
    return 0;
}

/*
测试样例



*/