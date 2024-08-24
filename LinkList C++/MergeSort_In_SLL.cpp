#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }

};

void insertATStart(Node* &head,int data){
    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

void InsertAtEnd(Node* &head,int data){
    Node* tempo = new Node(data);
    if(head == NULL){
        head = tempo;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = tempo;
}

void Display(Node* head){
    if(head == NULL){
        cout<<"Linklist is Empty\n";
        return;
    }
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL\n";

}

Node* Merge(Node* left,Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    Node* answer = new Node(-1);
    Node* temp = answer;
    
    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    
    temp = answer;
    answer = answer->next;
    delete temp;
    
    return answer;
    
}

Node* findmid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSort(Node* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node* mid = findmid(head);
        
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node* result = Merge(left,right);
        
       return result;
    } 

int main(){

    Node* head = NULL;
    insertATStart(head,5);
    InsertAtEnd(head,3);
    InsertAtEnd(head,2);
    InsertAtEnd(head,8);

    Display(head);

    head = mergeSort(head);
    Display(head);



return 0;
}