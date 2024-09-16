#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void Count_Sort(int *arr,int size){
    int max = INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }

    vector<int> newarr(max+1,0);
    for(int i=0;i<size;i++){
        newarr[arr[i]]++;
    }
    int index = 0;
    for(int i=0;i<=max;i++){
        while(newarr[i]>0){
            arr[index++] = i;
            newarr[i]--;
        }
    }
    
}

int main(){
    int size;
    cin>>size;
    
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter "<<i+1<<" Element : ";
        cin>>arr[i];
    }
    Count_Sort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

return 0;
}