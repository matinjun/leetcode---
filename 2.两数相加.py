#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        i = l1
        j = l2
        l = ListNode
        it = l
        add = 0
        while i != None and j != None:
            node = ListNode()
            node.va = (add + i.val + j.val) % 10
            it.next = node
            it = it.next
            add = int((add + i.val + j.val) / 10)
            i = i.next
            j = j.next
        while i != None:
            l.append((add + i.val) % 10)
            add = int((add + l1[i]) / 10)
            i += 1
        while i < len(l2):
            l.append((add + l2[i]) % 10)
            add = int((add + l2[i]) / 10)
            i += 1
        return l

        
# @lc code=end

