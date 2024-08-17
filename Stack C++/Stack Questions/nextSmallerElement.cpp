#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> nextSmallest(vector<int> arr,int s){
    vector<int> ar(s);

    stack<int> st;
    st.push(-1);

    for(int i=s-1;i>=0;i--){
        while(st.top() >= arr[i]){
            st.pop();
        }
        ar[i] = st.top();
        st.push(arr[i]);
    }
    
    return ar;
}

int main(){

    vector<int> arr;
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);

    int size = arr.size();
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    vector<int> result = nextSmallest(arr,size);

    int size2 = result.size();
    for(int i=0;i<size;i++){
        cout<<result[i]<<" ";
    }

return 0;
}