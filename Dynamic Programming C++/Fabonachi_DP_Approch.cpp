#include<iostream>
using namespace std;
// Dynamic Programming
//  Recursive + Memorization + Tabulation + Space Optimization
int Fabo_Fantastic(int n){
    if(n<=1)
        return n;
    int a = 1;
    int b = 0;
    int r = 0;
    for(int i=2;i<=n;i++){
        r = a + b;
        b = a;
        a = r;
    }
    return r;
    // T.P = O(n) , S.P = O(1)
    // Recursive + Tabulation + Space Optimization
}

int fabo_Good(int n,int dp[]){
    if(n<=1)
        return n;
    
    if(dp[n] != -1)
        return dp[n];

    dp[n] = fabo_Good(n-1,dp) + fabo_Good(n-2,dp);
    return dp[n];
    // T.P = O(n) , S.P = O(n) + O(n)
    //Recursive + Memorization
}

int fabo_Best(int n){
    if(n<=1)
        return n;

    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    return dp[n];
    // T.P = O(n) , S.P = O(n)
    // Recursive + Tabulation
}

int fabo_Worst(int n){
    if(n<=1)
        return n;
    
    return fabo_Worst(n-1) + fabo_Worst(n-2);
    // T.P = O(2^n) , S.P = O(n)
    // Recursive Only Worst Approch
}

int main(){

int n = 10;
int dp[n+1];
for(int i=0;i<=n;i++){
    dp[i] = -1;
}

for(int i=0;i<10;i++){
    cout<<fabo_Worst(i)<<" ";
}

return 0;
}
