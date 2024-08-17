#include<iostream>
using namespace std;

class DoublyNode{
    public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~DoublyNode(){
        int t = data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        if(this->prev!=NULL){
            delete prev;
            this->prev = NULL;
        }
        cout<<"The node that contain value "<<t<<" is deleted \n";
    }
};

void insertAtStart(DoublyNode* &head,int d){
    DoublyNode* temp = new DoublyNode(d);
    if(head == NULL){
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTailBYTraversing(DoublyNode* &head,int d){
    DoublyNode* temp = new DoublyNode(d);
    if(head == NULL){
        insertAtStart(head,d);
        return;
    }
    DoublyNode* tempo = head;

    while(tempo->next!=NULL){
        tempo = tempo->next;
    }
    tempo->next = temp;
    temp->prev = tempo;

}
void insertAtTailByTailVariable(DoublyNode* &tail,int d){
    DoublyNode* temp = new DoublyNode(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtSpecificPosition(DoublyNode* &head,int pos,int d){
    if(pos == 1){
        insertAtStart(head,d);
        return;
    }
    DoublyNode* tempo = head;
    int pos1 = 1;
    while(tempo->next!=NULL && pos1<pos-1){
        tempo = tempo->next;
        pos1++;
    }
    if(tempo->next == NULL){
        insertAtTailBYTraversing(tempo,d);
        return;
    }

    DoublyNode* temp = new DoublyNode(d);
    temp->next = tempo->next;
    tempo->next->prev = temp;
    tempo->next = temp;
    temp->prev = tempo;

}

void deleteNodeAtStart(DoublyNode* &head){
    if(head==NULL){
        cout<<"\nList is empty\n";
        return;
    }
    DoublyNode* temp = head;
    head = head->next;
    if(head!=NULL){
    head->prev = NULL;
    }
    temp->next = NULL;
    delete temp;
    
    
}
 void deletenodefromTail(DoublyNode* &head){
    if(head==NULL){
        cout<<"\nList is empty\n";
        return;
    }
    if(head->next == NULL){
        deleteNodeAtStart(head);
        return;
    }
        DoublyNode* curr = head;
        DoublyNode* prev = NULL;
        while(curr->next!=NULL){
        prev = curr;
        curr = curr->next;
        }
        
        prev->next = NULL;
        curr->prev = NULL;
        delete curr;
 }

 void deleteAtSpecificPosition(DoublyNode* &head,int pos){
    if(head==NULL){
        cout<<"\nList is empty\n";
        return;
    }
    if(pos==1){
        deleteNodeAtStart(head);
        return;
    }
    DoublyNode* curr = head;
    DoublyNode* prev = NULL;
    int pos1 = 1;
    while(curr!=NULL && pos1 < pos){
        prev = curr;
        curr = curr->next;
        pos1++;
    }

    if(curr == NULL){
        cout<<"\nThe position index not exist\nSo deleting the last node\n";
        deletenodefromTail(head);
        return;
    }
    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;

 }

 void deletenodethroughData(DoublyNode* &head,int value){
    if(head->data==value){
        deleteNodeAtStart(head);
        return;
    }
    DoublyNode* curr = head;
    DoublyNode* prev = NULL;
    while(curr!=NULL && curr->data!=value){
        prev =curr;
        curr = curr->next;
    }
    if(curr==NULL){
        cout<<"\nthe value "<<value<<" not found in list\n";
        return;
    }
    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    
 }

void display(DoublyNode* &head){
    if(head==NULL){
        cout<<"->NULL";
        return;
    }
    DoublyNode*  temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp =temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    DoublyNode* node1 = NULL;

    DoublyNode* head = node1;
    // DoublyNode* tail = node1;

    insertAtStart(head,4);
    insertAtStart(head,6);
    insertAtStart(head,7);
    insertAtStart(head,8);

    display(head);

    // insertAtTailByTailVariable(tail,9);
    insertAtTailBYTraversing(head,9);
    display(head);

    insertAtSpecificPosition(head,6,22);
    display(head);

    deleteNodeAtStart(head);
    display(head);

    deletenodefromTail(head);
    display(head);

    insertAtStart(head,34);
    insertAtStart(head,36);
    display(head);

    deleteAtSpecificPosition(head,3);
    display(head);

    deletenodethroughData(head,123);
    display(head);

return 0;

}