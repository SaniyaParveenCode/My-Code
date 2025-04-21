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
private:
    ListNode* front;

    bool check(ListNode* current) {
        if (current == nullptr) return true;

        if (!check(current->next)) return false;

        if (front->val != current->val) return false;

        front = front->next;
        return true;
    }

public: 
    bool isPalindrome(ListNode* head) {
        front = head;
        return check(head);
    }
};
