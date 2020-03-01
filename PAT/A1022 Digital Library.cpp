//
// Created by shaob on 2020/3/1.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

map<string, set<int>> index[6];


vector<string> split(const string &s, vector<string> &res, char delim) {
    // string的split方法，stackoverflow上看到的，值得记忆。
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        res.push_back(item);
    }
    return res;
}

int pat_solver() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int digit_id;
        scanf("%d\n", &digit_id);
        char buffer[100];
        // book title
        cin.getline(buffer, 100);
        index[1][buffer].insert(digit_id);
        // book author
        cin.getline(buffer, 100);
        index[2][buffer].insert(digit_id);
        // key words
        cin.getline(buffer, 100);
        vector<string> result;
        split(buffer, result, ' ');
        for (const auto &j : result) {
            index[3][j].insert(digit_id);
        }
        // publisher
        cin.getline(buffer, 100);
        index[4][buffer].insert(digit_id);
        // year
        cin.getline(buffer, 100);
        index[5][buffer].insert(digit_id);
    }
    int M;
    scanf("%d", &M);
    char key[100];
    int index_id;
    for (int k = 0; k < M; ++k) {
        scanf("%d: ", &index_id);
        cin.getline(key, 100);
        printf("%d: %s\n", index_id, key);
        if (index[index_id][key].empty()) {
            printf("Not Found\n");
        } else {
            for (const auto &a:index[index_id][key]) {
                printf("%07d\n", a); // 这里很关键，注意格式
            }
        }
    }
    M = 1;

    return 0;
}