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

/****************************************************************************************/

node* merge(node* first,node* second){

    node* fcurr = first;
    node* fnext = fcurr->next;
    node* scurr = second;
    node* snext = scurr->next;

    while(fcurr!=NULL && scurr!=NULL){
        if(fcurr->data <= scurr->data && fnext->data >= scurr->data){
            fcurr->next = scurr;
            snext = scurr->next;
            scurr->next = fnext;
            fcurr = scurr;
            scurr = snext;
        } else{
            fcurr = fnext;
            fnext =fnext->next;

        }
            if(fnext == NULL){
            fcurr->next = scurr;
            return first;
        }
    }
    return first;

}

node* merge_LL(node* first,node* second){
    if(first == NULL){
        return second;
    } if(second == NULL){
        return first;
    }

    if(first->data<=second->data){

       return merge(first,second);

    } else {
        return merge(second,first);
    }


}
/****************************************************************************************/

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

    insertAtStart(head1,1);
    insertAtEnd(head1,3);
    insertAtEnd(head1,5);
    display(head1);

    insertAtStart(head2,2);
    insertAtEnd(head2,4);
    insertAtEnd(head2,5);
    display(head2);


    head1 = merge_LL(head1,head2);
    display(head1);
return 0;
}