//
// Created by shaob on 2020/2/27.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;

double Cmax, D, Davg;
int N;
double current_location; // 当前所在的加油站的位置
struct Station {
    double dis;
    double price;
} station[512];

bool cmp(const Station &a, const Station &b) {
    if (a.dis != b.dis) {
        return a.dis < b.dis;
    } else {
        return a.price < b.price;
    }
}

int main() {
    double sum_price = 0.0;
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lf%lf", &station[i].price, &station[i].dis);
    }
    sort(station, station + N, cmp);
    station[N].dis = D;
    station[N].price = 0.00;
    // CASE 1 开局没有油箱的情况
    if (station[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    } else {
        double nowTank = 0, maxTankDistance = Cmax * Davg;
        int now = 0; // 当前所属的加油站编号。
        while (now < N) {
            int k = -1; // 油价最低的加油站编号
            double min_price = 0x3fffffff; // 油价最低的加油站的价格
            for (int i = now + 1; i <= N && station[i].dis - station[now].dis <= maxTankDistance; ++i) {
                if (station[i].price < min_price) {
                    min_price = station[i].price;
                    k = i;
                    if (min_price < station[now].price) {
                        break; // 如果比当前的油耗还要低，则后面的不用找了。
                    }
                }
            }
            if (k == -1) break; // 找不到加油站。退出循环
            double need = (station[k].dis - station[now].dis) / Davg; // 所需要的油耗
            if (min_price < station[now].price) {
                // 找到了一个更好的加油站，在当前加油站补充好能够到那个加油站的油，然后开过去。
                if (nowTank >= need) {
                    // 不用补充，直接开过去
                    nowTank -= need;
                } else {
                    // 需要补充
                    sum_price += (need - nowTank) * station[now].price;
                    nowTank = 0; // 到k的时候正好没有油
                }
            } else {
                // 没有找到更好的加油站，在当前加油站加满油，然后开到最远的加油站。
                sum_price += (Cmax - nowTank) * station[now].price;
                nowTank = Cmax - need;
            }
            now = k;
        }
        if (now == N) {
            printf("%.2f", sum_price);
        } else {
            printf("The maximum travel distance = %.2f", maxTankDistance + station[now].dis);
        }
    }
    return 0;
}
