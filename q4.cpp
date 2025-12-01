#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char x) : data(x), next(NULL), prev(NULL) {}
};

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* rev = NULL;
    Node* curr = slow;
    while (curr) {
        Node* next = curr->next;
        curr->next = rev;
        rev = curr;
        curr = next;
    }
    Node* left = head;
    Node* right = rev;
    while (right) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        Node* newNode = new Node(x);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    cout << (isPalindrome(head) ? "True" : "False") << endl;
    return 0;
}
