#include<iostream>
using namespace std;

// Array must be sort if using binary search
int BinarySearch(int arr[],int size,int key){
    int start = 0;
    int end = size-1;

    int mid = (start+end)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }

        if(arr[mid]<key){
            start = mid+1;
        } else {
            end = mid-1;
        }

        mid = (start+end)/2;

    }
    return -1;
}

int main(){

int arr[6] = {2,4,7,9,11,14};

int keyvalue = BinarySearch(arr,6,11);
cout<<keyvalue;
cout<<endl;

    if(keyvalue==-1){
        cout<<"Value not found in array";
    } else {
        cout<<"Value found at index "<<keyvalue;
    }


return 0;
}