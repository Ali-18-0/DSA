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
    int a = data;
    if(this->next!=NULL){
        delete next;
        this->next = NULL;
    }
    cout<<"\nThe Node is deleted which data value is : "<<a<<endl;
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

void insertAtEnd(node* &head,int a){
    node* temp1 = new node(a);

    if(head == NULL){
        head = temp1;
    } else {
        node*temp2 = head;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    }
    
}
void end(node* &tail,int a){
    node* temp = new node(a);
    tail->next = temp;
    tail = temp;
}

void insertAtSpecific(node* &head,node* &tail,int pos,int a){

    if(pos==1){
        insertAtStart(head,a);
        return;
    }
    
    node* temp = head;
    int pos1 = 1;
    while(pos1<pos-1 && temp->next!=NULL){
        temp = temp->next;
        pos1++;
    }
    if(temp->next==NULL){
        end(tail,a);
        return;
    }
    node* newtemp = new node(a);
    newtemp->next = temp->next;
    temp->next = newtemp;
}

void deleteHeadNode(node* &head){
    node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
}
void deleteTailNode(node* &head){
    node* curr = head;
    node* prev = NULL;
    while(curr->next!=NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    delete curr;
}
void deleteNodeAtPos(node* &head,int pos){
    if(pos==1){
        deleteHeadNode(head);
    } else {
        node* curr = head;
        node* prev = NULL;
        int pos1 = 1;
        while(pos1<pos && curr!=NULL) {
            prev = curr;
            curr = curr->next;
            pos1++;
        }
        if(curr==NULL){
            cout<<"\nPosition index is OUT OF BOUND \n deleting tail node\n";
            // prev->next = NULL;
            // delete curr;
            deleteTailNode(head);
            return;
        } 
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        
    }
}

void deletenodeThroughDataValue(node* &head,int value){
    if(head==NULL){
        return;
    }
    if(head->data==value){
        deleteHeadNode(head);
        return;
    }
    node* curr = head;
    node* prev = NULL;
    while(curr!=NULL && curr->data!=value){
        prev = curr;
        curr = curr->next;
    }
    if(curr==NULL){
        cout<<"\nvalue "<<value<<" not found in the list \n";
        return;
    }
    
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    
}

void Display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    // cout<<"\n"<<temp<<endl;
    // cout<<"\n"<<temp->data<<endl;
    // cout<<"\n"<<temp->next<<endl;
    // cout<<"\n";
}

int main(){

    node * node1 = new node(6);

    node* head = node1;
    node* tail = node1;

    insertAtStart(head,6);
    insertAtStart(head,87);
    insertAtStart(head,12);
    Display(head);
    cout<<endl;

    insertAtEnd(head,99);
    Display(head);

    cout<<endl;

    end(tail,45);
    end(tail,46);
    end(tail,47);
    Display(head);
    cout<<endl;

    insertAtSpecific(head,tail,11,59);
    Display(head);
    cout<<"\nhead "<<head->data<<" tail "<<tail->data;
    // cout<<head->data<<" ";
    // cout<<head->next->data<<" ";
    // cout<<head->next->next->data<<" ";
    // cout<<head->next->next->next->data<<" ";
    // cout<<head->next->next->next->next<<" ";

    deleteNodeAtPos(head,8);
    // deleteTailNode(head);
    // deleteHeadNode(head);
    Display(head);

    deletenodeThroughDataValue(head,12);
    Display(head);

return 0;

}