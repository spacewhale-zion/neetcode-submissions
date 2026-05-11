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
    void reorderList(ListNode* head) {
        
        ListNode * slow=head;
        ListNode * fast=head;
        while (fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode * second=slow->next;
        slow->next=nullptr;

        ListNode*prev=nullptr;
        while (second){
            ListNode *nxt=second->next;

            second->next=prev;
            prev=second;
            second=nxt;
        }

        second=prev;
        ListNode*first=head;

        while(second){
            ListNode*t1=first->next;
            ListNode*t2=second->next;

            first->next=second;
            second->next=t1;

            first=t1;
            second=t2;

        }

    }
};
