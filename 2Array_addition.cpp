#include<iostream>
using namespace std;

void swapdigit(int &a,int &b){
    int temp = b;
        b = a;
        a = temp;
}

void reverseArr(int arr[],int size){
    int s = 0;
    int e = size-1;
    while(s<e){
        swapdigit(arr[s],arr[e]);

        s++;
        e--;
    }
}

int reversedigit(int a){
    int result = 0;
    int temp = a;
    while(temp!=0){
        result = result*10 + temp%10;
        temp = temp/10;
    }
    return result;
    
}

int add(int arr1[],int arr2[],int size1,int size2){

    int i=0,j=0;

    reverseArr(arr1,size1);
    reverseArr(arr2,size2);

    int result=0;
    int carry=0;

    while(i<size1 && j<size2){
        int sum = arr1[i] + arr2[j] +carry;
        int digit = sum%10;
        result = result*10 + digit;
        carry = sum/10;
        i++;
        j++;
    }
    while(i<size1){
        int sum = arr1[i] +carry;
        int digit = sum%10;
        result = result*10 + digit;
        carry = sum/10;
        i++;
    }
    while(j<size2){
        int sum = arr2[j] +carry;
        int digit = sum%10;
        result = result*10 + digit;
        carry = sum/10;
        j++;
    }
    reverseArr(arr1,size1);
    reverseArr(arr2,size2);
    result = reversedigit(result);

    return result;

};

int main(){

    int a = 12345;
    // cout<<reversedigit(a);

    int arr1[] = {2,3,4,5};
    int arr2[] = {2,3,4,5,6,7};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int result = add(arr1,arr2,size1,size2);
    cout<<"{"<<arr1[0];
    for(int i=1;i<size1;i++){
        cout<<","<<arr1[i];
    }
    cout<<"} + {"<<arr2[0];

    for(int i=1;i<size2;i++){
        cout<<","<<arr2[i];
    }

    cout<<"} = ";
    cout<<result<<endl;

return 0;
}