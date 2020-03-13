//
// Created by shaob on 2020/2/20.
//
#include "../bin/1t_Class_PAT/PATHeader.h"

/*
 * Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where −10
​6
​​ ≤a,b≤10
​6
​​ . The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input:
-1000000 9

Sample Output:
-999,991
 */

int PAT1001() {
    int a, b, c, w = 0;
    vector<int> v;
    cin >> a >> b;
    c = a + b;
    if (c < 0)
        cout << "-";
    c = abs(c);
    do {
        v.push_back(c % 1000);
        c = c / 1000;
    } while (c != 0);
    while (!v.empty()) {
        c = v.back();
        if (w == 0) {
            printf("%d", c);
            w = 1;
        } else
            printf("%.3d", c);
        v.pop_back();
        if (!v.empty())
            cout << ",";
    }
    return 0;
}