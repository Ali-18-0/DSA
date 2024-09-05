#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    int node;
    vector<int> *adj;

    public:

    Graph(int size){
    node = size;
    adj = new vector<int>[node];
    }
    Graph(){
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
    void display(){
        for(int i=0;i<node;i++){
            cout<<i<<"-> ";
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            }cout<<endl;
        }
    }

    vector<int>* adjacent(){
        return adj;
    }
};
/*********************************************************************************/
// BFS TRAVERSAL
void BFS(int n,vector<int> adj[]){
    queue<int> q;
    vector<int> visited(n,0);
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                visited[adj[node][i]] = 1;
                q.push(adj[node][i]);
            }
        }
    }
    cout<<endl;
}
/*********************************************************************************/
//DFS TRAVERSAL

void DFS_Solve(int node,vector<int> adj[],vector<bool> &visited){
    visited[node] = true;
    cout<<node<<" ";
    // for(int i=0;i<adj[node].size();i++){
    for(auto i:adj[node]){
        
        if(!visited[i]){
            DFS_Solve(i,adj,visited);
        }
    }
}

void DFS(int n,vector<int> adj[]){
    vector<bool> visited(n,false);
    DFS_Solve(3,adj,visited);
}
/*********************************************************************************/

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
        if(u>node || v>node){
            cout<<"Invalid input Re-Enter ";
            i--;
            continue;
        }
        g.Edges(u,v,0);
    }
    cout<<"\nPrinting Adjacent List : \n";
    g.display();
    cout<<endl;

    cout<<"BFS Traversal : ";
    BFS(node,g.adjacent());
    
    cout<<"DFS Traversal : ";
    DFS(node,g.adjacent());

return 0;
}
//0 1 0 2 1 2 1 3 3 4 2 4