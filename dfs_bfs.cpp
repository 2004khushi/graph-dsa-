// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<int> &result){
    if(visited[u] == true){
        return;
    }
    visited[u] = true;
    result.push_back(u);
    for(int &v: adj[u]){
        if(!visited[v]){
            DFS(adj, v, visited, result);
        }
    }
}

void BFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<int> &result){
    queue<int> que;
    que.push(u);
    visited[u] = true;
    result.push_back(u);
    
    while(!que.empty()){
        int u = que.front();
        que.pop();
        
        for(int &v: adj[u]){
            if(!visited[v]){
                que.push(v);
                visited[v] = true;
                result.push_back(v);
            }
            
        }
    }
}


vector<int> detectBFS (vector<vector<int>> &mp){
    unordered_map<int, vector<int>>adj;
    int V = mp.size();
    for(int u=0; u<V; u++){
        for(auto it=mp[u].begin(); it!=mp[u].end(); it++){
            adj[u].push_back(*it);
        }
    }   
    
    vector<bool> visited(V, false);
    vector<int> result;
        
    BFS(adj,0,visited,result);
    
    return result;
    
}

vector<int> detectDFS (vector<vector<int>> &mp){
    unordered_map<int, vector<int>>adj;
    int V = mp.size();
    for(int u=0; u<V; u++){
        for(auto it=mp[u].begin(); it!=mp[u].end(); it++){
            adj[u].push_back(*it);
        }
    }   
    
    vector<bool> visited(V, false);
    vector<int> result;
        
    
    DFS(adj,0,visited, result);
    return result;
   
}



int main() {
    int num_nodes;
    cout << "Enter the number of nodes in the graph: ";
    cin >> num_nodes;
    vector<vector<int>> mp(num_nodes); 

    int num_edges;
    cout << "Enter the number of edges: ";
    cin >> num_edges;

    cout << "Enter the edges (source destination, e.g., 0 1):" << endl;
    for (int i = 0; i < num_edges; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < num_nodes && v >= 0 && v < num_nodes) {
            mp[u].push_back(v);
            mp[v].push_back(u); 
        } else {
            cout << "Invalid node(s) for edge " << u << " " << v << ". Nodes must be between 0 and " << num_nodes - 1 << "." << endl;
            i--; 
        }
    }

    // Capture and print BFS result
    cout << "\nBFS Traversal:" << endl;
    vector<int> bfs_result = detectBFS(mp);
    for (int node : bfs_result) {
        cout << node << " ";
    }
    cout << endl;

    // Capture and print DFS result
    cout << "\nDFS Traversal:" << endl;
    vector<int> dfs_result = detectDFS(mp);
    for (int node : dfs_result) {
        cout << node << " ";
    }
    cout << endl;

   

    return 0;
    
    
    
    
    
}