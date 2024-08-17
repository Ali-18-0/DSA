#include<iostream>
using namespace std;

class CNODE{
    public:
    int data;
    CNODE* next;

    CNODE(int data){
        this->data = data;
        this->next = NULL;
    }
    ~CNODE(){
        if(this->next !=NULL){
            delete next;
            next = NULL;
        }
        cout<<"The node deleted that contain data value : "<<this->data<<endl;
    }
};

void insertNode(CNODE* &head,int element,int d){

    CNODE* temp = new CNODE(d);

    if(head == NULL){
        head = temp;
        head->next = head;
        return ;
    }
    CNODE* curr = head;
    while(curr->data!=element && curr->next!=head){
        curr = curr->next;
    }
    if(curr->data!=element){
        cout<<"\nElement not found in the list \n";
        return;
    }
    temp->next = curr->next;
    curr->next = temp;

}

void deleteNode(CNODE* &head,int d){
    if(head == NULL){
        cout<<"\nCan't Delete List is Empty\n";
        return;
    }
    CNODE* curr = head->next;
    CNODE* prev = head;
    while(curr->data!=d && curr!=head){
        prev = curr;
        curr = curr->next;
    }
    if(curr->data!=d){
        cout<<"\nCan't delete node Element not found\n";
        return;
    }
    prev->next = curr->next;
    if(curr == prev){
        head = NULL;
    } else if(head == curr){
        head = head->next;
    }
    curr->next = NULL;
    delete curr;
    
}

void Display(CNODE* &head){

    if(head==NULL){
        cout<<"\nList is Empty\n";
        return;
    }
    CNODE* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=head);
    cout<<endl;
}

int main(){

    CNODE* head = NULL;

    insertNode(head,2,4);
    Display(head);

    insertNode(head,4,6);
    Display(head);

    insertNode(head,6,8);
    Display(head);

    insertNode(head,8,10);
    Display(head);

    insertNode(head,10,8);
    Display(head);

    insertNode(head,111,1);
    Display(head);

    deleteNode(head,4);
    Display(head);

return 0;
}