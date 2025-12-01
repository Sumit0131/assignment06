#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

void displayCircular(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int n, x;
    cin >> n;
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    if (tail) tail->next = head;
    displayCircular(head);
    return 0;
}
