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

node* getmid(node* head){
    node* slow = head;
    node* fast = head->next;

    while(fast!=NULL && fast->next!= NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* reverse(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* curr = head;
    node* pre = NULL;
    node* forward = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forward;
    }

    return pre;
}


bool palindrome(node* head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    node* mid = getmid(head);
    node* temp = mid->next;
    mid->next = reverse(temp);

    node* head1 = head;
    node* head2 = mid->next;

    while(head2!=NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    temp = mid->next;
    mid->next = reverse(temp);
    return true;
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
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,4);
    insertAtEnd(head,3);
    insertAtEnd(head,2);
    insertAtEnd(head,1);

    Display(head);

    if(palindrome(head)){
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    cout<<endl;
    Display(head);
return 0;
}