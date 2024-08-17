#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void Interleave(queue<int> &q){

    stack<int> s;
    int size = q.size()/2,c=0;


    while(c!=size){
        s.push(q.front());
        q.pop();
        c++;
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    c=0;
    while(c!=size){
        q.push(q.front());
        q.pop();
        c++;
    }
    c=0;
    while(c!=size){
        s.push(q.front());
        q.pop();
        c++;
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

void print_Q(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    print_Q(q);
    Interleave(q);
    print_Q(q);
    

return 0;
}