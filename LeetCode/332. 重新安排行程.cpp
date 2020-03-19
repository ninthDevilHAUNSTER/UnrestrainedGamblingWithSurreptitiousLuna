//
// Created by shaob on 2020/3/17.
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

#include "LCMainHeader.h"
/*
测试样例



*/
class Solution {
private:
    unordered_map<string,int> name2id;
    unordered_map<int,string> id2name;

    int net[18000][18000];
    bool vis[18000];
    bool dest[18000];
    int d[18000];
    int _index = 0;
    int ch_name2id(string &s){
        if(name2id.find(s)==name2id.end()){
            name2id[s] = _index;
            id2name[_index] = s;
            _index++;
        }
        return name2id[s];
    }

    int pre[18000];

    void dj(int start){
        fill(vis,vis+_index,false);
        fill(d,d+_index,0x3fffffff);
        for(int i=0;i<_index;i++){
            pre[i] = i;
        }
        d[start] = 0;
        for(int i=0;i<_index;i++){
            int MIN = 0x3fffffff,u = -1;
            for(int j=0;j<_index;j++){
                if(!vis[j] && d[j] < MIN){
                    MIN = d[j];
                    u = j;
                }
            }
            if(u==-1) return ;
            vis[u] = true;
            for(int j=0;j<_index;j++){
                if(!vis[j] && net[u][j] != 0x3fffffff){
                    if(net[u][j] + d[u] < d[j] ){
                        d[j] = d[u] + net[u][j];
                        pre[j]=u;
                    }else if(net[u][j]+d[u] == d[j]){
                        if(pre[j]==j || id2name[u] > id2name[pre[j]])
                            pre[j] =u;
                    }
                }
            }
        }
    }
    vector<string> res;
    void DFS(int des){

    }

public:
    vector<string> findItinerary() {
        fill(net[0],net[0]+18000*18000,0x3fffffff);
        fill(dest,dest+18000,true);
        vector<vector<string>> tickets =  {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
        for(int i=0;i<tickets.size();i++){
            int id1 = ch_name2id(tickets[i][0]);
            int id2 = ch_name2id(tickets[i][1]);
            net[id1][id2] = 1;
            dest[id1] = false;
        }
        dj(name2id["JFK"]);
        int _d = 0;
        while(!dest[_d]) _d++;
        cout << id2name[_d];
        DFS(_d);
        return res;
    }
};

