#include <bits/stdc++.h>
using namespace std;

//topological sorting

void dfs(vector<vector<int>> &adj, int u, vector<bool> &visited, stack<int> &st){
    visited[u] = true;
    for(int &v: adj[u]){
        if(!visited[v] ){
            dfs(adj,v,visited,st);
        }
    }
    st.push(u);
}

vector<int> topologicaldfs(vector<vector<int>> &adj){
    int V = adj.size();
    vector<bool> visited(V, false);
    stack<int> st;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            dfs(adj,i,visited,st);
        }
    }
    
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

vector<int> topologicalbfs(vector<vector<int>> &adj){
    int V = adj.size();
    vector<int> indegree(V, false);
    vector<int> result;
    queue<int> que;
    
    for(int i=0; i<V; i++){
        for(int &v: adj[i]){
            indegree[v] ++;
        }
    }
    
    for(int i=0; i<V; i++){
        if(indegree[i] == 0){
            que.push(i);
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
            }
        }
    }
    
    return result;
}



int main() {
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
    
    cout<<"topo sort(dfs): ";
    vector<int> ans = topologicaldfs(adj);
    for(int i=0; i<V; i++){
        cout<<ans[i]<<" ";
    }
    
    cout<<"\n topo sort(bfs): ";
    vector<int> ans1 = topologicalbfs(adj);
    for(int i=0; i<V; i++){
        cout<<ans1[i]<<" ";
    }

}
