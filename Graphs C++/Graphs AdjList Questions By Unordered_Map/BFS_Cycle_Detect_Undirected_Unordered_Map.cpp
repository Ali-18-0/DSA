#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
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
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" ";
            }cout<<endl;
        }
    }
    
};

bool DFS_Check(int vertex,unordered_map<int,list<int>> adj,vector<bool> &visited){
    queue<pair<int,int>> q;
    visited[vertex] = 1;
    q.push(make_pair(vertex,-1));
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto i:adj[node]){
            if(i == parent){
                continue;
            }
            if(visited[i]){
                return 1;
            }
            visited[i] = 1;
            q.push(make_pair(i,node));
        }
    }
    return 0;
}

bool DFS_Cycle_Detect(int v,unordered_map<int,list<int>> adj){
    vector<bool> visited(v,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(DFS_Check(i,adj,visited)){
                return 1;
            }
        }
    }
    return 0;
}

int main(){

    int node,edges;
    cout<<"Enter number of nodes : ";
    cin>>node;
    cout<<"Enter number of edges : ";
    cin>>edges;
    Graph g;
    int u,v;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.Edges(u,v,0);
    }
    g.Display();

    if(DFS_Cycle_Detect(node,g.adj)){
        cout<<"Cyclic";
    } else {
        cout<<"Not Cyclic";
    }

return 0;
}
//0 1 0 2 1 2 1 3 3 4 2 4