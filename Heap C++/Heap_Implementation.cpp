#include<iostream>
using namespace std;

//                                  Max Heap Implemenation 
/****************************************************************************************/

class heap{
    int arr[100];
    int size;
    public:

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int d){
        size++;
        int index = size;
        arr[index] = d;

        while(index > 1){
            int parent = index/2;
            if(arr[index] > arr[parent]){
                swap(arr[index],arr[parent]);
                index = parent;
            } else {
                return;
            }
        }
    }
    void deleteFromHeap(){
        if(size == 0){
            cout<<"Heap is Empty\n";
            return;
        }
        arr[1] = arr[size];
        size--;

        int i=1;
        while(i<size){
            int leftnode = 2*i;
            int rightnode = 2*i+1;

            if(leftnode<=size && arr[i] < arr[leftnode]){
                swap(arr[i],arr[leftnode]);
                i = leftnode;
            } else if(rightnode<=size && arr[i] < arr[rightnode]){
                swap(arr[i],arr[rightnode]);
                i = rightnode;
            } else {
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }
};
/****************************************************************************************/
//                                    Max Heap Implemenation
/****************************************************************************************/


class Heap2{
    int arr[100];
    int size;
    public:
    Heap2(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int d){
        size++;
        int index = size;
        arr[index] = d;

        while(index>1){
            int parent = index/2;

            if(arr[parent] > arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deleteFromHeap(){
        if(size == 0){
            cout<<"Nothing to delete form Heap\n";
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i<size){
            int leftnode = 2*i;
            int rightnode = 2*i+1;

            if(leftnode<=size && arr[leftnode]< arr[i]){
                swap(arr[leftnode],arr[i]);
                i = leftnode;
            } else if(rightnode<=size && arr[rightnode]< arr[i]){
                swap(arr[rightnode],arr[i]);
                i = rightnode;
            } else {
                return;
            }
        }
    }

    void display(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

/****************************************************************************************/
//                       Implementation of MAX Heap by 0 indexing
/****************************************************************************************/

class Heap3{
    int arr[100];
    int size;
    public:
    Heap3(){
        size = -1;
    }

    void insert(int d){
        size++;
        int index = size;
        arr[index] = d;

        while(index>0){
            int parent = (index-1)/2;
            if(arr[index] > arr[parent]){
                swap(arr[parent],arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deleteFromHeap(){
        if(size == -1){
            cout<<"Nothing to Delete\n";
            return;
        }

        arr[0] = arr[size];
        size--;

        int i=0;
        while(i<size){
            int large = i;
            int left = 2*i+1;
            int right = 2*i+2;
            if(left<=size && arr[left] > arr[large]){
                swap(arr[large],arr[left]);
                large = left;
            } else if(right<=size && arr[right] > arr[large]){
                swap(arr[right],arr[large]);
                large = right;
            } else {
                return;
            }
        }
    }
    void display(){
        for(int i=0;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
/****************************************************************************************/
//                              Implementation of MAX Heap by 0 indexing
/****************************************************************************************/

class Heap4{
    int arr[100];
    int size;
    public:
    Heap4(){
        size = -1;
    }

    void insert(int d){
        size++;
        int index = size;
        arr[index] = d;

        while(index>0){
            int parent = (index-1)/2;
            if(arr[index] < arr[parent]){
                swap(arr[parent],arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deleteFromHeap(){
        if(size == -1){
            cout<<"Nothing to Delete\n";
            return;
        }

        arr[0] = arr[size];
        size--;

        int i=0;
        while(i<size){
            int large = i;
            int left = 2*i+1;
            int right = 2*i+2;
            if(left<=size && arr[left] < arr[large]){
                swap(arr[large],arr[left]);
                large = left;
            } else if(right<=size && arr[right] < arr[large]){
                swap(arr[right],arr[large]);
                large = right;
            } else {
                return;
            }
        }
    }
    void display(){
        for(int i=0;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

/****************************************************************************************/


int main(){

    heap h;
    Heap2 h2;
    Heap3 h3;
    Heap4 h4;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    

    h.print();
    cout<<endl;
    h.deleteFromHeap();
    // h.deleteFromHeap();
    h.print();
    cout<<"\n\n";

    h2.insert(50);
    h2.insert(55);
    h2.insert(53);
    h2.insert(52);
    h2.insert(54);
    h2.display();
    h2.deleteFromHeap();
    h2.display();

    cout<<"\n\n";

    h3.insert(50);
    h3.insert(55);
    h3.insert(53);
    h3.insert(52);
    h3.insert(54);
    h3.display();
    h3.deleteFromHeap();
    h3.display();

    cout<<"\n\n";

    h4.insert(50);
    h4.insert(55);
    h4.insert(53);
    h4.insert(52);
    h4.insert(54);
    h4.display();
    h4.deleteFromHeap();
    h4.display();


return 0;
}