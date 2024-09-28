#include<iostream>
#include<cmath>
using namespace std;

bool Jump_Search(int *arr,int n,int key){
    int temp = sqrt(n);
    int start = 0;
    int end = temp;

    while(arr[end] <= key && end < n){
        start = end;
        end += temp;
        if(end > n-1){
            end = n;
        }
    }

    for(int i=start;i<end;i++){
        if(arr[i] == key){
            return true;
        }
    }
    return false;
    
}
void printArray(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){

    int arr[] = {1,3,4,5,7,8,9};
    printArray(arr,7);
    if(Jump_Search(arr,7,2)){
        cout<<"Elemnt founded";
    } else {
        cout<<"Element not found";
    }


return 0;
}