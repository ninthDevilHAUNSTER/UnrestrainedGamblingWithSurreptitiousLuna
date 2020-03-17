//
// Created by shaob on 2020/3/17.
//

class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmpPath;
    // unordered_set<int> vis;

    void DFS(vector<int> &nums,int start){
        if(tmpPath.size()>=2){
            res.push_back(tmpPath);
        }
        bool vis[256];
        fill(vis,vis+256,false);
        for(int i = start;i<nums.size();i++){
            if(vis[nums[i]+100]) continue;
            if(tmpPath.empty()){
                tmpPath.push_back(nums[i]);
                DFS(nums,i+1);
                vis[nums[i]+100] =true;
                tmpPath.pop_back();
            }else{
                if(nums[i] >= tmpPath.back()){
                    tmpPath.push_back(nums[i]);
                    DFS(nums,i+1);
                    vis[nums[i]+100] =true;
                    tmpPath.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        DFS(nums,0);
        return res;
        // dp.resize(nums.size());
        // dp[0] = nums[0]; // dp 中存放包含
        // for(int i=1;i<nums.size();i++){
        //     if(dp[i-1] > )
    }
};