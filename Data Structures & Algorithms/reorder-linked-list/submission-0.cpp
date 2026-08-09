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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        if (!slow || !slow->next) {
            return;
        }

        ListNode* fast = head->next;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
            if (!fast->next) {
                break;
            }
            fast = fast->next;
        }

        ListNode* prev = slow;
        ListNode* reverse = slow->next;
        while (reverse) {
            ListNode* next = reverse->next;
            reverse->next = prev;
            prev = reverse;
            reverse = next;
        }

        ListNode* left = head;
        ListNode* right = fast;
        while (left != right) {
            ListNode* leftNext = left->next;
            ListNode* rightNext = right->next;
            left->next = right;
            left = leftNext;
            if (left == right) {
                break;
            }
            right->next = left;
            right = rightNext;
        }
        left->next = nullptr;
    }
};
