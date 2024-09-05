#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    int node;
    vector<int>* adj;
    public:
    Graph(int node){
        this->node = node;
        adj = new vector<int>[node];
    }
    ~Graph(){
        delete[] adj;
    }

    vector<int>* ADJ(){
        return adj;
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
            cout<<i<<"-> ";
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            }cout<<endl;
        }
    }
    
};

bool BFS_Check(int vertex,vector<int> adj[],vector<bool> &visited){
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

bool BFS_Cycle_Detect(int v,vector<int> adj[]){
    vector<bool> visited(v,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(BFS_Check(i,adj,visited)){
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

    Graph g(node);
    int u,v;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.Edges(u,v,0);
    }
    g.Display();

    if(BFS_Cycle_Detect(node,g.ADJ())){
        cout<<"Cyclic";
    } else {
        cout<<"Not Cyclic";
    }

return 0;
}

//0 1 0 2 1 2 1 3 3 4 2 4