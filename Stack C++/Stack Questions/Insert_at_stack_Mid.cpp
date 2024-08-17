#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st,int size,int element,int count){
    if(count == size/2){
        st.push(element);
        return;
    }

    int copy = st.top();
    st.pop();

    solve(st,size,element,count+1);

    st.push(copy);
    return;
}

void insertAtMidOf_Stack(stack<int> &st,int size,int element){
    int count = 0;
    solve(st,size,element,count);
}
int main(){

    stack<int> st;
    st.push(1);
    st.push(3);

    insertAtMidOf_Stack(st,st.size(),2);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;


return 0;
}