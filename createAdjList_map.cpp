#include <iostream>
#include<list>

#include<unordered_map>
using namespace std;
template <typename T>

//hota to isme bhi whi hi hai, same vesa hi graph bnega jesa usme tha, bas isme map ke sahayaata se chije stroe hongi rather then by the vector in vector
class graph{
    public:
    unordered_map<T, list<T>> adj;
    void addEdge(T u, T v, bool direction){
        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto i: adj){ //ye h tumhara map
            cout<<i.first<<"->"<<" ";   //i.first tumhe tumhara int wala part dega(the vetrices)
            for( auto j: i.second){  //i.second tumhe tumhara jo vo list h vo batayegi
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"enter the vertices ";
    cin>>n;
    
    int m;
    cout<<"enter the edges ";
    cin>>m;

    graph<int> g; //yaha hum graph g; hi likhte if wouldnt had used template<typename T>
    for(int i =0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    g.print();
}