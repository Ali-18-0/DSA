#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtStart(node* &head,int d){
        
    node* temp = new node(d);

    if(head == NULL){
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}
void insertAtEnd(node* &head,int d){

    if(head == NULL){
        insertAtStart(head,d);
        return;
    }

    node* temp = new node(d);
    node* tempo = head;
    while(tempo->next != NULL){
        tempo = tempo->next;
    }
    tempo->next = temp;
}

int length(node* head){
    int length = 0;
    node* temp = head;
    while(temp!=NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

node* middleoflist(node* head){

    int len = length(head);

    int middle = 0;
    if(len%2==0){
        middle = (len/2);
    } else {
        middle = len/2;
    }
    int cnt = 0;
    while(cnt!=middle){
        head = head->next;
        cnt++;
    }
    return head;
}

void Display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

int main(){

    node* head = NULL;
    insertAtStart(head,6);
    Display(head);

    insertAtEnd(head,9);
    Display(head);

    insertAtEnd(head,12);
    Display(head);

    insertAtEnd(head,3);
    Display(head);

    insertAtEnd(head,7);
    Display(head);

    insertAtEnd(head,15);
    Display(head);

    cout<<length(head)<<endl;
    cout<<(length(head)/2)+1<<endl;
    
    node* temp = middleoflist(head);
    
    cout<<temp->data;

return 0;

}