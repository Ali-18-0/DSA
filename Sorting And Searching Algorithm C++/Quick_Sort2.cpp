#include<iostream>
using namespace std;

// int partition2(int *arr,int low,int high){
//     int pivot = arr[high];
//     int pos = low-1;

//     for(int i=low;i<high;i++){
//         if(arr[i] <= pivot){
//             swap(arr[i],arr[++pos]);
//         }
//     }
//     swap(arr[pos+1],arr[high]);
//     return pos+1;
// }
int partition(int *arr,int low,int high){
    int pivot = arr[high];
    int pos = low;

    for(int i=low;i<=high;i++){
        if(arr[i] <= pivot){
            swap(arr[i],arr[pos++]);
        }
    }

    return pos-1;
}

void sort(int *arr,int low,int high){
    if(low>=high)
     return;

    int pivot = partition(arr,low,high);

    sort(arr,low,pivot-1);
    sort(arr,pivot+1,high);
}

void Quick_Sort(int *arr,int n){
    int low = 0;
    int high = n-1;
    sort(arr,low,high);
}

void Print_Arr(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
    cout<<endl;
}
int main(){

    int arr[] = {9,1,8,2,7,3,6,4,5};
    Print_Arr(arr,9);
    Quick_Sort(arr,9);
    Print_Arr(arr,9);


return 0;
}