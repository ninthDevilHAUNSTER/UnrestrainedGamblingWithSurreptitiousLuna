//
// Created by shaob on 2020/2/29.
//

#include <iostream>
// 输出两个递增序列的中位数
#include <vector>
#include <string>

using namespace std;
#define MAX_RANGE 1000000007
#define MAX_SIZE 10
string s;

int left_P[MAX_SIZE], right_T[MAX_SIZE];
vector<int> A_loc_vec;
long long sum = 0;

int pat_solver() {
    cin >> s;
    (s[0] == 'P') ? left_P[0] = 1 : left_P[0] = 0;
    (s.back() == 'T') ? right_T[s.length() - 1] = 1 : right_T[s.length() - 1] = 0;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == 'P') {
            left_P[i] = left_P[i - 1] + 1;
        } else {
            left_P[i] = left_P[i-1];
            if (s[i] == 'A') {
                A_loc_vec.push_back(i);
            }
        }
    }
    for (int i = int(s.length() - 2); i >= 0; --i) {
        if (s[i] == 'T') {
            right_T[i] = right_T[i + 1] + 1;
        } else {
            right_T[i] = right_T[i+1];
        }
    }
    for (auto loc:A_loc_vec) {
        sum = (sum + right_T[loc] * left_P[loc]) % MAX_RANGE;
    }
    printf("%lld", sum);
    return 0;
}