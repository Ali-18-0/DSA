#include<iostream>
#include<stack>
using namespace std;

bool redundant(string a){
    stack<char> st;

    for(int i=0;i<a.length();i++){
        if(a[i] == '(' || a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/'){
            st.push(a[i]);
        } else {
            if(a[i] == ')'){
                bool isredundant = true;
                while(st.top()!='('){
                char top = st.top();
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    isredundant = false;
                    st.pop();
                }

                }
                if(isredundant){
                    return false;
                }
                st.pop();
            }
        }
    }
    return true;
}

int main(){

    string a = "(a+(b+(c+(d+(e/2)))))";

    if(redundant(a)){
        cout<<"Valid";
    } else {
        cout<<"Invalid";
    }

return 0;
}