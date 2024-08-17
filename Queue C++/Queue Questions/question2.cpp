#include<iostream>
#include<vector>
using namespace std;

void check(int arr[],int size,int k){
    vector<int> v;
    int s=0,n=0;
    for(int i=0;i<size;i++){
        int t=0;
        while((t+i)<(k+i)){
            if((k+i)>size){
                break;
            }
            if(arr[t+i]<0){
                v.push_back(arr[t+i]);
                break;
            } else {
                if((t+i)==(k+i)-1){
                    v.push_back(0);
                }
            }
            t++;
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}

int main(){

    int arr[5] = {-2,3,5,-6,10};
    check(arr,5,2);

return 0;
}