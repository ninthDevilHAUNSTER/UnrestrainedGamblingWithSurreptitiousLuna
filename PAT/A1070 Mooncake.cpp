//
// Created by shaob on 2020/2/26.
//

#include <iostream>
#include <map>

using namespace std;
double N, D;
map<double, double,greater<>> moon_cake;
double _a[1000];
double _p[1000];
double result;

int pat_solver() {
    scanf("%lf%lf", &N, &D);
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &_a[i]);
    }
    for (int j = 0; j < N; ++j) {
        scanf("%lf", &_p[j]);
        if (moon_cake.count(_p[j] / _a[j]) == 1) {
            moon_cake[_p[j] / _a[j]] += _a[j];
        } else
            moon_cake[_p[j] / _a[j]] =  _a[j];
    }
    for (auto a:moon_cake) {
        if (D > a.second) {
            result += a.second * a.first;
            D -= a.second;
        } else {
            result += a.first * D;
            break;
        }
    }
    printf("%.2f", result);
    return 0;
}