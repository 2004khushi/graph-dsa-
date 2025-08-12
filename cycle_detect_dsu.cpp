#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
     if(i == parent[i]){
        return i;
     }

     return parent[i] = find(parent[i]);
    }

    void Union(int x, int y){
     int x_par = find(x);
     int y_par = find(y);

     if(x_par == y_par){
        return;
     }
     if(rank[x_par]>rank[y_par]){
        parent[y_par] = x_par;
     }else if(rank[x_par]<rank[y_par]){
        parent[x_par] = y_par;
     }else if(rank[x_par] == rank[y_par]){
        rank[x_par]++;
        parent[y_par] = x_par;
     }
    }


//ye upar wala to saara same hi h dsu waala hi code h, sem to sem

    int detectCycle(int V, vector<vector<int>> &adj){
     parent.resize(V);
     rank.resize(V);
    //size batana jruri h vrna seg error aayega
    //and also inko fill bhi krna h and
     for(int i=0; i<V; i++){
            //starting me kya hota tha? 
            //ki sabki rank to 0 hai and parent sbka vo khud hi h
        parent[i] = i;
        rank[i] = 0;
     }

    //ab jo humne logic nikala tha vo lagayenge loop me
     for(int u=0; u<V; u++){
        for(int &v: adj[u]){
            if(u<v){
                int u_par = find(u);
                int v_par = find(v);

                if(u_par == v_par){
                    return true;
                }else {
                    Union(u,v); //graph banana haina 
                }
            }
        }
     }

     return false;
    }
};


int main(){
    int V,edge;
    cin>>V;
    cin>>edge;
    vector<vector<int>> adj(V);

    for(int i=0; i<edge; i++){
        int u,v;
        cin>>u>>v;
        if(u<V && v<V && u>=0 && v>=0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    Solution sol;  // Need to create an instance of Solution
    cout << "Cycle hai? " << (sol.detectCycle(V, adj) ? "Yes" : "No");
}