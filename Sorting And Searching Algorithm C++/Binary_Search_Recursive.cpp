#include<iostream>
using namespace std;

int solve(int* arr,int s,int e,int key){

    if(s>e){
        return -1;
    }

    int mid = s + (e-s)/2;

    if(arr[mid] == key){
        return mid;
    }

    if(arr[mid]<key){
        return solve(arr,mid+1,e,key);
    } else {
        return solve(arr,s,mid-1,key);
    }
}

int Binary_Search_Recursive(int *arr,int size,int key){
    
    int s = 0;
    int e = size -1;

    return solve(arr,s,e,key);
}

int main(){

    int arr[] = {1,2,3,4,5,6,7};

    int find = Binary_Search_Recursive(arr,sizeof(arr)/sizeof(arr[0]),7);
    if(find == -1){
        cout<<"Key not found ";
    } else {
        cout<<"Key found at "<<find<<" index ";
    }
return 0;
}