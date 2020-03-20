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

int N;

int coef(string &s, int &begin) {
    int cnt = 0;
    while (s[begin] <= '9' && s[begin] >= '1') {
        cnt *= 10;
        cnt += s[begin] - '0';
        begin++;
    }
    return cnt == 0 ? 1 : cnt;
}

string formula(unordered_map<string, int> &memo, string &s) {
    int begin = 0;
    int base = coef(s, begin);
    int back_base = 0;
    cout << s << endl;
    while (begin < s.size()) {

        if (isalpha(s[begin])) {
            string element = to_string(s[begin]);
            if (islower(begin + 1)) {
                element += to_string(s[++begin]);
            }
            begin++;
            back_base = coef(s, begin);
            memo[element] = back_base * base;
        }
        if (s[begin] == '(') {
            // 找后面的括号儿
            int cntLeft = 1;
            int i = ++begin;
            for (; i < s.size(); i++) {
                if (s[i] == '(') ++cntLeft;
                else if (s[i] == ')') --cntLeft;
                if (cntLeft == 0) break;
            }
            string sub = s.substr(begin, i - begin);
            formula(memo, sub);
        }
        //    if (s[begin] == '(') {
        //        string sub = s.substr(begin + 1, s.find_last_of(')'));
        //        formula(sub);
        //    }
    }
    return s;
}

int expr(unordered_map<string, int> &memo, string &s, int &begin, int &end) {
    // 按照加号切开来
    string tmp_s = s + "+";
    int findStartIndex = 0;
    int findEndIndex = s.find_last_of('+');
    int subIndex = 0;
    while ((subIndex = tmp_s.find('+', findStartIndex)) != string::npos) {
        string sub = tmp_s.substr(findStartIndex, subIndex - findStartIndex); // 加号不要
        formula(memo, sub);
        findStartIndex = subIndex + 1;
    }
}

int ccf_solver() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        string input;
        cin >> input;
        int idx = input.find('=');
        string expr1 = input.substr(0, idx);
        unordered_map<string, int> Left, Right; // 等式两边的元素
        string expr2 = input.substr(idx + 1, input.size() - idx - 1);
        int b1 = 0, e1 = expr2.size() - 1, b2 = 0, e2 = expr2.size() - 1;
        expr(Left, expr1, b1, e1);
        expr(Right, expr2, b2, e2);
        cout<<"Left"<<endl;
        for(unordered_map<string,int>::iterator itL = Left.begin(),itR;itL!=Left.end(); ++itL){
            cout<<itL->first<<"->"<<itL->second;
        }
        cout<<"Right"<<endl;
        for(unordered_map<string,int>::iterator itR = Right.begin();itR!=Right.end(); ++itR){
            cout<<itR->first<<"->"<<itR->second;
        }

    }
    return 0;
}

/*
测试样例



*/