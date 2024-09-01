#include<iostream>
#include<vector>
using namespace std;

int main(){

        // Adjacent Matrix
        // Undirected unweighted  graph

    int vertex,edges;
    cout<<"Enter Vector of graph ";
    cin>>vertex;
    cout<<"Enter Edges of graph ";
    cin>>edges;

    vector<vector<bool>> adj(vertex,vector<bool>(vertex,0));
    int u,v;
    
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        if(u>vertex-1 || v>vertex-1){
            cout<<"The edges is greator then vertices plz reenter !!";
            i--;
            continue;
        }
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<adj[i][j]<<" ";
        } cout<<endl;
    }
return 0;
}
//0 1 0 2 1 2 1 3 3 4 2 4