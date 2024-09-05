#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<unordered_map>
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
    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }cout<<endl;
        }
    }
};

void BFS(int n,unordered_map<int,list<int>> adj){
    queue<int> q;
    vector<bool> visited(n,0);
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
            }
        }
    } cout<<endl;
}

void DFS_Solved(int node,unordered_map<int,list<int>> adj,vector<bool> &visited){
    visited[node] = 1;
    cout<<node<<" ";

    for(auto i:adj[node]){
        if(!visited[i]){
            DFS_Solved(i,adj,visited);
        }
    }
}

void DFS(int n,unordered_map<int,list<int>> adj){
    vector<bool> visited(n,0);
    DFS_Solved(0,adj,visited);

}


int main(){ 

    Graph g;
    int node,edges;
    cout<<"Enter number of nodes : ";
    cin>>node;
    cout<<"Enter number of edges : ";
    cin>>edges;

    int u,v;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.Edges(u,v,0);
    }
    g.print();
    cout<<"\n\n";
    cout<<"BFS Traversal : ";
    BFS(node,g.adj);
    cout<<"DFS Traversal : ";
    DFS(node,g.adj);

return 0;
}