//
// Created by shaob on 2020/3/21.
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

struct Student {
    string name;
    int rank;
    int score;

    bool operator==(const Student &B) const {
        // 需要重载 ==
        return name == B.name;
    }

    friend ostream &operator<<(ostream &output, const Student &B) {
        output << B.name <<"\t" <<  B.rank<< "\t" << B.score;
        return output;
    }
};

struct HashTable {
    // 以及重载hash值的运算方法
//    std::size_t operator()(const Student &B) const { // 标准的重载应该是size_t
    unsigned long operator()(const Student &B) const { // 实际上size_t在源码中就是 u L 方便的话可以写成long
        string tmp = to_string(B.rank) + B.name; // 我的理解的话，这个就是个哈希函数，让它隔开来的那种
        return hash<string>()(tmp);
    }
};


unordered_map<Student, int, HashTable> Table;


int csp_solver() {
    Student A = {"ao", 1, 1093};
    Student B = {"shaobao", 2, 100};
    Student C = {"shaobao", 3, 100};
    Student D = {"shaobao", 4, 100};
    Student E = {"ao", 1, 1099}; // 冲突的情况
    Table[A] = 1;
    Table[B] = 2;
    Table[E] = 3;
    for (const auto &i: Table) {
        cout << i.first << "\t" << i.second << endl;
        // 可以看到这样只有两项，因为A和E的哈希值是一样的,当E插入的时候，原本的第一项不会发生更新
    }
    return 0;
}

/*
测试样例



*/