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
            if(u>= node || v>=node || u<0 || v<0){
                cout<<"Inavlid input ";
            } else {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        } else if(direction == 1){
            if(u>= node || v>=node || u<0 || v<0){
                cout<<"Inavlid input ";
            } else {
                adj[u].push_back(v);
            }
        }
    }

    void display(){
        for(int i=0;i<node;i++){
            cout<<i<<" -> ";
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            } cout<<endl;
        }
    }
};

bool DFS_Solved(int node,vector<int> adj[],vector<bool> &visited,int parent){
    visited[node] = 1;
    for(auto i:adj[node]){
        if(parent == i){
            continue;
        } if(visited[i] == 1){
            return 1;
        }
        if(DFS_Solved(i,adj,visited,node)){
            return 1;
        }
    }
        return 0;
}

bool DFS(int v,vector<int> adj[]){
    vector<bool> visited(v,0);
    int parent = -1;
    for(int i=0;i<v;i++){
            if(!visited[i]){
                // bool check = DFS_Solved(i,adj,visited,-1);
                // if(check){
                    // return 1;
                // }
                if(DFS_Solved(i,adj,visited,-1)){
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
    cout<<"\nPrinting Adjacent List : \n";
    g.display();

    if(DFS(node,g.ADJ())){
        cout<<"YES";
    } else {
        cout<<"NO";
    }

return 0;
}