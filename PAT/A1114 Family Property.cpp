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

int N;
#define MaxSize 10000

struct FamilyMember {
    int id = 0; // 4 digit num
    int father = -1; // parent ; if pass away is -1
    int mother = -1;
//    int femaleAncestor
// 如果有孩子，那就把孩子给拆开来。
    int k = 0; // number of children
    vector<int> children; // id of children ;
    double estate_num = 0; // total number of real estate under name
    double area = 0; // total area of estate;
//    bool visFlag = false;
    FamilyMember() = default;
} Family[MaxSize];


struct FamilyInfo {
    int id = 0;//the smallest id in family
    int M = 0;//total number of family
    double AVGsets = 0.0; // 人均几套房? %.3f
    double AVGarea = 0.0; // 人均多少平方?
    bool valid = false;
} info[MaxSize];
int infoValidCnt = 0;

/*
 * family number
 *
 */
int father[MaxSize];
bool vis[MaxSize];

int FindAncestor(int x) {
    while (x != father[x]) x = father[x];
    return x;
}

void Union(int x, int y) {
    int fx = FindAncestor(x);
    int fy = FindAncestor(y);
    if (fx != fy) {
        fx < fy ? father[fy] = fx : father[fx] = fy;
    }
}

void Init() {
    fill(vis, vis + MaxSize, false);
    for (int i = 0; i < MaxSize; ++i) {
        father[i] = i;
    }
}

//vector<FamilyInfo> result;

bool cmp0(const FamilyInfo &a, const FamilyInfo &b) {
    if (a.valid != b.valid) {
        return a.valid;
    }
}

bool cmp(const FamilyInfo &a, const FamilyInfo &b) {
    if (a.AVGarea != b.AVGarea) {
        return a.AVGarea > b.AVGarea;
    } else {
        return a.id < b.id;
    }
}

int pat_solver() {
    Init();
    scanf("%d", &N);
    int _id, _f, _m, _k, _c;
    double _e, _a;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d%d", &Family[i].id, &Family[i].father, &Family[i].mother, &Family[i].k);
        vis[Family[i].id] = true;
        if (Family[i].mother != -1) {
            vis[Family[i].mother] = true;
            Union(Family[i].id, Family[i].mother);
        }
        if (Family[i].father != -1) {
            vis[Family[i].father] = true;
            Union(Family[i].id, Family[i].father);
        }
        for (int j = 0; j < Family[i].k; ++j) {
            scanf("%d", &_c);
            Family[i].children.push_back(_c);
            vis[_c] = true;
            Union(Family[i].id, _c);
        }
        scanf("%lf%lf", &Family[i].estate_num, &Family[i].area);
    }
    for (int k = 0; k < N; ++k) {
        /*
         * 统计所有房产信息，这里是遍历
         */
        int ancestor = FindAncestor(Family[k].id);
        info[ancestor].id = ancestor;
//        info[ancestor].M++; // 如果加k会重复算的,想了想还是分开搞
        info[ancestor].AVGsets += Family[k].estate_num;
        info[ancestor].AVGarea += Family[k].area;
        info[ancestor].valid = true;
    }
    for (int l = 0; l < MaxSize; ++l) {
        /*
         * 统计人数
         */
        if (vis[l]) {
            info[FindAncestor(l)].M++;
        }
        if (info[l].valid) infoValidCnt++;
    }
    // 计算平均值
    for (auto & m : info) {
//        assert(info[m].valid);
        if (m.valid) {
            m.AVGarea = m.AVGarea / m.M;
            m.AVGsets = m.AVGsets / m.M;

        }
    }
    sort(info, info + MaxSize, cmp);
    printf("%d\n", infoValidCnt);
    for (int n = 0; n < infoValidCnt; ++n) {
        printf("%04d %d %.3lf %.3lf\n", info[n].id, info[n].M, info[n].AVGsets, info[n].AVGarea);
    }
    return 0;
}

/*
测试样例



*/