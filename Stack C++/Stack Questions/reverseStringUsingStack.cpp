#include<iostream>
#include<stack>
using namespace std;

int main(){

    // string a = "";
    // a.push_back('a');
    
    string a = "U EVOL I";
    stack<char> st;
    for(int i = 0;i<a.length();i++){
        st.push(a[i]);
    }
    string rev = "";
    char s;
    while(!st.empty()){
        s = st.top();
        rev.push_back(s);
        st.pop();
    }
    cout<<rev;
return 0;
}