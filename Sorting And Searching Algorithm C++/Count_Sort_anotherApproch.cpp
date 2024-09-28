#include<iostream>
#include<climits>
using namespace std;

int getmax(int *arr,int n){
    int max1 = INT_MIN;
    for(int i=0;i<n;i++){
        max1 = max(arr[i],max1);
    }
    return max1;

}

void count_Sort(int *arr,int n){
    int max1 = getmax(arr,n);

    int count[max1+1] = {0};

    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<max1+1;i++){
        count[i] += count[i-1];
    }

    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--count[arr[i]]] = arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i] = ans[i];
    }

}
void printf(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// TIME COMPLEXITY = O(n + m);

int main(){

    int arr[7] = {2,5,4,1,2,6,34};
    printf(arr,7);
    count_Sort(arr,7);
    printf(arr,7);
    

return 0;
}