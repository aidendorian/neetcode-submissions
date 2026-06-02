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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp_ = head;
        while(temp_){
            size++;
            temp_ = temp_->next;
        }
        if(size==1) return NULL;
        if(size == n) return head->next;
        int pos = size-n-1;
        ListNode* temp = head;
        while(pos--){
            temp = temp->next;
        }
        ListNode* node = temp->next;
        temp->next = temp->next->next;
        delete node;
        return head;
    }
};
