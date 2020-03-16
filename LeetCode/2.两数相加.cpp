//
// Created by shaob on 2020/3/16.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * l3=new ListNode(-1),*l3_tail = l3;
        int jinWei = 0,value = 0;
        while(l1!=nullptr || l2!=nullptr){
            int val1 = l1==nullptr? 0:l1->val;
            int val2 = l2==nullptr? 0:l2->val;
            value = val1+val2+jinWei;
            if(value >= 10){
                jinWei = 1;
                value -=10;
            }else{
                jinWei = 0;
            }
            ListNode * p = new ListNode(value);
            l3_tail->next = p;
            l3_tail = p;
            l1 = l1==nullptr? nullptr:l1->next;
            l2 = l2==nullptr? nullptr:l2->next;
        }
        if(jinWei == 1){
            ListNode * p = new ListNode(1);
            l3_tail->next = p;
        }
        return l3->next;
    }
};