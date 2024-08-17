#include<iostream>
using namespace std;

void insertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j-=1;
        }
        arr[j+1] = key;
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
    insertionSort(arr,6);
    display_array(arr,6);

return 0;
}