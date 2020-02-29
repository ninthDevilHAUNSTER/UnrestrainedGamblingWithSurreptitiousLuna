//
// Created by shaob on 2020/2/25.
//


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

struct magic_coin {
    long k = 0;
    long s = 0;
    long g = 0;

    magic_coin() = default;

    magic_coin(long _g, long _s, long _k) : g(_g), s(_s), k(_k) {};
};


int pat_solver() {
    long a, b, c;
    scanf("%ld.%ld.%ld", &a, &b, &c);
    magic_coin m1(a, b, c);
    scanf("%ld.%ld.%ld", &a, &b, &c);
    magic_coin m2(a, b, c);
    magic_coin m3;
    long carry;
    m3.k += (m1.k + m2.k) % 29;
    carry = (m1.k + m2.k) / 29;
    m3.s = (m1.s + m2.s + carry) % 17;
    carry = (m1.s + m2.s + carry) / 17;
    m3.g = m1.g + m2.g + carry;
    printf("%ld.%ld.%ld", m3.g, m3.s, m3.k);
}