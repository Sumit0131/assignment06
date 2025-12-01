#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

int sizeDLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while (temp) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int sizeCLL(Node* head) {
    if (!head) return 0;
    int cnt = 1;
    Node* temp = head->next;
    while (temp != head) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main() {
    int n, type;
    cin >> n >> type;
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int x;
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
    if (type == 1) cout << sizeDLL(head) << endl;
    else cout << sizeCLL(head) << endl;
    return 0;
}
