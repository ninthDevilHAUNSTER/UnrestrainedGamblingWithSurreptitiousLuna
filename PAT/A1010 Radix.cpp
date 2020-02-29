//
// Created by shaob on 2020/2/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>


using namespace std;
typedef long long LL;
LL m[256]; // 10 + 26
LL INF = (1LL << 63) - 1; // LL 的最大值

void __init__() {
    for (char i = '0'; i <= '9'; ++i) {
        m[i] = i - '0';
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        m[i] = i - 'a' + 10;
    }
}

char KN[12], UKN[12];
LL KN_num, UKN_num;
LL KN_base, UKN_base = -1;

LL cal_sum(char num[], LL base, LL inf) {
    LL rt_value = 0;
    for (int i = 0; i < strlen(num); ++i) {
        rt_value = rt_value * base + m[num[i]];
        if (rt_value < 0 || rt_value > inf) {
            return -1; // 溢出
        }
    }
    return rt_value;
}

int cmp(char n2[], LL base, LL num1) {
    // 将 n2转化为base进制与num1作比较
    LL num2 = cal_sum(n2, base, num1);
    if (num2 < 0) return 1; // 如果溢出或者超出阈值，那么就是大于
    if (num2 > num1) return 1;
    else if (num2 == num1) return 0;
    else return -1;
}

LL find_lower_boundary(char num[]) {
    LL rt_value = -1;
    for (int i = 0; i < strlen(num); i++) {
        if (rt_value < m[num[i]]) rt_value = m[num[i]];
    }
    return rt_value + 1;
}

int binary_find_radix(LL low, LL high) {
    LL mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        int flag = cmp(UKN, mid, KN_num);
        if (flag == -1) {
            low = mid + 1;
        } else if (flag == 0) {
            return mid;
        } else if (flag == 1) {
            high = mid - 1;
        }
    }
    return -1; // 正常退出则失败
}

int pat_solver() {
    __init__();
    char N1[12], N2[12];
    int tag;
    int base;
    scanf("%s%s%d%d", N1, N2, &tag, &base);
    KN_base = base;
    if (tag == 1) {
        strcpy(KN, N1);
        strcpy(UKN, N2);
    } else {
        strcpy(KN, N2);
        strcpy(UKN, N1);
    }
    KN_num = cal_sum(KN, KN_base, INF);
    LL low = find_lower_boundary(UKN);
    LL high = max(low, KN_num) + 1; // 进制是可以突破36的，比如 1000000 === 10 当且仅当1位1000000进制的时候成立
    UKN_base = binary_find_radix(low, high);
    if (UKN_base == -1) {
        printf("Impossible");
    } else {
        printf("%lld", UKN_base);
    }
    return 0;
}