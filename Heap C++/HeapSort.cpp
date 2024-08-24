#include<iostream>
using namespace std;


/*********************************************************************************/
void Heapify(int arr[],int size,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < size && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < size && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        Heapify(arr,size,largest);
    }
}

void HeapSort(int arr[],int size){

    for(int i=size/2-1;i>=0;i--){
        Heapify(arr,size,i);
    }

    int t = size;
    while(t>1){
    swap(arr[0],arr[t-1]);
    t--;
    Heapify(arr,t,0);
    }
}
/*********************************************************************************/

void checkHeapify(int arr[],int size){
    for(int i=size/2-1;i>=0;i--){
        Heapify(arr,size,i);
    }
}

void display(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

int main(){

    int arr[] = {3,2,5,6,1};
    int arr2[] = {3,2,5,6,1};
    display(arr,5);
    checkHeapify(arr2,5);
    display(arr2,5);
    cout<<"HEAP SORT : ";
    HeapSort(arr,5);
    display(arr,5);

return 0;
}