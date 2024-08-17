#include<iostream>
#include<queue>
#include<stack>
using namespace std;



void reverse_RECURSIVE(queue<int> &q) {
    if(q.empty()) {
        return;
    }
    int num = q.front();
    q.pop();

    reverse_RECURSIVE(q);

    q.push(num);
}

void reverse_ITERATIVE(queue<int> &q){
    if(q.empty()){
        return;
    }
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    q.push(5);
    q.push(2);
    q.push(6);
    q.push(8);

    cout << "Original queue: ";
    printQueue(q);

    reverse_ITERATIVE(q);

    cout << "Reversed queue: ";
    printQueue(q);

    return 0;
}
