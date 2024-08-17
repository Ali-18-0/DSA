#include<iostream>
#include <vector>
using namespace std;
#include<cstring>;

void merge(int *arr,int start,int mid,int end){
    int* temp = new int[end - start + 1];
    
    int left = start;
    int right = mid + 1;
    int index = 0;

    while(left<=mid && right<=end){
        if(arr[left]<=arr[right]){
            temp[index] = arr[left];
            left++;
            index++;
        } else {
            temp[index] = arr[right];
            right++;
            index++;
        }
    }

    while(left<=mid){
        temp[index] = arr[left];
        left++;
        index++;
    }
    while(right<=end){
        temp[index] = arr[right];
        right++;
        index++;
    }

    index = 0;
    while(start<=end){
        arr[start] = temp[index];
        start++;
        index++;
    }

    delete[] temp;
}

void MergeSort(int *arr,int start,int end){
    if(start<end){
        int mid = start +(end-start)/2;
        // int mid = (start+end)/2;
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
    

}
/************************************************************************/

// Merge sort by using vector

void mergee2(int arr[],int s,int mid,int e){
    vector<int> arrr;
    int left = s;
    int right = mid+1;

    while(left<=mid && right<=e){
        if(arr[left]>arr[right]){
            arrr.push_back(arr[right]);
            right++;
        } else {
         arrr.push_back(arr[left]);
         left++;   
        }
    }

    while(left<=mid){
        arrr.push_back(arr[left]);
        left++;
    }
    while(right<=e){
        arrr.push_back(arr[right]);
        right++;
    }
    int size = 0;
    while(s<=e){
        arr[s] = arrr[size];
        s++;
        size++;

    }

}

void mergesort2(int arr[],int s, int e){
    
    if(s<e){
        int mid = s + (e-s)/2;
        mergesort2(arr,s,mid);
        mergesort2(arr,mid+1,e);
        mergee2(arr,s,mid,e);
    }
}
/******************************************************************************* */

int main(){
    int size;
    cout<<"Enter size of array : ";
    cin>>size;
    int arr[size];

    for(int i = 0; i<size; i++){
        cout<<"Enter element no. "<<i+1<<" : ";
        cin>>arr[i];
    }
    // int len = sizeof(arr)/sizeof(arr[0]);


    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    MergeSort(arr,0,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

return 0;
}