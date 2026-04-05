class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> m;
    int cap;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add(Node* node) {
        Node* temp = head->next;

        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    int get(int key) {
        if (m.find(key) == m.end()) return -1;

        Node* node = m[key];
        deleteNode(node);
        add(node);

        return node->val;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            deleteNode(node);
            m.erase(key);
        }

        if (m.size() == cap) {
            Node* lru = tail->prev;
            m.erase(lru->key);
            deleteNode(lru);
        }

        Node* newNode = new Node(key, value);
        add(newNode);
        m[key] = newNode;
    }
};