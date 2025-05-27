class LRUCache
{
    struct ListNode
    {
        int val;
        int key;
        ListNode* prev;
        ListNode* next;
        ListNode() : val(0), key(0), prev(nullptr), next(nullptr) {}
        ListNode(int _key) : val(0), key(_key), prev(nullptr), next(nullptr) {}
        ListNode(int _key, ListNode* _prev) : val(0), key(_key), prev(_prev), next(nullptr) {}
        ListNode(int _key, int _val, ListNode* _prev, ListNode* _next) : val(_val), key(_key), prev(_prev), next(_next) {}
    };

    unordered_map<int, ListNode*> um;
    ListNode* head;
    ListNode* tail;
    int max_capacity = 0;

public:
    LRUCache(int capacity)
    {
        max_capacity = capacity;
        head = new ListNode(-2);
        ListNode* current = head;

        for (int i = 0; i < capacity; i++)
        {
            ListNode* new_node = new ListNode(-1, current);
            current->next = new_node;
            current = new_node;
        }

        tail = new ListNode(-2, current);
        current->next = tail;
    }

    int get(int key)
    {
        if (um.contains(key))
        {
            // delete
            um[key]->prev->next = um[key]->next;
            um[key]->next->prev = um[key]->prev;

            // insert
            um[key]->prev = head;
            um[key]->next = head->next;
            head->next = um[key];
            um[key]->next->prev = um[key];

            return um[key]->val;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (um.contains(key))
        {
            um[key]->val = value;

            // delete
            um[key]->prev->next = um[key]->next;
            um[key]->next->prev = um[key]->prev;

            // insert
            um[key]->prev = head;
            um[key]->next = head->next;
            head->next = um[key];
            um[key]->next->prev = um[key];
        }
        else
        {
            ListNode* del_node = tail->prev;
            int del_key = del_node->key;
            if (del_key != -1)
            {
                um.erase(del_key);
            }
            
            del_node->prev->next = tail;
            tail->prev = del_node->prev;

            delete del_node;

            ListNode* new_node = new ListNode(key, value, head, head->next);
            um[key] = new_node;
            head->next = new_node;
            new_node->next->prev = new_node;
        }
    }

    ~LRUCache()
    {
        ListNode* current = head;
        
        while (current)
        {
            ListNode* tmp = current->next;
            delete current;
            current = tmp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */