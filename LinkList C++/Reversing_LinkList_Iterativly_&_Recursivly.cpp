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
    
    ~node(){
        if(this->next!=NULL){
            delete this->next;
            this->next = NULL;
        }
        cout<<"NODE DELETED VALUD = "<<this->data<<endl;
    }
};

void insertAtStart(node* &head,int a){
    node* temp = new node(a);
    if(head == NULL){
        head = temp;
        return;
    } else{
    temp->next = head;
    head =  temp;
    }
}

node* ReverseITERATIVE(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

node* ReverseRECURSIVE(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* newhead = ReverseRECURSIVE(head->next);

    head->next->next = head;
    head->next = NULL;

    return newhead;
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

    insertAtStart(head,5);
    insertAtStart(head,4);
    insertAtStart(head,3);
    insertAtStart(head,6);
    Display(head);

    head = ReverseITERATIVE(head);
    Display(head);
    
    head = ReverseRECURSIVE(head);
    Display(head);

return 0;
}