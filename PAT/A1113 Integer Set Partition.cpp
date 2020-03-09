//
// Created by shaob on 2020/3/9.
//

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

/* 水得不行 */
int pat_solver() {
    int n, sum = 0, halfsum = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n / 2; i++)
        halfsum += v[i];
    printf("%d %d", n % 2, sum - 2 * halfsum);
    return 0;
}