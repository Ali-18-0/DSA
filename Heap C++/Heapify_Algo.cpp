#include<iostream>
using namespace std;

//                                      MAX HEAPIFY
/******************************************************************************************/
// for 1 index

void heapify_solve(int arr[],int size,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= size && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= size && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify_solve(arr,size,largest);
    }
}

void Heapify_MAX(int arr[],int size){
    for(int i=size/2;i>0;i--){
        heapify_solve(arr,size,i);
    }
}
/******************************************************************************************/
// for 0 Indexing

void heapify_solve2(int arr[],int size,int i){
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
        heapify_solve2(arr,size,largest);
    }
}

void Heapify_MAX2(int arr[],int size){
    for(int i=size/2-1;i>=0;i--){
        heapify_solve2(arr,size,i);
    }
}

/******************************************************************************************/
//                                      MIN HEAPIFY
/******************************************************************************************/
// for 1 indexing

void heapify_solve3(int arr[],int size,int i){
    int smallest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= size && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right <= size && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify_solve3(arr,size,smallest);
    }
}

void Heapify_MIN(int arr[],int size){
    for(int i=size/2;i>0;i--){
        heapify_solve3(arr,size,i);
    }
}



/******************************************************************************************/
// for 0 indexing

void heapify_solve4(int arr[],int size,int i){
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < size && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < size && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify_solve4(arr,size,smallest);
    }
}

void Heapify_MIN2(int arr[],int size){
    for(int i=size/2-1;i>=0;i--){
        heapify_solve4(arr,size,i);
    }
}

/******************************************************************************************/

// printing array form 1 index
void displayARRAY(int *arr,int n){
    for(int i=1;i<=n;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}
// printing array form 0 index
void displayARRAY2(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

int main(){

    int arr[] = {-1,54,53,55,52,50};
    int arr2[] = {54,53,55,52,50};
    int arr3[] = {-1,54,53,55,52,50};
    int arr4[] = {54,53,55,52,50};
    // displayARRAY(arr,5);
    cout<<"Heapify_MAX with 1 indexing : ";
    Heapify_MAX(arr,5);
    displayARRAY(arr,5);

    cout<<"Heapify_MAX with 0 indexing : ";
    Heapify_MAX2(arr2,5);
    displayARRAY2(arr2,5);

    cout<<"Heapify MIN with 1 indexing : ";
    Heapify_MIN(arr3,5);
    displayARRAY(arr3,5);

    cout<<"Heapify_MAX with 0 indexing : ";
    Heapify_MIN2(arr4,5);
    displayARRAY2(arr4,5);


return 0;
}