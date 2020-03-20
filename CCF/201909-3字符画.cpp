//
// Created by shaob on 2020/3/20.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <cassert>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff

string ch_frontColor(int R, int G, int B) {
    return "\x1B[38;2;"
           + to_string(R) + ";"
           + to_string(G) + ";"
           + to_string(B) + "m";
}

string ch_backColor(int R, int G, int B) {
    return "\x1B[48;2;"
           + to_string(R) + ";"
           + to_string(G) + ";"
           + to_string(B) + "m";
}



int M, N;
int p, q;
string NEWLINE = "\x0D";
string RETURN = "\x0A"; // 换行
string DEFAULT = "\x1B[0m";


//
//
//void split_color2(string &s, string &R, string &G, string &B) {
//    for (auto &i: s) {
//        i = toupper(i);
//    }
//    if (s.length() == 2) {
//        R = G = B = s.substr(1, 1) + s.substr(1, 1);
//    } else if (s.length() == 4) {
//        R = s.substr(1, 1) + s.substr(1, 1);
//        G = s.substr(2, 1) + s.substr(2, 1);
//        B = s.substr(3, 1) + s.substr(3, 1);
//    } else {
//        R = s.substr(1, 2);
//        G = s.substr(3, 2);
//        B = s.substr(5, 2);
//    }
//}

void split_color(string &s, int &R, int &G, int &B) {
    if (s.length() == 2) {
        int _i = stoi(s.substr(1, 1) + s.substr(1, 1), nullptr, 16);
        R = G = B = _i;
    } else if (s.length() == 4) {
        R = stoi(s.substr(1, 1) + s.substr(1, 1), nullptr, 16);
        G = stoi(s.substr(2, 1) + s.substr(2, 1), nullptr, 16);
        B = stoi(s.substr(3, 1) + s.substr(3, 1), nullptr, 16);
    } else {
        R = stoi(s.substr(1, 2), nullptr, 16);
        G = stoi(s.substr(3, 2), nullptr, 16);
        B = stoi(s.substr(5, 2), nullptr, 16);
    }
}

vector<vector<array<int, 3>>> img;

int csp_solver() {
//    int _i = stoi("ef", nullptr, 16);
//    cout << _i;
    scanf("%d%d", &M, &N); // 宽,高
    scanf("%d%d", &p, &q); // 每一小块的宽和搞
    string rbg;
    int R, G, B;
    img.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> rbg;
            split_color(rbg, R, G, B);
            img[i].push_back(array<int, 3>{0, 0, 0});
            img[i].back()[0] = R;
            img[i].back()[1] = G;
            img[i].back()[2] = B;
        }
    }
    array<int, 3> start = {0, 0, 0}, last = {0, 0, 0};
    for (int i = 0; i < N / q; ++i) {
        for (int j = 0; j < M / p; ++j) {
            array<int, 3> avg = {0, 0, 0};
            for (int k = 0; k < q; ++k) {
                for (int l = 0; l < p; ++l) {
                    for (int m = 0; m < 3; ++m) {
                        avg[m] += img[i * q + k][j * p + l][m];
                    }
                }
            }
            for (int n = 0; n < 3; ++n) {
                avg[n] /= p * q;
            }
            if (avg != last) { // 与上一块颜色分量不同
                if (avg == start) {

                }
            }
        }
    }
    return 0;
}

/*
测试样例



*/
