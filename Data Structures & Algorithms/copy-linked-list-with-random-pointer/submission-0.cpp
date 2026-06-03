/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash;

        Node* temp = head;
        Node dummy(0);
        Node* last = &dummy;
        while(temp){
            hash[temp] = new Node(temp->val);
            last->next = hash[temp];
            last = hash[temp];
            temp = temp->next;
        }
        temp = head;
        while(temp){
            hash[temp]->random = hash[temp->random];
            temp = temp->next;
        }
        return head ? hash[head] : NULL;
    }
};
