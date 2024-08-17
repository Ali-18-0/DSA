#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> q;
    q.pop();
    q.push(5);
    q.push(5);
    cout<<q.top();

return 0;
}