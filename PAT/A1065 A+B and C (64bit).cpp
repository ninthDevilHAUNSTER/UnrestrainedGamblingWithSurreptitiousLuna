//
// Created by shaob on 2020/2/25.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
// 该题目书写有误，应该是 [-2**63,2**63) 这样的范围。

//long long int	8	-9223372036854775808～+9223372036854775807
// CASE 3 中给出的是LONG LONG 的最大两个数字表达
int pat_solver() {
//    A+B>C ?
    long long a, b, c;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld%lld%lld", &a, &b, &c);
        // A+B 正溢出，则必然成立，此时A+B <0;A>0;B>0; 范围是 -2**63 , -2
        // A+B 负溢出，则必然不成立，此时A+B>=0;A<0;B<0; 范围是 0, 2**63
        // 否则正常考虑
        long long sum = a+b;
        if (a > 0 && b > 0 && sum< 0) { // 这里不能写成 a+b < 0 因为按照规则，a+b的结果会转化为 int 类型
            printf("Case #%d: true\n", i + 1);
        } else if (a < 0 && b < 0 && sum >= 0) {
            printf("Case #%d: false\n", i + 1);
        } else {
            if (sum > c) {
                printf("Case #%d: true\n", i + 1);
            } else {
                printf("Case #%d: false\n", i + 1);
            }
        }
    }

    return 0;
}