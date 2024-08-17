#include<iostream>
#include <vector>
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

bool checkPalindrome(vector<int> arr){
    int size = arr.size();
    int s = 0;
    int e = size-1;
    while(s<=e){
        if(arr[s]!=arr[e]){
            return false;
        }
        s++;
        e--;
    }
    arr.clear();
    return true;
}

bool palindrome(node* &head){
    if(head == NULL || head->next == NULL){
        return true;
    }

    node* temp = head;
    vector<int> arr;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome(arr);
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
    insertAtEnd(head,1);

    if(palindrome(head)){
        cout<<"YES";
    } else {
        cout<<"NO";
    }

return 0;
}