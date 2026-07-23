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
    ListNode* reverseList(ListNode* head) {
          ListNode* prev = nullptr;   // initially no previous node
        ListNode* curr = head;      // start from head

        while (curr != nullptr) {
            ListNode* next = curr->next; // save next
            curr->next = prev;           // reverse pointer
            prev = curr;                 // move prev forward
            curr = next;                 // move curr forward
        }

        return prev;
        
    }
};