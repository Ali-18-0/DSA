#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;

    node(int d){
        data = d;
        next = NULL;
    }
    ~node(){
        if(next!=NULL){
            next = NULL;
        }
    }
};

class Deque{
    node* head;
    node* tail;
    int sizee;
    int count;
    
    public:
    Deque(int s){
        head = NULL;
        tail = NULL;
        sizee = s;
        count = 0;
    }
    Deque(){
        head = NULL;
        tail = NULL;
        sizee = -1;
        count = 0;
    }

    ~Deque(){
        if(!isEmpty()){
            node* temp = head;
            node* nex;
            do{
                nex = temp->next;
                delete temp;
                temp = nex;
            }while(temp!=head);
        }
        head = tail = NULL;
    }

    bool isEmpty(){
        return head == NULL;
    }

    void push_front(int a){
        if(count == sizee){
            cout<<"Deque is Full\n";
            return;
        }
        node* temp = new node(a);
        if(isEmpty()){
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
            tail->next = head;
        }
        count++;
    }

    void push_back(int a){
        if(count == sizee){
            cout<<"Deque is Full\n";
            return;
        }
        node* temp = new node(a);
        if(isEmpty()){
            head = tail = temp;
            tail->next = head;
        } else {
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }
        count++;
    }
    
    void pop_front(){
        if(isEmpty()){
            cout<<"Deque is Empty\n";
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
        } else {
            node*temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        count--;
    }
    void pop_back(){
        if(isEmpty()){
            cout<<"Deque is Empty\n";
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
        } else {
            node* temp = head;
            while(temp->next!=tail){
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = head;
        }
        count--;
    }

    int fornt(){
        if(isEmpty()){
            cout<<"Deque is Empty\n";
            return -1;
        }
        return head->data;
    }

    int back(){
        if(isEmpty()){
            cout<<"Deque is Empty\n";
            return -1;
        }
        return tail->data;
    }

    int size(){
        return count;
    }

};
int main(){

    Deque q(5);
    q.push_front(2);
    cout<<q.fornt()<<endl;
    q.push_back(3);
    cout<<q.back()<<endl;
    q.push_back(3);
    q.push_back(3);
    q.push_back(3);
    // q.pop_back();
    // q.pop_front();
    // q.pop_front();
    // q.pop_front();
    // q.pop_front();
    // q.pop_back();
    cout<<q.size()<<endl;




return 0;
}