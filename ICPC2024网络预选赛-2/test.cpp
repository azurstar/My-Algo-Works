#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

struct Node {
    ll data;
    Node *next;
};

void add(Node *&head, ll data) {
    Node *newNode = new Node{data, nullptr};
    if (!head || head->data > data) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *p = head;
    while (p->next && p->next->data <= data) {
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
}

void del(Node *&head, ll data) {
    if (!head) return;

    if (head->data == data) {
        Node *td = head;
        head = head->next;
        delete td;
        return;
    }

    Node *p = head;
    while (p->next && p->next->data != data) {
        p = p->next;
    }

    if (p->next) {
        Node *td = p->next;
        p->next = p->next->next;
        delete td;
    }
}

void printList(Node *head) {
    Node *p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;

    add(head, 10);
    add(head, 5);
    add(head, 12);
    add(head, 15);
    add(head, 23);

    printList(head); // 5 10 12 15 23
    del(head, 15);
    printList(head); // 5 10 12 23
    del(head, 12);
    printList(head); // 5 10 23
}
