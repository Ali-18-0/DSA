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

/*************************************************************************************/
// 1st APPROCH

void end(node* &tail,node* curr){
    tail->next = curr;
    tail = curr;
}

node* SORT012(node* head){
    node* zeronode = new node(-1);
    node* zero = zeronode;
    node* onenode = new node(-1);
    node* one = onenode;
    node* twonode = new node(-1);
    node* two = twonode;

    node* curr = head;
    while(curr!=NULL){
        int v = curr->data;
        if(v == 0){
            end(zero,curr);
        } else if(v == 1){
            end(one,curr);
        } else if(v == 2){
            end(two,curr);
        }
        curr = curr->next;
    }

    if(onenode->next!=NULL){
        zero->next = onenode->next;
        one->next = twonode->next;
    } else {
        zero->next = twonode->next;
    }
    two->next = NULL;
    head = zeronode->next;
    zeronode->next = NULL;
    onenode->next = NULL;
    twonode->next = NULL;

    delete zeronode;
    delete onenode;
    delete twonode;

    return head;

}

/*************************************************************************************/
// 2nd APPROCH

node* sort021(node* head){
    int zero = 0;
    int one = 0;
    int two = 0;

    node* curr = head;

    while(curr!=NULL){
        if(curr->data == 0){
            zero++;
        } else if(curr->data == 1){
            one++;
        } else if(curr->data ==  2){
            two++;
        }
        curr = curr->next;
    }

    curr = head;
    while(curr!=NULL){
        if(zero!=0){
            curr->data = 0;
            zero--;
        } else if(one!=0){
            curr->data = 1;
            one--;
        } else if(two!=0){
            curr->data = 2;
            two--;
        }
        curr = curr->next;
    }
    return head;
}


/************************************************************************************/

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){

    node* head = NULL;

    insertAtStart(head,2);
    insertAtEnd(head,0);
    insertAtEnd(head,2);
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,1);

    display(head);

    head = sort021(head);
    // head = SORT012(head);
    display(head);

return 0;
}