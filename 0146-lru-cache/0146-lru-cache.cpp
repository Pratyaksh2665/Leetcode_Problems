
class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    map<int, Node*> mp;
    int size;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        size = capacity;
        mp.clear();

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

    int get(int key) {
        if (mp.count(key) == 0)
            return -1;

        Node* node = mp[key];

        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->val = value;

            deleteNode(node);
            insertAfterHead(node);
            return;
        }

        if (mp.size() == size) {
            Node* node = tail->prev;

            deleteNode(node);
            mp.erase(node->key);
            delete node;
        }

        Node* newnode = new Node(key, value);
        mp[key] = newnode;
        insertAfterHead(newnode);
    }
};
