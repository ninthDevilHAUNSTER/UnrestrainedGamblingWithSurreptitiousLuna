//
// Created by shaob on 2020/3/1.
//

#include <stack>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int M, N, K;

int pat_solver() {
    scanf("%d%d%d", &M, &N, &K);
    // M stack size
    int _;
    for (int i = 0; i < K; ++i) {
        stack<int> S;
        queue<int> seq;
        for (int j = 0; j < N; ++j) {
            scanf("%d", &_);
            seq.push(_);
        }
        bool rt_flag = true;
        for (int k = 1; k <= N; ++k) {
            S.push(k);
            if (S.size() > M) {
                rt_flag = false;
                break;
            } else {
                while (!S.empty() && S.top() == seq.front()) {
                    S.pop();
                    seq.pop();
                }
//             ?   cout << endl;
            }
        }
        seq.empty() && rt_flag ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}