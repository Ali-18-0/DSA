#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int> st;

    st.push(5);
    st.push(51);
    st.push(52);
    cout<<st.top()<<endl;

    st.pop();
    cout<<st.top()<<endl;

    if(st.empty()){
        cout<<"true";
    } else {
        cout<<"false";
    }
    cout<<endl;
    cout<<st.size();
    

return 0;
}