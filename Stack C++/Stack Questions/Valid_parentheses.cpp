#include<iostream>
#include<stack>
using namespace std;

bool validCheck(string a){
    stack<char> st;

    for(int i=0;i<a.length();i++){
        char temp = a[i];

        if(a[i] == '[' || a[i] == '{' || a[i] == '('){
            st.push(a[i]);
        } else {
            if(!st.empty()){
                char t = st.top();
                if(( (temp == ')' && t =='(') || 
                (temp == '}' && t == '{') || 
                (temp == ']' && t == '[') )){
                    st.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}

int main(){

    string a = "[{({[]})}]";

    if(validCheck(a)){
        cout<<"YES";
    } else {
        cout<<"NO";
    }

return 0;
}