#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;

// 定义顺序循环队列结构体
struct CircularQueue {
    int data[MAXSIZE];  // 队列的数组
    int front;          // 头指针
    int rear;           // 尾指针
    int tag;            // 标志位，区分空和满，tag=0表示空，tag=1表示满
};

// 初始化队列
void initQueue(CircularQueue &queue) {
    queue.front = 0;
    queue.rear = 0;
    queue.tag = 0;  // 初始化为空
}

// 判断队列是否为空
bool isEmpty(const CircularQueue &queue) {
    return queue.front == queue.rear && queue.tag == 0;
}

// 判断队列是否为满
bool isFull(const CircularQueue &queue) {
    return queue.front == queue.rear && queue.tag == 1;
}

// 入队操作
bool enqueue(CircularQueue &queue, int value) {
    if (isFull(queue)) {
        cout << "队列已满，无法入队！" << endl;
        return false;
    }
    queue.data[queue.rear] = value;
    queue.rear = (queue.rear + 1) % MAXSIZE;
    queue.tag = 1;  // 入队后，队列不为空
    return true;
}

// 出队操作
bool dequeue(CircularQueue &queue, int &value) {
    if (isEmpty(queue)) {
        cout << "队列为空，无法出队！" << endl;
        return false;
    }
    value = queue.data[queue.front];
    queue.front = (queue.front + 1) % MAXSIZE;
    queue.tag = 0;  // 出队后，队列不满
    return true;
}

// 输出队列内容
void displayQueue(const CircularQueue &queue) {
    if (isEmpty(queue)) {
        cout << "队列为空！" << endl;
        return;
    }
    int i = queue.front;
    while (i != queue.rear || (i == queue.rear && queue.tag == 1)) {
        cout << queue.data[i] << " ";
        i = (i + 1) % MAXSIZE;
    }
    cout << endl;
}

int main() {
    CircularQueue queue;
    initQueue(queue);  // 初始化队列

    // 测试入队
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);

    // 测试出队
    int value;
    dequeue(queue, value);
    cout << "出队元素：" << value << endl;
    dequeue(queue, value);
    cout << "出队元素：" << value << endl;
    dequeue(queue, value);
    cout << "出队元素：" << value << endl;
    enqueue(queue, 123);
    dequeue(queue, value);
    cout << "出队元素：" << value << endl;
    dequeue(queue, value);
    cout << "出队元素：" << value << endl;

}