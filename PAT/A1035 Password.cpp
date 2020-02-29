//
// Created by shaob on 2020/2/25.
//


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct account {
    string ac;
    string pwd;

    account(string _ac, string _pwd) : ac(move(_ac)), pwd(move(_pwd)) {};
};

bool ch_pwd(string &pwd) {
    bool ch_flag = false;
    for (char &i : pwd) {
        if (i == '1') {
            i = '@';
            ch_flag = true;
        } else if (i == '0') {
            i = '%';
            ch_flag = true;
        } else if (i == 'l') {
            i = 'L';
            ch_flag = true;
        } else if (i == 'O') {
            i = 'o';
            ch_flag = true;
        }
    }
    return ch_flag;
}

int pat_solver() {
    int N;
    scanf("%d", &N);
    vector<account> acc;
    vector<account> ch_acc;
    for (int i = 0; i < N; ++i) {
        string _, __;
        cin >> _ >> __;
        account _a(_, __);
        acc.push_back(_a);
    }
    for (auto &a:acc) {
        if (ch_pwd(a.pwd)) {
            ch_acc.push_back(a);
        }
    }
    if (ch_acc.empty()) {
        if (N == 1) {
            printf("There is %d account and no account is modified", N);
        } else {
            printf("There are %d accounts and no account is modified", N);
        }
    } else {
        printf("%zu\n", ch_acc.size());
        for (int i = 0; i < ch_acc.size(); ++i) {
            account a = ch_acc[i];
            if (i == ch_acc.size() - 1) {
                printf("%s %s", (a.ac).c_str(), (a.pwd).c_str());
            } else {
                printf("%s %s\n", (a.ac).c_str(), (a.pwd).c_str());
            }
        }
    }
    return 0;
}