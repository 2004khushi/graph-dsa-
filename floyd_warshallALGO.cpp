#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &grid) {
        int n = grid.size();
        int INF = 100000000;
        
        for(int k=0; k<n; k++){
            //ye loop to h ki bhai jo each via ke liye banana haina pura chittha uska hai ye
            //vhi ki via 0 se har jagah kese phuch skte ho pehle unsbka likho then via 1 se hr jgh phucne me kya w8 lgega vo nikaalna h sbka
            
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    //row and col humesha same hi rhenge as per question
                    if (grid[i][k] != INF && grid[k][j] != INF) {
                        grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                    }
                    //via jaa jaake agar chota raasta aara h to vo krdo uski value vrna jo h vhi rehndo 
                }
            }
        }
    }
};

int main(){
    int V;

    cin>>V;
    vector<vector<int>> grid(V, vector<int>(V));

    for(int i=0;i<V; i++){
        for(int j=0; j<V; j++){
            cin>>grid[i][j];
        }
    }

    Solution sol;
    sol.floydWarshall(grid);
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}