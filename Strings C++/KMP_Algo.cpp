#include<iostream>
using namespace std;

void lps(string needle,int arr[]){
    int pref = 0,suf = 1;
    arr[0] = 0;
    while(suf < needle.size()){
        if(needle[pref] == needle[suf]){
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
    return;
}
int strStr(string haystack, string needle) {
    int arr[needle.size()];
    lps(needle,arr);
    int first = 0,second = 0;
    while(first < haystack.size() && second < needle.size()){
        if(haystack[first] == needle[second]){
            first++,second++;
        } else {
            if(second == 0){
                first++;
            } else {
                second = arr[second-1];
            }
        }
    }
    if(first == haystack.size()){
        return -1;
    }
    return first-second;
}

int main(){

return 0;
}