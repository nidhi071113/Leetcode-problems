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

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            ListNode* minNode = pq.top();
            pq.pop();

            temp->next = minNode;
            temp = temp->next;

            if (minNode->next != nullptr) {
                pq.push(minNode->next);
            }
        }

        return dummy->next;
    }
};