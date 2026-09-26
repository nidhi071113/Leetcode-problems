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
    ListNode* deleteMiddle(ListNode* head) {
        // int n=0;
        // ListNode* temp=head;
        // while(temp){
        //     n++;
        //     temp=temp->next;
        // }
        // if(n==1)return nullptr;
        // int pos=n/2;
        // temp=head;
        // for(int i=0;i<pos-1;i++){
        //     temp=temp->next;
        // }
        // ListNode* del=temp->next;
        // temp->next=del->next;
        // delete del;
        // return head;

        if(head==nullptr || head->next==nullptr) return nullptr;

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;

        while(fast!=nullptr&&fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        delete slow;

        return head;
    }
};