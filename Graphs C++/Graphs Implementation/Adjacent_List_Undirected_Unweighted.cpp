#include<iostream>
#include<vector>
using namespace std;

int main(){

    //Undirected Unweighted Graph

    int vertex,edges;
    cout<<"Enter Vector of graph ";
    cin>>vertex;
    cout<<"Enter Edges of graph ";
    cin>>edges;

    vector<int> adjlist[vertex];

    int u,v;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        if(u>vertex-1 || v>vertex-1){
            cout<<"The edges is greator then vertices plz reenter !!";
            i--;
            continue;
        }
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    cout<<"\n";

    for(int i=0;i<vertex;i++){
        cout<<i<<" -> ";
        for(int j=0;j<adjlist[i].size();j++){
            cout<<adjlist[i][j]<<" ";
        } cout<<endl;
    }


return 0;
}