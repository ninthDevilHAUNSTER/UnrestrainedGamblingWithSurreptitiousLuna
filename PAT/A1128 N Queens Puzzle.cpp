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

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        vector<int> v(n);
        bool result = true;
        for (int j = 0; j < n; j++) {
            cin >> v[j];
            for (int t = 0; t < j; t++) {
                if (v[j] == v[t] || abs(v[j]-v[t]) == abs(j-t)) {
                    result = false;
                    break;
                }
            }
        }
        cout << (result == true ? "YES\n" : "NO\n");
    }
    return 0;
/*
bool Graph[8][8];
vector<int> position;

bool judge() {
    for (int i = 0; i < 8; ++i) { // i 列号
        int j = position[i]; // j 行号
        for (int k = 0; k < 8; ++k) {
            if (k == i) continue;
            if (Graph[j][k]) return false;
        }
    }
}


int pat_solver() {
    int _;
    scanf("%d", &_);
    for (int i = 0; i < _; ++i) {
        position.clear();
        fill(Graph[0], Graph[0] + 8 * 8, false);
        int _1, _2;
        scanf("%d", &_1);
        for (int j = 0; j < _1; ++j) {
            scanf("%d", &_2);
            Graph[i][_2 - 1] = true;
            position.push_back(_2 - 1);
        }
        if (judge()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
*/
/*
测试样例



*/