#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    int arr[] = {1,2,3,4,2,5,1,3,6,1};

    unordered_map<int,int> it;
    for(int i=0;i<10;i++){
        it[arr[i]]++;
    }
    int maxi = 0;
    int index = 0;
    for(auto i:it){
        if(i.second > maxi){
            maxi = i.second;
            index = i.first;
        }
    }

    cout<<"The "<<index<<" number has more occureces in array with "<<maxi<<" counts "<<endl;
    // cout<<it[1]<<endl;


    int arr2[] = {11,2,3,4,6,1,3,6};
    unordered_map<int,int> itt;
    maxi = 0;
    int maxfre = 0;
    for(int i=0;i<8;i++){
        itt[arr2[i]]++;
        maxfre = max(maxfre,itt[arr2[i]]);
    }
    for(int i=0;i<8;i++){
        if(itt[arr2[i]] == maxfre){
            maxi = arr2[i];
            break;
        }
    }
    cout<<"Most frequecy number of lowest index is : "<<maxi<<" with "<<maxfre<<" counts"<<endl;
    cout<<itt[3]<<endl;
return 0;
}