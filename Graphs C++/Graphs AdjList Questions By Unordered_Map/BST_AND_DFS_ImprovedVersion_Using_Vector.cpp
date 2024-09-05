#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph {
    int node;
    vector<vector<int>> adj;  // Using vector of vectors to manage memory automatically

public:
    // Constructor
    Graph(int size) : node(size), adj(size) {}

    // Function to add edges
    void addEdge(int u, int v, bool isDirected = false) {
        if (u >= node || v >= node || u < 0 || v < 0) {
            cout << "Invalid input: Node indices should be between 0 and " << node - 1 << endl;
            return;
        }
        adj[u].push_back(v);
        if (!isDirected) {
            adj[v].push_back(u);
        }
    }

    // Function to display the adjacency list
    void display() const {
        for (int i = 0; i < node; i++) {
            cout << i << " -> ";
            for (int j : adj[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    // Function to return the adjacency list
    const vector<vector<int>>& getAdjList() const {
        return adj;
    }
};

// BFS function (renamed from BST to BFS)
void BFS(int startNode, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> visited(n, 0);
    queue<int> q;

    q.push(startNode);
    visited[startNode] = 1;

    cout << "BFS Traversal starting from node " << startNode << ": ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void DFS_Solved(int node,vector<vector<int>> adj,vector<bool> &visited){
    visited[node] = 1;
    cout<<node<<" ";
    for(auto i:adj[node]){
        if(!visited[i]){
            DFS_Solved(i,adj,visited);
        }
    }
}

void DFS(int n,vector<vector<int>> adj){
    vector<bool> visited(n,0);
    DFS_Solved(0,adj,visited);
}

int main() {
    int node, edges;
    cout << "Enter number of nodes: ";
    cin >> node;
    cout << "Enter number of edges: ";
    cin >> edges;

    Graph g(node);

    int u, v;
    for (int i = 0; i < edges; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        g.addEdge(u, v);  // By default, it adds undirected edges
    }

    g.display();
    cout << endl;

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    if (startNode >= 0 && startNode < node) {
        BFS(startNode, g.getAdjList());
    } else {
        cout << "Invalid starting node." << endl;
    }

    cout << "BFS Traversal starting from node " << startNode << ": ";
    if (startNode >= 0 && startNode < node) {
        DFS(startNode, g.getAdjList());
    } else {
        cout << "Invalid starting node." << endl;
    }

    return 0;
}
