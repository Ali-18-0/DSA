#include<iostream>
#include<vector>
using namespace std;

class Graph{
    int node;
    vector<int>* adj;
    public:
    Graph(int node){
        this->node = node;
        adj = new vector<int>[node];
    }

    void Edges(int u,int v,int direction){
        if(direction == 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else if(direction == 1){
            adj[u].push_back(v);
        }
    }

    void Display(){
        for(int i=0;i<node;i++){
            cout<<i<<" -> ";
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            }cout<<endl;
        }
    }
    vector<int>* ADJ(){
        return adj;
    }
};

void DFS_Solve(int node,vector<int> adj[],vector<bool> &visited){
    visited[node] = 1;
    cout<<node<<" ";
    for(auto i:adj[node]){
        if(!visited[i]){
            DFS_Solve(i,adj,visited);
        }
    }
}
void DFS(int v,vector<int> adj[]){
    vector<bool> visited(v,0);
    DFS_Solve(0,adj,visited);
}

bool DFS_Check_UD(int node,int parent,vector<int> adj[],vector<bool> &visited){
    visited[node] = 1;
    for(auto i:adj[node]){
        if(parent == i){
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

bool DFS_Cycle_Detect_UD(int v,vector<int> adj[]){
    vector<bool> visited(v,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            int check = DFS_Check_UD(i,-1,adj,visited);
            if(check){
                return 1;
            }
        }
    }
    return 0;
}

bool DFS_Check_D(int node, vector<int> adj[], vector<bool> &dfs_visited, vector<bool> &visited) {
    visited[node] = true;
    dfs_visited[node] = true;

    for (auto i : adj[node]) {
        if (!visited[i]) {
            bool check = DFS_Check_D(i, adj, dfs_visited, visited);
            if (check) {
                return true;
            }
        } else if (dfs_visited[i]) {
            return true; 
        }
    }

    dfs_visited[node] = false;
    return false;
}

bool DFS_Cyclic_Detect_D(int v, vector<int> adj[]) {
    vector<bool> visited(v, false);
    vector<bool> dfs_visited(v, false);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (DFS_Check_D(i, adj, dfs_visited, visited)) {
                return true;
            }
        }
    }
    return false;
}



int main(){

    int node,edges;
    cout<<"Enter number of nodes : ";
    cin>>node;
    cout<<"Enter number of edges : ";
    cin>>edges;

    Graph g(node);
    int u,v;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.Edges(u,v,1);
    }

    g.Display();

    DFS(node,g.ADJ());

    if(DFS_Cyclic_Detect_D(node,g.ADJ())){
        cout<<"Cyclic";
    } else {
        cout<<"Acyclic";
    }


return 0;
}
//0 1 0 2 1 2 1 3 3 4 2 4 UN DFS
//0 1 2 0 1 2 1 3 3 4 2 4 D DFS CD
//1 0 0 2 1 2 1 3 3 4 2 4 D DFS CD

//1 2 2 3 2 4 3 7 3 8 4 5 5 6 6 4 8 7