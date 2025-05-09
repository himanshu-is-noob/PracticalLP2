#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj) {
    vis[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node]) 
        if (!vis[neighbor]) dfs(neighbor, vis, adj);
}

void bfs(int start, vector<vector<int>>& adj) {
    vector<bool> vis(adj.size(), false);
    queue<int> q;
    q.push(start);
    vis[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 5;  // Number of vertices
    vector<vector<int>> adj(n);
    
    // Undirected edges
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    
    cout << "DFS: ";
    vector<bool> vis(n, false);
    dfs(0, vis, adj);
    
    cout << "\nBFS: ";
    bfs(0, adj);
    
    return 0;
}