#include<iostream>
using namespace std;

int main(){

    int a = 123;
    cout<<to_string(a)<<endl;


    string b = "321f";
    cout<<stoi(b)<<endl;

    string test = "2k4g2k34gj32g4532g42u3";
    long long testnum = 0;
    for(int i=0;i<test.length();i++){ // or for(char ch : test)
        if(isdigit(test[i])){        // if(isdigit(ch))
            testnum = testnum*10 + test[i] - '0';// ch - '0'
            
        }
    }

    cout<<testnum;
    

return 0;
}