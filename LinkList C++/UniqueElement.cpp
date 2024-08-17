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

    ~node(){
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"element "<<data<<" deleted Successfully :)\n";
    }

};
void insertAtStart(node* &head,int a){
    node* temp = new node(a);
    if(head == NULL){
        head = temp;
        return;
    }
    temp->next = head;
    head =  temp;
    
}

void insertAtEnd(node* &head,int a){
    node* temp1 = new node(a);

    if(head == NULL){
        head = temp1;
        return;
    }
        node*temp2 = head;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    
    
}

node* S_unique(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* temp = head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->data == temp->next->data){
            node* after = temp->next->next;
            temp->next->next = NULL;
            delete temp->next;
            temp->next = after;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

node* US_unique(node* head){
    if(head == NULL || head->next==NULL){
        return head;
    }

    node* temp = head;
    

    while(temp!=NULL){
        node* temp2 = temp;
        while(temp2->next!=NULL){
            if(temp->data == temp2->next->data){
                node* temporary = temp2->next;
                temp2->next = temp2->next->next;
                temporary ->next = NULL;
                delete temporary;
            } else {
            temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
    return head;
   
}

void Display(node* temp){
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


int main(){

    node* head = NULL;

    insertAtStart(head,9);
    insertAtStart(head,5);
    insertAtStart(head,4);
    
    insertAtEnd(head,3);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,5);
    insertAtEnd(head,3);

    Display(head);

    // head = S_unique(head
    head = US_unique(head);
    Display(head);

return 0;
}