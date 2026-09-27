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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* lessHead = less;

        ListNode* greater = new ListNode(0);
        ListNode* greaterHead = greater;

        ListNode* curr = head;

        while(curr != nullptr){
            if(curr->val < x){
                less->next = curr;
                less = less->next;
            }
            else{
                greater->next = curr;
                greater = greater->next;
            }
            curr = curr->next;
        }
        greater->next = nullptr;
        less->next = greaterHead->next;
        
        return lessHead->next;
    }
};