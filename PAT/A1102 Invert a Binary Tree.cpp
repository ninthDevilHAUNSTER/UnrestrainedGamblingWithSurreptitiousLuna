//
// Created by shaob on 2020/3/4.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <queue>

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
#define MaxSize 0x3fffffff
struct static_bTree {
    int left = -1;
    int right = -1;
    int data = -1;
    bool is_root = true;
    bool visit = false;
} BTree[10];

struct node {
    node *left = nullptr;
    node *right = nullptr;
    int data = -1;
};

int N;
//
//node *build_tree(int root_id) {
//    if(BTree)
//    node *p = new node;
//    p->data = root_id; // 简化一下哈。
//    p->right = BTree[root_id].right != -1 ? build_tree(BTree[root_id].right) : nullptr;
//    p->left = BTree[root_id].left != -1 ? build_tree(BTree[root_id].left) : nullptr;
//    return p;
//}

void postOrder(int root) {
    if (root == -1) return;
    postOrder(BTree[root].left);
    postOrder(BTree[root].right);
    swap(BTree[root].left, BTree[root].right); // 交换左右孩子完成镜像。
}

int pre_num = 0;

void inOrder(int root) {
    if (root == -1) return;
    inOrder(BTree[root].left);

    printf("%d", root);
    pre_num++;
    (pre_num <= N - 1) ? printf(" ") : printf("\n");

    inOrder(BTree[root].right);
}

int layer_num = 0;

void layerOrder(int root) {
    queue<int> Q;
    Q.push(root);
    while (!Q.empty()) {
        int q = Q.front();
        printf("%d", q);
        layer_num++;
        (layer_num <= N - 1) ? printf(" ") : printf("\n");
        Q.pop();
        if (BTree[q].left != -1)Q.push(BTree[q].left);
        if (BTree[q].right != -1)Q.push(BTree[q].right);
    }
}


int pat_solver() {
    scanf("%d", &N);
    string buffer1, buffer2;
    for (int i = 0; i < N; ++i) {
        cin >> buffer1 >> buffer2;
        BTree[i].data = i;
        BTree[i].left = (buffer1 == "-") ? -1 : stoi(buffer1);
        BTree[i].right = (buffer2 == "-") ? -1 : stoi(buffer2);
        (BTree[i].left != -1) ? BTree[BTree[i].left].is_root = false : 0;
        (BTree[i].right != -1) ? BTree[BTree[i].right].is_root = false : 0;
    }
    int root_id = 0;
    while (!BTree[root_id].is_root) root_id++;
//    cout << "node id\t" << root_id;
    postOrder(root_id);
    layerOrder(root_id);
    inOrder(root_id);
    return 0;
}

/*

 镜像二叉树 以前在牛客网上做过类似的题目。这里给的是静态二叉树。我的思路是转化成动态。没有写过，尝试一下吧。【答，写不出】
 根节点就是所有节点的左右孩子中，都没有出现过的点。
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6

 */