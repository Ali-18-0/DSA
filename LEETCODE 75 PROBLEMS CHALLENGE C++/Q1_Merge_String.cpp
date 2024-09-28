#include<iostream>
using namespace std;

string mergeAlternately(string word1, string word2) {
        int size1 = word1.length();
        int size2 = word2.length();
        string newword = "";

        int i=0,j=0;
        while(i<size1 && j<size2){
            // if(i==j){
            //     newword += word1[i++];
            // } else if(i != j){
            //     newword += word2[j++];
            // }
                newword += word1[i++];
                newword += word2[j++];

        }
        while(i<size1){
                newword += word1[i++];
        }
        while(j<size2){
                newword += word2[j++];
        }
    return newword;
    }
    // TIME COMPLEXITY = O(n+m)

int main(){
    string a = "abc";
    string b = "pqr";
    string merge = mergeAlternately(a,b);
    cout<<merge;

return 0;
}