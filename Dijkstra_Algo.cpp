#include <iostream>
using namespace std;
#include<queue>
#include<vector>
#include<climits>


vector<int> dijkstra_minheap(int V, vector<vector<int>>& edges, int src){

    //sbse adj list banani h so->
    vector<vector<pair<int,int>>> adj(V);
    for(auto &e: edges){
        int u = e[0];
        int v = e[1];
        int weight = e[2];
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }

    //ab main start hoga ->
    //to sbse pehle kn bas jo jo ds cahhiye vo sab define krna h
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //ye pq h min_heap ke liye
    vector<int> result(V,INT_MAX); //initially infinite hota h sabme
    result[src] = 0; //common sense

    //ab bfs ke tarah chlna hai
    //sbse pehle bhro kuch q me
    pq.push({0, src}); //{weight,destination}


    //ab whi while loop and usme pop krne se pehle save krlo chije
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto& v: adj[node]){ //ab us node ko hi to explore krke uske andar ghuste jaana h
            int dist = v.second;
            int adjnode = v.first;

            //ab bhrna kese h and kab in queue again?
            //obv jab new distance to reach that adjnode is if lesser than what's already inside then u push [rmmbr the logic we used to apply in our copie stoo]
            if( (d+dist) < result[adjnode]){
                resul[adjnode] = d+dist;
                pq.push({d+dist, adjnode});
            }
        }
    }

    return result;
    
}


//apan same chij set se krenge to save time bcs isme apan vo {6,0} jise waapis iterate krna padra tha vo del krdungi bcs isme erase feature hota h and pq me nhi hota vo
vector<int> dijkstra_set(int V, vector<vector<int>>& edges, int src){
    vector<vector<pair<int,int>>> adj(V);
    for(int &e: edges){
        int u = e[0];
        int v = e[1];
        int weight = e[2];

        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }


    set<pair<int,int>> st;
    vector<int> result(V,INT_MAX);
    result[src] = 0;

    st.insert({0,src});
    while(!st.empty()){
        auto &it = *st.begin();
        int d = it.first;
        int node = it.second;
        st.erase(it);

        for(auto& v: adj[node]){
            int dist = v.second;
            int adjnode = v.first;

            if(d+dist < result[adjnode]){
                if(result[adjnode] != INT_MAX){
                    st.erase({result[adjnode], adjnode});
                }
                result[adjnode] = d+dist;
                st.insert({d+dist, adjnode});
            }
        }
    }
}

int main(){
    int V,src,edgenumber;
    cin>>V;
    cin>>src;
    cin>>edgenumber;

    vector<vector<int>> edges;
    for(int i =0; i<edgenumber; i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        if(u>=0 && v>=0 && u<V && v<V ){
            edges.push_back({u,v,weight});
        }
    }

    vector<int> ans = dijkstra_minheap(V,edges,src);
    for(int i=0; i<V; i++){
        cout<< ans[i]<<" ";
    }
}