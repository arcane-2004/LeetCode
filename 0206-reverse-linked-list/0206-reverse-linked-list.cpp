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
        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        ListNode* curr = temp->next;
        ListNode* nextNode = curr->next;

        head->next = NULL;
        while(true){

            curr->next = temp;

            if(nextNode == NULL) break;

            temp = curr;
            curr = nextNode;
            nextNode = nextNode->next;
        }

        return curr;
    }
};