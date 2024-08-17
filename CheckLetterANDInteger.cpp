#include<iostream>
using namespace std;

int main(){
    string a = "d76das7d6";
    string d = "m4n2l3432232";
    bool isalphadisgit = true;
    bool isalphadisgit2 = true;
    for(char ch : a){
        if( !((ch>='0' && ch<='9' ) ||
            (ch>='a' && ch<='z')  ||
            (ch>='A' && ch<='Z'))
        ){
            isalphadisgit = false;
        }
    }

    for(char ch : d){
        if(!isalnum(ch)){
            isalphadisgit2 = false;
        }
    }
    
    if(isalphadisgit2){
        cout<<"YES";
    } else {
        cout<<"NO";
    }

return 0;
}