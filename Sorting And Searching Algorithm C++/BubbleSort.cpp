#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void display_array(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){

int arr[6] = {6,5,8,4,1,3};
    display_array(arr,6);
    BubbleSort(arr,6);
    display_array(arr,6);

return 0;
}