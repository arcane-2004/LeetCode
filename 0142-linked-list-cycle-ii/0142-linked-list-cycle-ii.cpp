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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL && fast->next->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                while(slow != head){
                    head = head->next;
                    slow = slow->next;
                }

                return head;
            }

        }

        return {};
    }
};