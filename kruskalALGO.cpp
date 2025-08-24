#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    //sbse pehle dsu wala code smae to same likhna h idhar
    vector<int> parent;
    vector<int> rank;
    //inka initialization yaha nhi ho skta bcs kuch main se abhi liya hi nhi h so baadme krenge ise

    int find(int i){
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y){
        int x_par = find(x);
        int y_par = find(y);

        if(x_par == y_par ) return;

        if(rank[x_par] > rank[y_par]){
            parent[y_par] = x_par;
        }else if (rank[y_par] > rank[x_par]){
            parent[x_par] = y_par;
        }else if (rank[y_par] == rank[x_par]){
            rank[y_par]++;
            parent[x_par]=y_par;
        }
    }



    int kruskal(vector<vector<int>>& edges, int V){
        //1. DEFINE RANK AND PARENT OF DSU
        rank.resize(V, 0);
        parent.resize(V);
        for(int i=0; i<V; i++) parent[i]=i;

        //2. SORT
        auto comprator = [&](vector<int> &edge1, vector<int>& edge2){
            return edge1[2]<edge2[2]; //sort hum weight ke basis pe krre h bcs ye kruskal algo ka algo/rule hai ki jo bhi chote w8s hai unhe pehle join kro(mathematically bhi ese hi krte h)
        };
        sort(edges.begin(), edges.end(), comprator); 


        //3. LOGIC
        int sum = 0;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            //u and v ke papa nikaallo
            int u_par = find(u);
            int v_par = find(v); 

            //agar dono ke papa same hue yaani ki vo khina khi se connected h to unhe connect krne ki no need
            if(u_par != v_par){
                Union(u_par,v_par);
                //union kro bcs connected hi nhi h and ab kyuki tum unhe connect krre ho to obv h ki sum me add bhi hoga unka w8
                sum+=w;
            }
        }


        return sum;
    }
};


int main(){
    int V,E;
    cin>>V;
    cin>>E;

    vector<vector<int>> edges;
    for(int i=0; i<V; i++){
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back({u,v,w});
    }

    Solution sol;
    cout<<sol.kruskal(edges, V);
}