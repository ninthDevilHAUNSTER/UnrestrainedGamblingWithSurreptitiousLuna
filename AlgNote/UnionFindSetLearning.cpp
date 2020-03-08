//
// Created by shaob on 2020/3/8.
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

using namespace std;
#define MaxSize 0x3fff

class UnionFindSet {
public:
    int father[MaxSize]{}; //  并查集的基础数据结构就是一个数组，father[i] 代表元素i的父节点
    // 特别的  father[i] = i 代表的是根节点
    UnionFindSet() {
        for (int i = 0; i < MaxSize; ++i) {
            this->father[i] = i;
        }
    }

    /*
     * 这下面两个函数都没有路径压缩的概念复杂度是非常高的。
     */
    int _findFatherNonRecursion_O_n(int x) {
        while (x != this->father[x]) { // 不是根节点，则继续循环
            x = father[x]; // 获取自己的父节点
        }
        return x;
    }

    int _findFatherRecursion_O_n(int x) {
        /*
         * 递归写法
         */
        if (father[x] == x) return x;
        else return _findFatherRecursion_O_n(father[x]);
    }

    int findFatherNoneRecursion_O_1(int x) {
        int a = x; // 暂时保存一下x的值
        while (x != this->father[x]) {
            x = father[x];
        }
        // 此时循环退出时，x已经是根节点了
        while (a != father[a]) { // 当 a 不是根节点的时候
            int z = a;
            a = father[a]; // 查找a的上一层节点
            father[z] = x; // 并把a的父节点改为根节点
        }
        return x; // 返回根节点
    }

    int findFatherRecursion_O_1(int x) {
        if (x == father[x]) return x;
        else {
            int f = findFatherRecursion_O_1(father[x]); // 查找x的上一层节点（这是一个递归的过程，不断返回来的就是根节点）
            father[x] = f; // 将x的父节点改为上一层节点|实际上就是改为根节点
            return f;
        }
    }

    int findFather(int x) {
        return findFatherRecursion_O_1(x);
    }

    int Union(int x, int y) {
        /*
         * （一般给两个元素，让两个元素找到根节点后判断）两个集合合并成一个集合，判断两个元素是否属于同一集合，
         *
         * 若属于两个集合，则可以将其中一个父节点指向另一个节点。
         *
         */
        int r1 = this->findFather(x);
        int r2 = this->findFather(y);
        if (r1 == r2) return -1;
        else {
            father[r1] = r2;
            return r2;
        }
    }


};

int alg_solver() {

    return 0;
}

/*
测试样例



*/