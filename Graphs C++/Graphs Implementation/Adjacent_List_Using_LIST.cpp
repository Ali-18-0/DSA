#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

    // Adjacent List  using STL LIST unweighted

class Graph{

    public:
    unordered_map<int,list<int>> adj;

    void Addedges(int u,int v,int direction){
        if(direction == 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else if(direction == 1){
            adj[u].push_back(v);
        }
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            } cout<<endl;
        }
    }

};

int main(){
    int nodes,edges;
    cout<<"Enter number of nodes : ";
    cin>>nodes;

    Graph adj;

    cout<<"Enter number of edges : ";
    cin>>edges;

    int u,v;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        adj.Addedges(u,v,1);
    }

    adj.print();


return 0;
}

//0 1 0 2 1 2 1 3 3 4 2 4