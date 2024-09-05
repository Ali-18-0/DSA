#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class Graph{
    public:

    unordered_map<int,list<int>> adj;

    void Edges(int u,int v,int direction){
        if(direction == 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else if(direction == 1){
            adj[u].push_back(v);
        }
    }
    void Display(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" ";
            } cout<<endl;
        }
    }

};

bool CycleCheck(int node,int parent,unordered_map<int,list<int>> adj,vector<bool> &visited){
    visited[node] = 1;
    for(auto i:adj[node]){
        if(parent == i){
            continue;
        } if(visited[i] == 1){
            return 1;
        }
        if(CycleCheck(i,node,adj,visited)){
            return 1;
        }
    }
    return 0;
}

bool DFS_Cycle_Detect(int v,unordered_map<int,list<int>> adj){
    vector<bool> visited(v,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bool check = CycleCheck(i,-1,adj,visited);
            if(check){
                return 1;
            }
        }
    }
    return -1;
}

int main(){

    int node,edges;
    cout<<"Enter number of nodes : ";
    cin>>node;
    cout<<"Enter number of edges : ";
    cin>>edges;

    Graph g;
    int u,v;
    for(int i=0;i<node;i++){
        cin>>u>>v;
        g.Edges(u,v,0);
    }
    g.Display();

    if(DFS_Cycle_Detect(node,g.adj)){
        cout<<"YES";
    } else {
        "NO";
    }

return 0;
}

//0 1 0 2 1 2 1 3 3 4 2 4