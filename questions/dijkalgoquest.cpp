// Q) -> Shortest Path in Weighted undirected graph

#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

vector<int> detectPath(int m, int n, vector<vector<int>> &edges){
    vector<vector<int>> adj(n+1);
    for(auto &e: edges){
        int u = e[0];
        int v = e[1];
        int weight = e[2];
        adj[u].push_back({weight,v});
        adj[v].push_back({weight, u});
    }

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    vector<int> result(n+1, INT_MAX);
    result[1]=0;
    pq.push({0,1});

    //new add 
    vector<int> path; //this is the final vector which is the output
    //new add
    vector<int> parent(n+1); //this is for storage of kon pappa hai bhai tumhara taaki hum output me papao ke through n se 1 tak phuch paae
    for(int i=1; i<=n; i++){
        parent[i]=i;
    }

    
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto &v: adj[node]){
            int dist = v.first;
            int adjnode = v.second;

            if(d+dist < result[adjnode]){
                result[adjnode] = d+dist;
                pq.push({d+dist, adjnode});
                //new add
                parent[adjnode]=node; //new papa to yahi change hoke aata hai
            }
        }
    }

    //new add
    //what if path hi nhi bana koi?, ye result use krre haiana apan, to ye use hi kyu hora h faaltu me time and space khaara
    //ab usage dikhega tumhe iska
    if(result[n] == INT_MAX){
        return {-1};
    }

    //new add
    while(parent[n] != n) {
        path.push_back(n);
        n = parent[n];
    }
    path.push_back(1); //ye basically bolra ki jabtak tumhare papa tum khud hi ho esa nhi aajata hai tab tak chlte rho(and ye tab hoga jab 1 aayega)

    //path chappa to ulta hai
    reverse(path.begin(), path.end());

    return path;
}


int main(){
    int m, n;
    cin>>m; //no. of edges
    cin>>n; //no. of nodes 

    vector<vector<int>> edges;

    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u v w;
        if(u>=1 && v>=1 && u<=n && v<=n){
            edges.push_back({u,v,w});
        }
    }

    vector<int> ans = detectPath(m,n,edges);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}