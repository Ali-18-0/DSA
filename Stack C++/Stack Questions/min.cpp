#include<iostream>
#include<stack>
using namespace std;


void minimum(stack<int> &st,int &a){
    if(st.empty()){
        
        return ;
    }

    if(a>st.top()){
        a = st.top();
    }
    st.pop();

   return minimum(st,a);


}

stack<int> getmin(stack<int> st){

    if(st.empty()){
        return st;
    }
    stack<int> result;

    int copy = st.top();
    int copy1 = st.top();
    st.pop();

    result = getmin(st);

    minimum(st,copy1);
    result.push(copy1);
    st.push(copy);
    
    return result;

}

int main(){

    stack<int> st;
    st.push(4);
    st.push(8);
    st.push(1);
    st.push(2);
    st.push(10);

    cout<<st.top()<<endl;

    stack<int> st2;
    st2 = getmin(st);

    cout<<st2.top()<<endl;
    st2.pop();
    cout<<st2.top()<<endl;
    st2.pop();
    cout<<st2.top()<<endl;
    st2.pop();
    cout<<st2.top()<<endl;
    st2.pop();
    cout<<st2.top()<<endl;


return 0;
}