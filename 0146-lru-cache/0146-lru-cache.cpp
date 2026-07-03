class LRUCache {
public:
    struct Node{
        int key,val;
        Node* prev;
        Node* next;

        Node(int k,int v){
            key=k;
            val=v;
            prev=NULL;
            next=NULL;
        }
    };
    unordered_map<int,Node*> mp;
    int size;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        size=capacity;

        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;
    }

    void deleteNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;

        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    void insertafterhead(Node* node){
        Node* temp=head->next;

        head->next=node;
        node->prev=head;

        node->next=temp;
        temp->prev=node;
    }
    int get(int key) {

        if(mp.count(key)==0) return -1;

        Node* node=mp[key];
        deleteNode(node);
        insertafterhead(node);

        return node->val;
    }

    void put(int key,int value){

        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            node->val=value;

            deleteNode(node);
            insertafterhead(node);
        }
        else{

            if(mp.size()==size){
                Node* node=tail->prev;
                mp.erase(node->key);
                deleteNode(node);
            }

            Node* node=new Node(key,value);
            mp[key]=node;
            insertafterhead(node);
        }
    }
};