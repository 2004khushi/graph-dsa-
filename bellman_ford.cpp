#include<iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:

    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int src){
        vector<int> result(V,INT_MAX);
        result[src] = 0;

        for(int i=1; i<=V-1; i++){
            for(auto &edge: edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if(result[u]!= INT_MAX && result[u]+wt < result[v] ){
                    result[v] = result[u]+wt;
                }
            }
        }

        //negative cycle ke liuye ->
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(result[u]!= INT_MAX && result[u]+wt < result[v] ){
                    return {-1};
            }
        }

        return result;
    }
};


int main(){
    int V,E,src;
    cin>>V;
    cin>>E;
    cin>>src;

    vector<vector<int>> edges;
    
    for(int j=0; j<E; j++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }

    Solution sol;
    vector<int> ans = sol.bellman_ford(V, edges, src);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

}