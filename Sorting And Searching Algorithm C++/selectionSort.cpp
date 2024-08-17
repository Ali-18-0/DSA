#include<iostream>
using namespace std;

void selection_sort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j = i+1;j<size;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

void selection_sort3(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}
void selection_sort2(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minnum = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[minnum] > arr[j]) {
                minnum = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[minnum];
        arr[minnum] = arr[i];
        arr[i] = temp;
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
    // insertionSort(arr,6);
    selection_sort(arr,6);
    display_array(arr,6);

return 0;
}