//
// Created by shaob on 2020/2/25.
//


#include <iostream>
#include <cctype>
#include <string>
#include <utility>

using namespace std;

char num[10][10] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

void dfs(int sum) {
    if (sum / 10 == 0) {
        printf("%s", num[sum % 10]);
        return;
    }
    dfs(sum / 10);
    printf(" %s", num[sum % 10]);
}


int pat_solver() {
    string input;
    cin >> input;
    int sum = 0;
    for (char i : input) {
        sum += i - '0';
    }
    dfs(sum);
    return 0;
}