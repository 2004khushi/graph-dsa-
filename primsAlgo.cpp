#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    typedef pair<int,int> P;
    public:
    int mst(vector<vector<int>> &edges, int V){

        //sbse pehle to dekho ki bhai EDGE AAYA HAI naaki adj list
        
        //1. ADJ LIST CREATION
        vector<vector<P>> adj(V);
        for(auto &edge :edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }

        //2. PRIM'S ALGO 
        priority_queue< P, vector<P>, greater<P>> pq;
        pq.push({0,0});
        vector<bool> visited(V,false);
        int sum = 0;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int wt = p.first;

            if(visited[node]) continue;
            visited[node] = true;
            sum+=wt;

            for(auto &v: adj[node]){
                int node1 = v.second;
                int node1_wt = v.first;

                if(!visited[node1]){
                    pq.push({node1_wt,node1});
                }
            }
        }
        return sum;
    }
};

int main(){
    int V, E;
    cin>>V;
    cin>>E;

    vector<vector<int>> edges;
    for(int i=0; i<E; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }

    Solution sol;
    cout<<sol.mst(edges, V);
}