#include<iostream>
using namespace std;

int partition (int arr[], int low, int high){
    int pivot = arr[low];
    int cnt = 0;

    for(int i=low+1;i<=high;i++){
        if(pivot >= arr[i]){
            cnt++;
        }
    }
    int pivotIndex = low+cnt;
    swap(arr[pivotIndex],arr[low]);

    int i=low,j=high;
    while(i < pivotIndex && j > pivotIndex){
        while(i < pivotIndex && arr[i] <= pivot){
            i++;
        }
        while(j > pivotIndex && arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
    }

void QuickSort(int arr[], int low, int high){
        if(low>=high){
        return;
    }

    int p = partition(arr,low,high);

    QuickSort(arr,low,p-1);
    QuickSort(arr,p+1,high);
    }

int main(){

int arr[]= {3,2,1,6,7,9,5};

for(int i=0;i<7;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
QuickSort(arr,0,6);

for(int i=0;i<7;i++){
    cout<<arr[i]<<" ";
}




return 0;
}