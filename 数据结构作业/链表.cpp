#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
const ll maxn = 1e9+10;

// 定义单链表的结点结构体
struct Node {
    ll data;           // 数据域
    Node* next;         // 指针域，指向下一个结点
};

// 创建带头结点的单链表
Node* create() {
    Node* head = new Node; // 创建头结点
    head->next = nullptr;  // 初始化头结点的指针为空
    return head;
}

// 在链表中插入新结点
void add(Node* L, ll value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = L->next;
    L->next = newNode;
}

// 删除链表中所有值为x的结点
void del(Node* L, ll x) {
    Node* prev = L;          // 指向当前结点的前驱
    Node* current = L->next; // 当前结点从头结点后的第一个开始

    while (current != nullptr) {
        if (current->data == x) {
            // 找到值为x的结点，执行删除操作
            prev->next = current->next;  // 前驱的next指向当前结点的next
            delete current;              // 释放当前结点的内存
            current = prev->next;        // 更新当前结点为下一个结点
        } else {
            // 当前结点不需要删除，继续前进
            prev = current;
            current = current->next;
        }
    }
}

// 打印链表
void printList(Node* L) {
    Node* current = L->next;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // 创建带头结点的链表
    Node* L = create();

    // 插入一些测试数据
    add(L, 5);
    add(L, 3);
    add(L, 5);
    add(L, 2);
    add(L, 5);
    add(L, 1);
    printList(L);
    // 删除所有值为5的结点
    del(L, 5);
    printList(L);
    return 0;
}
