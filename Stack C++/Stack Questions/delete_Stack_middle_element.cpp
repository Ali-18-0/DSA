#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &a,int size,int count){
    if(count==size/2){
        a.pop();
        return;
    }

    int copy = a.top();
    a.pop();

    solve(a,size,count+1);

    a.push(copy);
    return;
}

void deleteMiddleElement(stack<int> &a,int size){
    int count = 0;
    solve(a,size,count);
}

int main(){

    stack<int> st;
    st.push(6);
    st.push(4);
    st.push(2);
    st.push(8);
    st.push(5);

    cout<<st.top()<<endl;

    deleteMiddleElement(st,st.size());

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;


return 0;
}