//
// Created by shaob on 2020/3/12.
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
 * 考虑到其中有2个狼人，至少有1个狼人（但不是全部）都在撒谎，而恰好有2个撒谎者。
 */
int N; // 5...100
bool isGood[128];
vector<int> v;

int pat_solver() {
    cin >> N;
    v.resize(N+1);
    for (int i = 1; i <= N; i++) cin >> v[i];
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            vector<int> lie, a(N + 1, 1);
            a[i] = a[j] = -1;
            for (int k = 1; k <= N; k++)
                if (v[k] * a[abs(v[k])] < 0) lie.push_back(k);
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}

/*
测试样例



*/