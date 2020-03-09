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

int N, K;

/*
 * 1..N
 *
 * N number of query
 * K max recommend show to user
 *
 * then give query that user is accessing;
 *
 */

struct node {
    int id = -1;
    int cnt = 1;

    node(int _i, int _c) : id(_i), cnt(_c) {};

    bool operator<(const node &n) const {
        if (cnt != n.cnt) {
            return cnt > n.cnt;
        } else {
            return id < n.id;
        }
    }
};

set<node> result;
int Hash[500012];

int pat_solver() {
    fill(Hash, Hash + 500012, 0);
    scanf("%d%d", &N, &K);
    int click;
    scanf("%d", &click);
    assert(N >= 1);
    result.insert({click, 1});
    Hash[click]++;
    for (int i = 1; i < N; ++i) {
        scanf("%d", &click);
        printf("%d:", click);
        int printTime = 0;
        for (auto s:result) {
            printf(" %d", s.id);
            if (++printTime >= K) break;
        }

        printf("\n");
        if (Hash[click] == 0) {
            result.insert({click, 1});
            Hash[click]++;
        } else {
            node x(click, Hash[click]);
            auto s = result.find(x);
            assert(s != result.end());
            result.erase(s);
            Hash[click]++;
            result.insert({click, Hash[click]});
        }
    }
    return 0;
}

/*
测试样例

5: 3
7: 3 5
5: 3 5 7
5: 5 3 7
3: 5 3 7
2: 5 3 7
1: 5 3 2
8: 5 3 1
3: 5 3 1
8: 3 5 1
12: 3 5 8

*/