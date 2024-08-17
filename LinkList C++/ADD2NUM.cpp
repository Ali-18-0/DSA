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

node* reverse(node* head){
    node* pre = NULL;
    node* curr = head;
    node* forward = NULL;

    while(curr!=NULL){
        forward = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forward;
        
    }
    return pre;
}



node* addfunction(node* head1,node*head2){
    node* newhead = NULL;
    int carry = 0;
    while(head1!=NULL && head2!=NULL){
        int sum = head1->data + head2->data + carry;
        int digit = sum%10;
        insertAtEnd(newhead,digit);
        carry = sum/10;
        head1 = head1->next;
        head2 = head2->next;
    }

    while(head1!=NULL){
        int sum = carry + head1->data;
        int digit = sum%10;
        insertAtEnd(newhead,digit);
        carry = sum/10;
        head1 = head1->next;
    }
    while(head2!=NULL){
        int sum = carry + head2->data;
        int digit = sum%10;
        insertAtEnd(newhead,digit);
        carry = sum/10;
        head2 = head2->next;
    }

    return newhead;
}

node* ADD(node* head1,node* head2){
    if( head1 == NULL){
        return head2;
    } if(head2 == NULL){
        return head2;
    }

    head1 = reverse(head1);
    head2 = reverse(head2);

    node* ans = addfunction(head1,head2);

    ans = reverse(ans);

    return ans;

}
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){

    node* head1 = NULL;
    node* head2 = NULL;

    insertAtStart(head1,9);
    insertAtEnd(head1,3);
    insertAtEnd(head1,4);
    insertAtEnd(head1,5);
    display(head1);

    insertAtStart(head2,4);
    insertAtEnd(head2,3);
    insertAtEnd(head2,5);
    insertAtEnd(head2,7);
    insertAtEnd(head2,3);
    display(head2);

    // head2 = reverse(head2);
    // display(head2);

    node* newnode = NULL;
    newnode = ADD(head1,head2);
    display(newnode);

return 0;
}