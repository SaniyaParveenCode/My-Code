/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
//  */

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2 , int carry = 0) {
        if(!l1 && !l2 && carry ==0) return NULL;

        int sum = carry;
        if(l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2) {
            sum+= l2->val;
            l2 = l2->next;
        }
        ListNode *dummy = new ListNode(sum%10);
        dummy->next = addTwoNumbers(l1, l2, sum/10);
        return dummy;
    }
};