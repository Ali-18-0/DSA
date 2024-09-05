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
            for(auto j:adj[i]){
                cout<<j<<" ";
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



void Topological_Sort(int v,vector<int> adj[]){
    vector<int> InDeg(v,0);
    for(int i=0;i<v;i++){
        for(auto j:adj[i]){
            InDeg[j]++;
        }
    }

    queue<int> q;
    for(int i=0;i<v;i++){
        if(InDeg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto i:adj[node]){
            InDeg[i]--;
            if(InDeg[i] == 0){
                q.push(i);
            }
        }
    }
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
    cout<<endl;

    Topological_Sort(node,g.ADJ());

return 0;
}
// node = 6 , edges = 7
//0 1 0 2 1 3 2 3 3 4 3 5 4 5