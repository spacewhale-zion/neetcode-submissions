class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int tot = 0;

        ListNode* temp = head;

        while (temp) {
            temp = temp->next;
            tot++;
        }

        int req = tot - n;

        // remove head
        if (req == 0) {
            return head->next;
        }

        temp = head;

        ListNode* prev = nullptr;

        while (req > 0) {
            prev = temp;
            temp = temp->next;
            req--;
        }

        prev->next = temp->next;

        return head;
    }
};