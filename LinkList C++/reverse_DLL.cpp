#include<iostream>
using namespace std;

class DNODE{
    public:
    int data;
    DNODE* next;
    DNODE* prev;

    DNODE(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~DNODE(){
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        if(this->prev!=NULL){
            delete prev;
            this->prev = NULL;
        }

        cout<<"Node deleted that contain data(value) : "<<data<<endl;
    }
};

void insertAtStart(DNODE* &head,int d){
    DNODE* newnode = new DNODE(d);
    if(head == NULL){
        head = newnode;
        return ; 
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insertAtEnd(DNODE* &head,int d){
    DNODE* newnode = new DNODE(d);
    if(head == NULL){
        head = newnode;
        return ;
    }
    DNODE* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    
    
}
DNODE* Reverse_Iterative(DNODE* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    DNODE* pre = NULL;
    DNODE* curr = head;
    DNODE* forward = NULL;
    
    while(curr!=NULL){
        forward = curr->next;
        curr->next = pre;
        curr->prev = forward;
        pre = curr;
        curr = forward;

    }

    return pre;

}
DNODE* Reverse_Recursive(DNODE* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    DNODE* newnode = Reverse_Recursive(head->next);

    head->next->prev = head->next->next;
    head->next->next = head;
    head->next = NULL;


    return newnode;

}

void print(DNODE* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}
void Rprint(DNODE* head){
    while(head->next!=NULL){
        head = head->next;
    }
    cout<<"Reverse order : ";
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->prev;
    }
    cout<<"NULL"<<endl;
}

int main(){

    DNODE* head = NULL;

    insertAtStart(head,2);
    insertAtStart(head,4);

    insertAtEnd(head,6);
    insertAtEnd(head,8);
    // cout<<head->next->prev->data;
    print(head);
    // Rprint(head);

    // head = Reverse_Iterative(head);
    // print(head);
    // Rprint(head);
    cout<<endl;

    head = Reverse_Recursive(head);
    print(head);
    Rprint(head);

return 0;
}