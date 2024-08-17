#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<int> q;
    q.push(5);
    q.push(3);
    q.push(7);
    q.push(11);
    

    cout<<q.front()<<endl;

    q.pop();

    cout<<q.front()<<endl;

    cout<<q.back()<<endl;

    cout<<q.size()<<endl;
    
    if(q.empty()){
        cout<<"YES";
    } else {
        cout<<"NO";
    }

return 0;
}