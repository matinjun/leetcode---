/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carray = 0;
        int ans = 0;
        // 此处使用哑节点减少判断
        ListNode * l = new ListNode();
        auto i = l;
        auto i1 = l1, i2 = l2;
        for(; 
            i1 != nullptr && i2 != nullptr; 
            i1 = i1->next, i2 = i2->next) {
            ans = i1->val + i2->val;
            ans += carray;
            
            i->next = new ListNode(ans % 10);
            i = i->next;
            carray = ans / 10;
        }

        for(;i1 != nullptr; i1 = i1->next) {
            ans = i1->val;
            ans += carray;
            
            i->next = new ListNode(ans % 10);
            i = i->next;
            carray = ans / 10;
        }
        for(;i2 != nullptr; i2 = i2->next) {
            ans = i2->val;
            ans += carray;
            
            i->next = new ListNode(ans % 10);
            i = i->next;
            carray = ans / 10;
        }
        if(carray) {
            i->next = new ListNode(carray);
            i = i->next;
        }
        i = l;
        l = l->next;
        delete i;
        return l;
    }
};
// @lc code=end

