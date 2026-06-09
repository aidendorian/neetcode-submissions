class LRUCache {
public:
    typedef struct Node{
        int val;
        int key;
        Node* next;
        Node* prev;
        Node(int k, int v): val(v), key(k), next(nullptr), prev(nullptr){}
    }Node;

    unordered_map <int, Node*> hash;
    int curr;
    int cap;

    Node* toHead;
    Node* toTail;

    void remove(Node* temp){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    void add(Node* temp){
        temp->prev = toTail->prev;
        temp->next = toTail;
        temp->prev->next = temp;
        toTail->prev = temp;
    }

    LRUCache(int capacity) {
        curr = 0;
        cap = capacity;
        toHead = new Node(0, 0);
        toTail = new Node(0, 0);
        toHead->next = toTail;
        toTail->prev = toHead;
    }
    
    int get(int key) {
        if(hash.contains(key)){
            Node* temp = hash[key];
            remove(temp);
            add(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash.contains(key)){
            Node* temp = hash[key];
            temp->val = value;
            remove(temp);
            add(temp);
            return;
        }
        Node* temp = new Node(key, value);
        hash[key] = temp;
        curr++;
        add(temp);
        if(curr>cap){
            Node* node = toHead->next;
            remove(node);
            hash.erase(node->key);
            curr--;
            delete node;
        }
    }
};
