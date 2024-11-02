#include<iostream>
using namespace std;

int lps(string str) {
        int arr[str.size()] = {0};
        int pref = 0,suf = 1;
        while(suf<str.size()){
            if(str[pref] == str[suf]){
                arr[suf] = pref+1;
                pref++,suf++;
            } else {
                if(pref == 0){
                    arr[suf++] = 0;
                } else {
                    pref = arr[pref-1];
                }
            }
        }
        return arr[str.length()-1];
    }


int main(){

return 0;
}