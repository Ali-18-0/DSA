#include<iostream>
using namespace std;

class NODE{
    public:
    int data;
    NODE* next;

    NODE(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtStart(NODE* &head,int a){
    NODE* temp = new NODE(a);
    if(head == NULL){
        head = temp;
        return;
    } else{
    temp->next = head;
    head =  temp;
    }
}
void insertAtEnd(NODE* &head,int a){
    NODE* temp1 = new NODE(a);

    if(head == NULL){
        head = temp1;
    } else {
        NODE*temp2 = head;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    }
    
}

NODE* K_reverse(NODE* head,int k){
    if(head == NULL || head->next == NULL){
        return head;
    }
    NODE* pre = NULL;
    NODE* curr = head;
    NODE* forward = NULL;
    int count = 0;
    while(curr!=NULL && count<k){
        forward = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forward;
        count++;
    }

    if(forward!=NULL){
        head->next = K_reverse(forward,k);
    }

    return pre;

}

void Display(NODE* &head){
    NODE* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

NODE* head = NULL;

insertAtEnd(head,2);
insertAtEnd(head,4);
insertAtEnd(head,6);
insertAtEnd(head,8);
insertAtEnd(head,10);
insertAtEnd(head,12);

Display(head);

head = K_reverse(head,3);
Display(head);


return 0;
}