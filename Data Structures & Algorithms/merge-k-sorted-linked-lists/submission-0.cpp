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

class cmp{
    public:
    bool operator ()(ListNode*a,ListNode*b){
            return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;

        for (auto h : lists){
            if (h)pq.push(h);
        }   
        ListNode * head= new ListNode(-1);
        ListNode *temp=head;

        while (!pq.empty()){

            ListNode*top=pq.top();
            pq.pop();
            if (top->next)pq.push(top->next);

            temp->next=top;
            temp=temp->next;
        }
        return head->next;
    }
};
