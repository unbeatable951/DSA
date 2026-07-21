class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int value) : val(value), next(nullptr) {}
    };

    Node* head;

public:
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        if (index < 0) return -1;
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            if (temp == nullptr) return -1;
            temp = temp->next;
        }
        return (temp != nullptr) ? temp->val : -1;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            if (curr == nullptr) return;
            curr = curr->next;
        }
        if (curr == nullptr) return;
        
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || head == nullptr) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            if (curr == nullptr || curr->next == nullptr) return;
            curr = curr->next;
        }
        if (curr->next == nullptr) return;
        
        Node* nodeToDelete = curr->next;
        curr->next = curr->next->next;
        delete nodeToDelete;
    }
};