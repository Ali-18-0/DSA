#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(NULL) {}
};

class Queue {
    Node* head;
    Node* tail;

public:
    Queue() : head(NULL), tail(NULL) {}

    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return head == NULL;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return head->data;
    }

    int back() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return tail->data;
    }

    void push(int a) {
        Node* temp = new Node(a);
        if (isEmpty()) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL) {  // Queue became empty
            tail = NULL;
        }
        delete temp;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    Queue q;
    q.push(6);
    q.push(63);
    q.push(61);
    q.push(26);

    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    cout << q.front() << endl;

    return 0;
}
