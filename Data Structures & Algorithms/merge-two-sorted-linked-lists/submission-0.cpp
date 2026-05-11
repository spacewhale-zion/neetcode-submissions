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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode*temp=new ListNode(0);
        ListNode*head3=temp;
        ListNode *head1=list1;
        ListNode *head2=list2;

        while (head1!=nullptr && head2!=nullptr){

            if (head1->val < head2->val){
                temp->next = new ListNode(head1->val); 
                temp=temp->next;
                head1=head1->next;
            }
            else if (head1->val >= head2->val){
                temp->next = new ListNode(head2->val); 
                temp=temp->next;
                head2=head2->next;
            }
        }
        while (head1!=nullptr){
                temp->next = new ListNode(head1->val); 
                temp=temp->next;
                head1=head1->next;
        }
        while (head2!=nullptr){
                temp->next = new ListNode(head2->val); 
                temp=temp->next;
                head2=head2->next;
        }
        return head3->next;


    }
};
