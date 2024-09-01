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

    vector<pair<int,int>> adjlist[vertex];

    int u,v,w;
    for(int i=0;i<edges;i++){
        cin>>u>>v>>w;
        if(u>vertex-1 || v>vertex-1){
            cout<<"The edges is greator then vertices plz reenter !!";
            i--;
            continue;
        }
        adjlist[u].push_back(make_pair(v,w));
    }

    cout<<"\n";

    for(int i=0;i<vertex;i++){
        cout<<i<<" -> ";
        for(int j=0;j<adjlist[i].size();j++){
            cout<<adjlist[i][j].first<<"-"<<adjlist[i][j].second<<" ";
        } cout<<endl;
    }


return 0;
}