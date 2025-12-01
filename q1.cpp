#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

class DoublyLL {
public:
    Node* head;
    DoublyLL() : head(NULL) {}
    
    void insertFront(int x) {
        Node* newNode = new Node(x);
        if (!head) head = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void insertEnd(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    void insertAfter(int key, int x) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (temp) {
            Node* newNode = new Node(x);
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
    
    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            if (head) head->prev = NULL;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (temp->next) {
            Node* toDel = temp->next;
            temp->next = toDel->next;
            if (toDel->next) toDel->next->prev = temp;
            delete toDel;
        }
    }
    
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }
    
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CircularLL {
public:
    Node* head;
    CircularLL() : head(NULL) {}
    
    void insertFront(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        newNode->next = head;
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        head = newNode;
    }
    
    void insertEnd(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    
    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) {
            if (head->next == head) {
                delete head;
                head = NULL;
                return;
            }
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = head->next;
            Node* toDel = head;
            head = head->next;
            delete toDel;
            return;
        }
        Node* temp = head;
        while (temp->next != head && temp->next->data != key) temp = temp->next;
        if (temp->next != head) {
            Node* toDel = temp->next;
            temp->next = toDel->next;
            delete toDel;
        }
    }
    
    bool search(int key) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == key) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }
    
    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyLL dll;
    CircularLL cll;
    int choice, type, val, key;
    while (true) {
        cin >> choice;
        if (choice == 0) break;
        cin >> type;
        if (type == 1) {
            if (choice == 1) {
                cin >> val;
                dll.insertFront(val);
            } else if (choice == 2) {
                cin >> val;
                dll.insertEnd(val);
            } else if (choice == 3) {
                cin >> key >> val;
                dll.insertAfter(key, val);
            } else if (choice == 4) {
                cin >> val;
                dll.deleteNode(val);
            } else if (choice == 5) {
                cin >> val;
                cout << (dll.search(val) ? 1 : 0) << endl;
            }
            dll.display();
        } else {
            if (choice == 1) {
                cin >> val;
                cll.insertFront(val);
            } else if (choice == 2) {
                cin >> val;
                cll.insertEnd(val);
            } else if (choice == 4) {
                cin >> val;
                cll.deleteNode(val);
            } else if (choice == 5) {
                cin >> val;
                cout << (cll.search(val) ? 1 : 0) << endl;
            }
            cll.display();
        }
    }
    return 0;
}
