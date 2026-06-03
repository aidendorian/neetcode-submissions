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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* tail = NULL;
        int carry = 0;
        while(temp1 && temp2){
            int sum =  temp1->val+temp2->val + carry;
            carry = sum/10;
            temp1->val = sum%10;
            tail = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(!temp1 && !temp2){
            if(carry){
                ListNode* temp = new ListNode(1);
                tail->next = temp;
            }
            return l1;
        }
        else{
            if(temp1==NULL && temp2!=NULL){
                tail->next = temp2;
                temp1 = tail->next;
            }
            while(temp1){
                    int sum = temp1->val + carry;
                    carry = sum/10;
                    temp1->val = sum%10;
                    tail = temp1;
                    temp1 = temp1->next;
            }
        }
        if(carry){
            ListNode* temp = new ListNode(1);
            tail->next = temp;
        }
        return l1;
    }
};