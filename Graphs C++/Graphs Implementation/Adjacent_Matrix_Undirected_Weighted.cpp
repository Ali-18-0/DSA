#include<iostream>
#include<vector>
using namespace std;

int main(){
    
        // Adjacent Matrix
        // Undirected weighted  graph

    int vertex,edges;
    cout<<"Enter Vector of graph ";
    cin>>vertex;
    cout<<"Enter Edges of graph ";
    cin>>edges;

    vector<vector<int>> adj(vertex,vector<int>(vertex,0));
    int u,v,w;
    for(int i=0;i<edges;i++){
        cin>>u>>v>>w;
        if(u>vertex-1 || v>vertex-1){
            cout<<"The edges is greator then vertices plz reenter !!";
            i--;
            continue;
        }
        adj[u][v] = w;
        adj[v][u] = w;
    }
    cout<<"\n";

    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<adj[i][j]<<" ";
        } cout<<endl;
    }

return 0;
}
//0 1 4 0 2 5 1 2 6 1 3 3 3 4 9 2 4 10
