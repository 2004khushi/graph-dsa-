#include <bits/stdc++.h>
using namespace std;


//detect cycle in directed graph

bool dfs(vector<vector<int>> &adj,int u,vector<bool>& visited, vector<bool> &isRecursion){
    visited[u] = true;
    isRecursion[u] = true;
    
    for(int &v: adj[u]){
        if(!visited[v] && dfs(adj,v,visited,isRecursion)){
            return true;
        }else if(isRecursion[v] == true){
            return true;
        }
    }
    
    isRecursion[u] = false;
    return false;
}

bool isCycledfs(vector<vector<int>> &adj){
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<bool> isRecursion(V, false);
    
    for(int i=0; i<V; i++){
        if(!visited[i] && dfs(adj,i,visited,isRecursion)){
            return true;
        }
    }
    return false;
}

bool isCyclebfs(vector<vector<int>> &adj){
    int V = adj.size();
    vector<int>result;
    
    int count = 0;
    
    queue<int> que;
    vector<int> indegree(V,0);
    
    for(int i=0; i<V; i++){
        for(int &v: adj[i]){
            indegree[v]++;
        }
    }
    
    for(int i=0; i<V; i++){
        if(indegree[i] == 0){
            que.push(i);
            count++;
        }
    }
    
    while(!que.empty()){
        int u = que.front();
        que.pop();
        result.push_back(u);
        
        for(int &v: adj[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                que.push(v);
                count++;
            }
        }
    }
    
    if(count == V) return false;
    return true;
    
}

int main(){
    int V, edge;
    cin>>V;
    cin>>edge;
    
    vector<vector<int>> adj(V);
    for(int i=0; i<V; i++){
        int u,v;
        cin>>u>>v;
        
        if(u>=0 && v>=0 && u<V && v<V){
            adj[u].push_back(v);
        }
    }
    
    cout<<"kya vo h directed cyclic (dfs) ? "<<(isCycledfs(adj))? "yes":"no";
    cout<<"\n kya vo h directed cyclic (bfs) ? "<<(isCyclebfs(adj))? "yes":"no";
    
}