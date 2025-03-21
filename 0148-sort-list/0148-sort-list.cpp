class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head; // Base case: return if list is empty or has one node
        }

        // Split the list into two halves
        ListNode* temp = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = nullptr; // Disconnect the first half

        // Recursively sort both halves
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        // Merge the sorted halves
        return mergeList(l1, l2);
    }

    ListNode* mergeList(ListNode* head1, ListNode* head2) {
        ListNode* finalHead = nullptr;
        ListNode* ft = nullptr;

        // Initialize the merged list
        if (head1 && head2) {
            if (head1->val > head2->val) {
                finalHead = head2;
                ft = head2;
                head2 = head2->next;
            } else {
                finalHead = head1;
                ft = head1;
                head1 = head1->next;
            }
        }

        // Merge the two lists
        while (head1 && head2) {
            if (head1->val < head2->val) {
                ft->next = head1;
                ft = ft->next;
                head1 = head1->next;
            } else {
                ft->next = head2;
                ft = ft->next;
                head2 = head2->next;
            }
        }

        // Attach the remaining nodes
        if (head1) {
            ft->next = head1;
        }
        if (head2) {
            ft->next = head2;
        }

        return finalHead;
    }
};

