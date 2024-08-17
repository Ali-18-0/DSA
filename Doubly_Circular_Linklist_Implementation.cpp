#include<iostream>
using namespace std;
 
class CDNODE{
    public:
    int data;
    CDNODE* next;
    CDNODE* prev;

    CDNODE(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~CDNODE(){
        if(this->next!=NULL){
            delete this->next;
            this->next = NULL;
        } 
        if(this->prev != NULL){
            delete this->prev;
            this->prev = NULL;
        }
        cout<<"\nNode deleted that contain data(value) "<<this->data<<endl;
    }
};

void insertNode(CDNODE* &head,int element,int value){

    CDNODE* newnode = new CDNODE(value);

    if(head == NULL){
        head = newnode;
        head->next = head;
        head->prev = head;
        return;
    }
    
    CDNODE* temp = head;
    while(temp->data != element && temp->next != head){
        temp = temp->next;
    }
    if(temp->data!=element){
        cout<<"\nCan't deleted node Cuz element not found\n";
        return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;

}


void deleteNode(CDNODE* & head,int element){
    if(head == NULL){
        cout<<"\nCan't Delete List is empty\n";
        return;
    }
    CDNODE* pre = head;
    CDNODE* curr = head->next;
    while(curr->data!=element && curr!=head){
        pre = curr;
        curr = curr->next;
    }
    if(curr->data!=element){
        cout<<"\nCan't delete node element not found in list\n";
        return;
    }
    pre->next = curr->next;
    curr->next->prev = pre;
    if(curr == pre){
        head == NULL;
    } else if(head == curr){
        head = head->next;
    }
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}
void Display(CDNODE* &head){
    if(head == NULL){
        cout<<"\nList is empty\n";
        return;
    }
    CDNODE* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=head);
    cout<<"\n";
}

void ReverseDisplay(CDNODE* &head){
    if(head == NULL){
        cout<<"\nList is empty\n";
        return;
    }
    CDNODE* temp = head->prev;
    cout<<"Reverse Order : ";
    do{
        cout<<temp->data<<" ";
        temp = temp->prev;
    }while(temp!=head->prev);
    cout<<"\n";
}

int main(){

    CDNODE* head = NULL;

    insertNode(head,1,2);
    Display(head);

    insertNode(head,2,4);
    Display(head);

    insertNode(head,4,6);
    Display(head);

    insertNode(head,6,8);
    Display(head);

    insertNode(head,4,5);
    Display(head);

    // cout<<head->data<<endl;
    // cout<<head->next->data<<endl;
    // cout<<head->next->data<<endl;
    // cout<<head->next->next->data<<endl;
    ReverseDisplay(head);
    
    cout<<endl;

    deleteNode(head,8);
    Display(head);
    // cout<<head->data<<endl;
    // cout<<head->next->data<<endl;


return 0;
}