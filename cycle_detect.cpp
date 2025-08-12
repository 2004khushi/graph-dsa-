#include <bits/stdc++.h>
using namespace std;


bool isCycleBFS(vector<vector<int>> &adj, int u, vector<bool>&visited){
    queue<pair<int,int>> que;
    que.push({u,-1});
    visited[u] = true;
    
    while(!que.empty()){
        pair<int, int> P = que.front();
        que.pop();
        
        int source = P.first;
        int parent = P.second;
        for(int &v: adj[source]){
            if(!visited[v]){
                que.push({v,source});
                visited[v] = true;
            }else if(v != parent){
                return true;
            }
        }
    }
    return false;
}

bool CycleDetectBFS(vector<vector<int>> &adj){
    int V = adj.size();
    vector<bool>visited(V, false);
    for(int i=0; i<V; i++){
        if(!visited[i] && isCycleBFS(adj,i,visited)){
            return true;
        }
    }
    return false;
}

bool isCycleDFS(vector<vector<int>> &adj, int u, vector<bool>&visited, int parent){
    visited[u] = true;
    for(int &v: adj[u]){
        if(v == parent) continue;
        if(visited[v]){
            return true;
        }
        if(isCycleDFS(adj,v,visited,u)) return true;
    }
    return false;
}

bool CycleDetectDFS(vector<vector<int>>& adj){
    int V = adj.size();
    vector<bool> visited(V, false);
    for(int i=0; i<V; i++){
        if(!visited[i] && isCycleDFS(adj,i,visited,-1)){
            return true;
        }
    }
    return false;
}

int main() {
	int edge;
	cin>>edge;
	int V;
	cin>>V;
	
	vector<vector<int>> adj(V);
	
	for(int i=0; i<edge; i++){
	    int u, v;
	    cin>>u>>v;
	    if(u>=0 && v>=0 && u<V && v<V){
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	    }
	}
	
	cout<<"\n is that bfscycle??? "<< (CycleDetectBFS(adj) ? "Cycle exists" : "No cycle") << endl;
	
	cout<<"\n is that dfscycle??? "<< (CycleDetectDFS(adj) ? "Cycle exists" : "No cycle") << endl;

}
