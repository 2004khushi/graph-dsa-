#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

void dfs_push(int u, stack<int>st, vector<vector<int>>& adj, vector<bool>& visited){
    visited[u]=true;
    for(auto &v: adj[u]){
        if(!visited[v]) dfs_push(v,st,adj,visited);
    }
    st.push(u);
}

void dfs_pop(int u, vector<vector<int>>& adj, vector<bool>& visited){
    visited[u]=true;
    for(auto &v: adj[u]){
        if(!visited[v]) dfs_push(v,adj,visited);
    }
}

int kosaraju(int V, vector<vector<int>>& adj){
    stack<int> st;
    vector<bool> visited(V,false);

    for(int i=0; i<V; i++){
        if(!visited[i]){
            dfs_push(i,st,adj,visited);
        }
    }

    vector<vector<int>> revAdj(V);
    for(int u=0; u<V; i++){
        for(auto& v:adj[u]){
            revAdj[v].push_back(u);
        }
    }

    int SCC = 0;
    visited = vector<bool>(V,false);
    while(!st.empty()){
        int i = st.pop();
        st.pop();

        if(!visited[i]){
            dfs_pop(i,revAdj,visited);
            SCC++;
        }
    }

    return SCC;
}


int main(){
    int V,E;
    cin>>V>>E;

    vector<vector<int>> adj(V);
    for(int i=0; i<V; i++){
        int u,v;
        cin>>u>>v;

        if(u>=0 && v>=0 && u<V && v<V){
            adj[u].push_back(v);
        } 
    }

    cout<<kosaraju(V,adj);
}