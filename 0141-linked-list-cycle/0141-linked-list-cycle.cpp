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
    bool hasCycle(ListNode *head) {
        
        if(!head || !head->next){
            return 0;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(true){
            slow = slow->next;
            fast = fast->next;

            if(fast->next == NULL) return false;
            fast = fast->next;

            if(slow == fast){
                return true;
            }

            if(!fast->next || !fast->next->next){
                return false;
            }
        }

        return 1;
    }
};