//
// Created by shaob on 2020/2/29.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cassert>

using namespace std;

struct factor {
    int x, cnt;// x为质因子，cnt为个数
    factor(int _x, int _cnt) : x(_x), cnt(_cnt) {};
};

vector<factor> factorVec;
vector<int> primeTable;


bool isPrime(int s) {
    int sqr = int(sqrt(1.0 * s));
    for (int i = 2; i < sqr; ++i) {
        if (s % i == 0)return false;
    }
    return true;
}

void mkPrimeTable(vector<int> &table, int find_num_range = 100) { // 求 2 - 100
    for (int i = 2; i < find_num_range; ++i) {
        if (isPrime(i)) primeTable.push_back(i);
    }
}

void findAllFactors(int number) {
    assert(number >= 2);
    int sqr = int(sqrt(number * 1.0));
    for (auto p:primeTable) {
        if (p > sqr) break;
        if (number % p == 0) {
            while (number % p == 0) {
                if (factorVec.empty() || factorVec.back().x != p) {
                    factorVec.emplace_back(p, 1);
                } else {
                    factorVec.back().cnt++;
                }
                number /= p;
            }
        }
    }
    if (number != 1) {
        factorVec.emplace_back(number, 1);
    }
}

int pat_solver() {
    mkPrimeTable(primeTable, 100000);
    int number;
    cin >> number;
    if (number == 1) {
        cout << "1=1";
        return 0;
    }
    findAllFactors(number);
    cout << number << "=";
    for (auto f:factorVec) {
        if (f.cnt != 1) {
            cout << f.x << "^" << f.cnt;
        } else {
            cout << f.x;
        }
        if (f.x != factorVec.back().x) {
            cout << "*";
        }
    }
    return 0;
}