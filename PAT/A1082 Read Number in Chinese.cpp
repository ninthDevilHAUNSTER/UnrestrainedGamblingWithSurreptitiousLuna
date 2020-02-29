//
// Created by shaob on 2020/2/25.
//


#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba",
                  "jiu"};
unordered_map<int, string> wei;

void __init__() {
    wei[11] = "Wan";
    wei[12] = "Yi";
    wei[2] = "Shi";
    wei[1] = "Bai";
    wei[0] = "Qian";
}

int input[9] = {0};

void num2array(long a) {
    queue<long> tmp;
    do {
        tmp.push(a % 10);
        a /= 10;
    } while (a != 0);
    int index = 8;
    while (!tmp.empty()) {
        int s = tmp.front();
        tmp.pop();
        input[index] = s;
        index--;
    }
}

bool FIRST_OUTPUT_FLAG = true;

void cout_and_ch_flag(const string &_s) {
    if (FIRST_OUTPUT_FLAG) {
        cout << _s;
        FIRST_OUTPUT_FLAG = false;
    } else {
        cout << " " << _s;
    }
}

void yi_sector() {
    /*
     * 0,1
     */
    if (input[0] == 0) {
        return;
    } else {
        if (FIRST_OUTPUT_FLAG) {
            cout << num[input[0]] << " Yi";
            FIRST_OUTPUT_FLAG = false;
        } else {
            cout << " " << num[input[0]] << " Yi";
        }
    }
}

void wan_sector() {
    /*
     * 1 2 3 4
     */
    int left = -1, right = -1;
    int BIAS = 1; // 将 1 2 3 4 对应到 0 1 2 3
    for (int i = 1; i <= 4; ++i) {
        if (input[i] != 0) {
            left = i;
            break;
        }
    }
    for (int i = 4; i >= 1; --i) {
        if (input[i] != 0) {
            right = i;
            break;
        }
    }
    if (right == -1 && left == -1) {
        return;
    } else {
        // 左右指针重合，代表该部分只有一个数字
        if (right - BIAS == 0) {
            // 对应千位
            cout_and_ch_flag(num[input[right]]);
            cout_and_ch_flag(wei[11]); // 输出万
        } else {
            // 不是千位 加零
            cout_and_ch_flag(num[0]);
            cout_and_ch_flag(num[input[right]]);
        }
    }
    cout_and_ch_flag(wei[11]); // 输出万
}

void ge_sector() {

}

int pat_solver() {
    __init__();
    long a = 0;
    scanf("%ld", &a);
    if (a < 0) {
        printf("Fu");
        a = abs(a);
        FIRST_OUTPUT_FLAG = false;
    }
    num2array(a);
//    for (int i : input) {
//        cout << i;
//    }
    yi_sector();
    wan_sector();
    ge_sector();


    return 0;
}

/*
int pat_solver() {
    long a = 0;
    scanf("%ld", &a);
    if (a < 0) {
        a = abs(a);
        result_stack.push("Fu");
    }
    long sub = 0;
    int sub_push_c = 0;
    int a_push_c = 0;
    int tmp = 0;
    do {
        sub = a % 10000;
        do {

            tmp = sub % 10;
            if (tmp==0)
            result_stack.push("");
            sub = sub / 10;
        } while (sub != 0);
        a = a / 10000;
    } while (a != 0);
    return 0;
}

 用栈做太恶心了，要考虑很多很多的问题。重新来。
 */