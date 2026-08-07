/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* start;
        ListNode* curr;
        ListNode* top = list1;
        ListNode* bottom = list2;
        if (top && bottom) {
            if (list1->val <= list2->val) {
                start = list1;
                curr = start;
                top = top->next;
            } else {
                start = list2;
                curr = start;
                bottom = bottom->next;
            }
        } else {
            if (top) {
                return list1;
            } 
            if (bottom) {
                return list2;
            }
        }
        while (top && bottom) {
            if (top->val <= bottom->val) {
                curr->next = top;
                curr = top;
                top = top->next;
            } else {
                curr->next = bottom;
                curr = bottom;
                bottom = bottom->next;
            }
        }
        if (top) {
            curr->next = top;
        } 
        if (bottom) {
            curr->next = bottom;
        }

        return start;
    }
};
