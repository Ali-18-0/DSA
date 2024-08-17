#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtStart(node* &head,int data){
    node* temp = new node(data);
    if(head == NULL){
        head = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

void insertAtEnd(node* &head,int data){
    node* temp = new node(data);
    if(head == NULL){
        head = temp;
        return;
    }
    node* tempo = head;
    while(tempo->next!=NULL){
        tempo = tempo->next;
    }
    tempo->next = temp;
}

void insertAtSpecific(node* &head,int pos,int data){
    node* temp = new node(data);
    if(head == NULL){
        head = temp;
        return;
    }
    int count = 0;
    node* tempo = head;
    while(tempo!=NULL && count<pos-1){
        tempo = tempo->next;
        count++;
    }
    if(tempo == NULL){
        cout<<"\nPosition not found\n";
        return;
    }
    temp->next = tempo->next;
    tempo->next = temp;
}

void merge(node* &head,int start,int mid,int end){
    node* temp = NULL;
    int left = start;
    int right = mid+1;

    while(left<=mid && right<=end){
        if()
    }
}

void mergesort(node* &head,int start,int end){
    if(start<end){
        int mid = start + (end - start)/2;
        mergesort(head,start,mid);
        mergesort(head,mid+1,end);
        merge(head,start,mid,end);

    }
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){

    node* head = NULL;

    insertAtStart(head,4);
    insertAtStart(head,2);
    insertAtEnd(head,6);
    insertAtEnd(head,8);
    print(head);

    

return 0;
}