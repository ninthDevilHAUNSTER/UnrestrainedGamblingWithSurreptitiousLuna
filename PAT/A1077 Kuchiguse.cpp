//
// Created by shaob on 2020/2/25.
//

#define WARNING 最后一个样例不知道为啥就是过不去...吐了

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;

void cin_whitespace() {
    /*
     * 利用 cin.getline 输入内容。这里的c不能是string类型。但是可以后续转换。
     */
    char c[100];
    cin.getline(c, 100);
    string s = c;
    cout << s;
}

int pat_solver() {

    int N;
    scanf("%d", &N); //或者可以用 "%d\n"
    string sentence[100];
    for (int i = 0; i < N; ++i) {
        char _buffer[512];
        cin.getline(_buffer, 512);
        string _b = string(_buffer);
        reverse(_b.begin(), _b.end());
        sentence[i] = _b;
    }
    int ans = 0;
    for (int j = 0; j < 512; ++j) {
        char s = sentence[0][j];
        bool same_s_flag = true;
        for (int i = 0; i < N; ++i) {
            if (s != sentence[i][j]) {
                same_s_flag = false;
                break;
            }
        }
        if (same_s_flag)
            ans++;
        else break;
    }
    if (ans == 0) {
        printf("nai");
    } else {
        for (int i = ans-1; i >= 0; --i) {
            printf("%c", sentence[0][i]);
        }
    }
    return 0;
}