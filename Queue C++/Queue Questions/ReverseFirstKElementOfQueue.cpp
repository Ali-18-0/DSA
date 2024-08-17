#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void ReverseK(queue<int> &q,int k){
    if(k>q.size()){
        cout<<"Can't reverse k is larger then size\n";
        return;
    }
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    int t = q.size() - k;
    while(t!=0){
        q.push(q.front());
        q.pop();
        t--;
    }

}
void print(queue<int> q){
    while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    print(q);
    ReverseK(q,5);
    print(q);

return 0;
}