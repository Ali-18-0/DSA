#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adj;

    void edges(int u,int v,int direction){
        if(direction == 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }else if(direction == 1){
            adj[u].push_back(v);
        }
    }

    void Display(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" ";
            }cout<<endl;
        }
    }
};


bool BFS_Cycle_Detect(int v, unordered_map<int,list<int>> adj){
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
    int cnt = 0;
    while(!q.empty()){
        int node =  q.front();
        cnt++;
        q.pop();
        for(auto i:adj[node]){
            InDeg[i]--;
            if(InDeg[i] == 0){
                q.push(i);
            }
        }
    }
    if(cnt == v){
        return false;
    }
    return true;
}

int main(){

    int node,edges;
    cout<<"Enter number of nodes : ";
    cin>>node;
    cout<<"Enter number of edges : ";
    cin>>edges;

    Graph g;
    int u,v;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.edges(u,v,1);
    }

    g.Display();

    cout<<endl;

    if(BFS_Cycle_Detect(node,g.adj)){
        cout<<"Cyclic";
    } else {
        cout<<"Acyclic";
    }

return 0;
}

// node = 6 , edges = 7
//0 1 0 2 1 3 2 3 3 4 3 5 4 5