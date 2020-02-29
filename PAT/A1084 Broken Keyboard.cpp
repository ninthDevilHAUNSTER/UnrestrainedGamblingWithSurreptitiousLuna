//
// Created by shaob on 2020/2/26.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;
bool hash_table[128];

int pat_solver() {
    fill(hash_table, hash_table + 128, false);
    char s1[81];
    char s2[81];
    cin.getline(s1, 81);
    cin.getline(s2, 81);
    string str1 = s1;
    string str2 = s2;
    for (char &i : str2) {
        i = toupper(i);
    }
    for (char &i : str1) {
        i = toupper(i);
    }
    int i = 0, j = 0;
    for (j = 0; j < str1.size(); ++j) {
        for (i = 0; i < str2.size(); ++i) {
            if (str1[j] == str2[i]) break;
        }
        if (i == str2.size() && !hash_table[str1[j]]) {
            hash_table[str1[j]] = true;
            printf("%c", str1[j]);
        }// 没有出现过
    }
}