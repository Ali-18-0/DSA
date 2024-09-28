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

void Count_Sort(int *arr,int n,int exp){
    int count[10] = {0};

    for(int i=0;i<n;i++){
        int digit = (arr[i]/exp) % 10;
        count[digit]++;
    }

    for(int i=1;i<10;i++){
        count[i] += count[i-1];
    }

    int* ans = new int[n];
    for(int i=n-1;i>=0;i--){
        int digit = (arr[i]/exp) % 10;
        ans[--count[digit]] = arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i] = ans[i];
    }

    delete[] ans;
    
}

void Radix_Sort(int *arr,int n){
    int maxi = getmax(arr,n);

    for(int exp=1;maxi/exp > 0;exp *= 10){
        Count_Sort(arr,n,exp);
    }
}

void printf(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// TIME COMPLEXITY = O(n,k);


int main(){

    int arr[] = {2,6,7,3,1,5,6,2,1,7,9};
    printf(arr,11);
    Radix_Sort(arr,11);
    printf(arr,11);


return 0;
}