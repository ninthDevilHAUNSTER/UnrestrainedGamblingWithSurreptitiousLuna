//
// Created by shaob on 2020/2/25.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <map>
#include <string>
#include <vector>

using namespace std;

int rate[24] = {0};

struct DateTime {
    int dd = 0, HH = 0, MM = 0;
};

static void printDateTime(const DateTime &d) {
    printf("%02d:%02d:%02d ", d.dd, d.HH, d.MM);
}

struct PhoneRecord {
    char name[25]{};
    int mm{};
    DateTime date;
    bool on_line = false;
} record[1024];
int _rec_num = 0;

void __init__() {
    for (int &i : rate) {
        scanf("%d", &i);
    }
    scanf("%d", &_rec_num);
    for (int j = 0; j < _rec_num; ++j) {
        char _t[10];
        DateTime _d;
        scanf("%s %d:%d:%d:%d %s",
              record[j].name, &record[j].mm, &_d.dd, &_d.HH, &_d.MM, _t);
        // 多用char 少用 string...
        record[j].on_line = strcmp(_t, "on-line") == 0;
        record[j].date = _d;
    }
}

int cmp(const PhoneRecord &a, const PhoneRecord &b) {
    int s = strcmp(a.name, b.name); // 先按人名的字典序排序
    if (s != 0) {
        return s < 0;
    } else if (a.mm != b.mm) { // 然后再按日期排序
        return a.mm < b.mm;
    } else if (a.date.dd != b.date.dd) {
        return a.date.dd < b.date.dd;
    } else if (a.date.HH != b.date.HH) {
        return a.date.HH < b.date.HH;
    } else {
        return a.date.MM < b.date.MM;
    }
}

vector<pair<DateTime, DateTime>> current_user_bill;

void calculate(int i) {
    double sum = 0.0;
    for (auto bill:current_user_bill) {
        printDateTime(bill.first);
        printDateTime(bill.second);
        // 基本的想法就是让second 不断减小到零。
        int time = 0;
        double money = 0.0;
        while (bill.second.dd > bill.first.dd
               || bill.second.MM > bill.first.MM
               || bill.second.HH > bill.first.HH) {
            time++;
            money += rate[bill.first.HH];
            bill.first.MM++;
            if (bill.first.MM >= 60) {
                bill.first.MM = 0;
                bill.first.HH++;
            }
            if (bill.first.HH >= 24) {
                bill.first.HH = 0;
                bill.first.dd++;
            }
        }
        printf("%d $%.02f\n", time, money / 100);
        sum += money / 100;
    }
    if (i == _rec_num - 1) {
        printf("Total amount: $%.02f", sum);
    } else {
        printf("Total amount: $%.02f\n", sum);
    }
}

void classify() {
    PhoneRecord current = record[0];
    for (int i = 1; i < _rec_num; ++i) {
//        cout << current.name << "\t" << record[i].name << "\t" << strcmp(current.name, record[i].name) << endl;
        if (strcmp(current.name, record[i].name) != 0 || i == _rec_num - 1) { /// 这里还有一个边界条件我debug了一个多小时我吐了。
            if (!current_user_bill.empty()) {
                printf("%s %02d\n", record[i - 1].name, record[i - 1].mm);
                calculate(i);
                current_user_bill.clear();
            }
            current = record[i];
        } else {
            if (record[i - 1].on_line && !record[i].on_line) {
                current_user_bill.emplace_back(record[i - 1].date, record[i].date);
            }
        }
    }
}

int pat_solver() {
    __init__();
    sort(record, record + _rec_num, cmp);
    classify();
    return 0;
}

