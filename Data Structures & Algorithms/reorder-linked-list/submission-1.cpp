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
        ListNode* slow = head;
        if (!slow) return;
        if (!slow->next || !slow->next->next) return;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head_1 = head;
        ListNode* head_2 = slow->next;
        slow->next = NULL;

        ListNode* temp = head_2;
        ListNode* last = NULL;
        while (temp) {
            ListNode* next = temp->next;
            temp->next = last;
            last = temp;
            temp = next;
        }
        ListNode* temp_2 = last;
        ListNode* temp_1 = head_1;

        while (temp_2) {
            ListNode* next_1 = temp_1->next;
            ListNode* next_2 = temp_2->next;
            temp_1->next = temp_2;
            temp_2->next = next_1;
            temp_1 = next_1;
            temp_2 = next_2;
        }
    }
};