#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

    // Adjacent List  using STL LIST Weighted

class Graph{

    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void Addedges(int u,int v,int w,int direction){
        if(direction == 0){
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        } else if(direction == 1){
            adj[u].push_back(make_pair(v,w));
        }
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j.first<<"-"<<j.second<<",";
            } cout<<" END"<<endl;
        }
    }

};

int main(){
    Graph adj;
    int nodes,edges;
    cout<<"Enter number of nodes : ";
    cin>>nodes;
    cout<<"Enter number of edges : ";
    cin>>edges;

    int u,v,w;
    for(int i=0;i<edges;i++){
        cin>>u>>v>>w;
        adj.Addedges(u,v,w,0);
    }

    adj.print();


return 0;
}
//0 1 4 0 2 5 1 2 6 1 3 3 3 4 9 2 4 10