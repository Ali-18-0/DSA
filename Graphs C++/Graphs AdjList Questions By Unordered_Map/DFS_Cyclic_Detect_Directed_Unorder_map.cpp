#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> adj;

    void edges(int u,int v,int direction){
        if(direction == 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else if(direction == 1){
            adj[u].push_back(v);
        }
    }
    void display(){
        for(auto i:adj){
            cout<<i.first<< "-> ";
            for(auto j:i.second){
                cout<<j<<" ";
            }cout<<endl;
        }
    }

};

void DFS_Solved(int node,unordered_map<int,list<int>> adj,vector<bool> &visited){
    visited[node] = 1;
    cout<<node<<" ";
    for(auto i:adj[node]){
        if(!visited[i]){
            DFS_Solved(i,adj,visited);
        }
    }
}

void DFS(int v,unordered_map<int,list<int>> adj){
    vector<bool> visited(v,0);
    DFS_Solved(0,adj,visited);
}

bool DFS_Check_UD(int node,int parent,unordered_map<int,list<int>> adj,vector<bool> &visited){
    visited[node] = 1;
    for(auto i:adj[node]){
        if(i == parent){
            continue;
        }
        if(visited[i]){
            return 1;
        }
        if(DFS_Check_UD(i,node,adj,visited)){
            return 1;
        }
    }
    return 0;
}

bool DFS_Cycle_Detect_UD(int v,unordered_map<int,list<int>> adj){
    vector<bool> visited(v,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(DFS_Check_UD(i,-1,adj,visited)){
                return 1;
            }
        }
    }
    return 0;
}

bool DFS_Check_D(int node,unordered_map<int,list<int>> adj,vector<bool> &dfs_visited,vector<bool> &visited){
    visited[node] = 1;
    dfs_visited[node] = 1;
    for(auto i:adj[node]){
        if(!visited[i]){
            if(DFS_Check_D(i,adj,dfs_visited,visited)){
                return 1;
            }
        } else if(dfs_visited[i]){
            return 1;
        }
    }
    dfs_visited[node] = 0;
    return 0;

}

bool DFS_Cycle_Detect_D(int v,unordered_map<int,list<int>> adj){
    vector<bool> visited(v,0);
    vector<bool> dfs_visited(v,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(DFS_Check_D(i,adj,dfs_visited,visited)){
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
        g.edges(u,v,1);
    }
    g.display();

    DFS(node,g.adj);

    if(DFS_Cycle_Detect_D(node,g.adj)){
        cout<<"Cyclic";
    } else {
        cout<<"Acyclic";
    }

return 0;
}
//0 1 0 2 1 2 1 3 3 4 2 4 acyclic
//0 1 1 2 2 0 1 3 3 4 2 4 cyclic

//1 2 2 3 2 4 3 7 3 8 4 5 5 6 6 4 8 7