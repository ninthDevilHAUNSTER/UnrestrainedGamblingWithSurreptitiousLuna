//
// Created by shaob on 2020/3/17.
//

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    long long sum = 0;
    void calculate(NestedInteger & nL,int depth){
        if(nL.isInteger()){
            sum+=depth*nL.getInteger();
        }else{
            for(auto i:nL.getList()){
                calculate(i,depth+1);
            };
        }
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        for(auto i:nestedList){
            calculate(i,1);
        }
        return sum;
    }
};