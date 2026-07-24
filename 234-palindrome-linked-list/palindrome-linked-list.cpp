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
     ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find the middle using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: If odd length, skip the middle node
        if (fast) slow = slow->next;

        // Step 3: Reverse the second half
        ListNode* secondHalf = reverse(slow);

        // Step 4: Compare first and second half
        ListNode* firstHalf = head;
        ListNode* second = secondHalf;
        while (second) {
            if (firstHalf->val != second->val)
                return false;
            firstHalf = firstHalf->next;
            second = second->next;
        }

        // Optional Step 5: Restore second half (if needed)
        // reverse(secondHalf);

        return true;
    }
};