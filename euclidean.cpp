// return 1 if u find EP
// return 2 if find EC
//return 0 if none

//DFS
void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited){
    visited[u] = true;
    for(auto &v: adj[u]){
        if(!visited[v]) DFS(v,adj,visited);
    }
}

//2. define isConnected
bool isConnected(vector<vector<int>>& adj, int V){
    //2.1 so we check this by dfsing on one of teh nonzeroNode, so just get 1 nonZero node dont find all -> SAVE TIME
    int nonzeroNode = -1;
    for(int i=0; i<V; i++){
        if(adj[i].size() !=0){
            nonzeroNode = i; //jitna size utna hi uska degree h obviosuly
            break; //SAVE TIME
        }
    }

    //2.2 obv ab dfs krenge uspe
    vector<bool> visited(V,false);
    DFS(nonzeroNode, adj,visited);

    //2.3 ab check krenge ki bhai konse hisso me false aara bcs false aane pe bhi do raasta h yato EP ya none
    for(int i=0; i<V; i++){
        if(!visited[i] && adj[i].size()>0){
            return false;
        }
    }

    return true;
}


int euler(int V, vector<vector<int>>& adj){

    //1. check for the different components of graph
    //if they all connected or not or there're diff components and so
    if(!isConnected(adj,V)) return 0;

    //3. logic of odd degree
    int oddDegreeNodes = 0;
    for(int i=0; i<V; i++){
        if(adj[i].size()%2 != 0 ){
            oddDegreeNodes++;
        }
    }

    if(oddDegreeNodes > 2) return 0; //bhai agar 2 se jyada odddegree waale nodes dikhgye terko to bhai obv kn h wahape
    else if (oddDegreeNodes == 2) return 1; // agar ekdum 2 hi h to EP hai.

    return 2; //ab ek hi or rasta bacha ki 2 se kum nodes hai jinke odddegree h yaani ki EC bnega
}


int main(){
    int E,V;
    cin>>V>>E;

    vector<vector<int>> adj(V);
    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<euler(V,adj);
}