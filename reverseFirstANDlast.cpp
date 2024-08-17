#include<iostream>
using namespace std;

void reverseNum(int &a){
    if(a==0){
        return;
    } 
    int result = 0;
    while(a!=0){
        result = result*10 + a%10;
        a/=10;
    }
    a = result;
}

 int swapFirstANDLastDigit(int a){
    int temp = a%10;
    a/=10;
    reverseNum(a);
    int temp2 = a%10;
    a/=10;
    a = a*10 + temp;
    reverseNum(a);
    a = a*10 + temp2;

    return a;
 }
int main(){

    int a = 23456;
    cout<<a<<endl;

    cout<<swapFirstANDLastDigit(a)<<endl;

return 0;
}