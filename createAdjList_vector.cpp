#include <iostream>
#include <vector>
using namespace std;

//ab baat krte hai apan ki addedge fn kese bnega so->
void addEdge(vector<vector<int>>& adj, int u, int v){
    adj[u].push_back(v); // jese u 0 hai to bhai 0 waala jo tha mera adj wahape ab 1 daalo vo us new vector me smjhre? see that graph
    adj[v].push_back(u); //undriected h to bhai dono side ghusega
}

void print(vector<vector<int>> adj, int v){
    //obv do loop chlane pdenge hi apan ko
    for(int i=0; i<v; i++){
        cout << i << " -> "; // Print the current vertex
        for(auto x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

//to sabse pehle hum dekheneg int main me kese kaam hora hai ok
//so see 
int main(){
    int u=4;
    int v = u; //ek esa graph banari me jisme me 4 vertex leri and 4 hi edge bhi leri, and undirected graph h abhi ye
    vector<vector<int>> adj(v); //me vector leri to represent my adj list. bascially 2d wala vcetor hoga ye
    //so like [0,1,2,3] -> vertex and unke saath connected hai unki connected vertex so kuch esa matrix form of vector hoga->
/* [0, -> [1,2] // abhi ye sab link kiya nhi h mene, bas overview deri hu ki esa banega kuch
     1, -> [0,2]
     2, -> [0,1,3]
     3, -> [2]
    ]
*/
    addEdge(adj,0,1); //ye edge jodne ke liye h
    addEdge(adj,1,2);
    addEdge(adj,0,2);
    addEdge(adj,2,3);

    print(adj,v);
    return 0;
}


