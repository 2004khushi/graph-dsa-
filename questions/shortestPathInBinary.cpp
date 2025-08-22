#include<bits/stdc++.h>
using namespace std;

// class Solution {
//     public:

//     vector<vector<int>> directions {
//         {0,1},
//         {1,0},
//         {1,1},
//         {-1,0},
//         {-1,-1},
//         {-1,1},
//         {1,-1},
//         {0,-1},
//     };

//     int shortestPathInBinaryMatrix(vector<vector<int>>& grid){
//         int m = grid.size();
//         int n = grid[0].size();

//         //base case
//         if(m==0 || n == 0|| grid[0][0] == 1){
//             return -1;
//         }

//         auto isSafe = [&](int x, int y){
//             return (x>=0 && y>=0 && x<m && y<n);
//         };

//         queue<pair<int,int>> que;
//         que.push({0,0});
//         grid[0][0]=1;

//         int level = 1;
//         while(!que.empty()){
//             int N = que.size();
//             while(N--){
//                 auto curr = que.front();
//                 que.pop();
//                 int x = curr.first;
//                 int y = curr.second;

//                 //need to end this when ->
//                 if(x == m-1 && y == n-1) return level;

//                 for(auto dir : directions){
//                     int x_ = x+dir[0];
//                     int y_ = y+dir[1];

//                     if(isSafe(x_,y_) && grid[x_][y_]==0){
//                         que.push({x_,y_});
//                         grid[x_][y_]=1;
//                     }
//                 }
//             }
//             level++;
//         }
//         return -1;
//     }
// };


//u can use -> dijkstra method too to solve it -> 

class Solution {
public:

typedef pair<int, pair<int,int>>P;

vector<vector<int>> directions = {
    {0,1},
    {1,0},
    {1,1},
    {-1,0},
    {0,-1},
    {-1,-1},
    {1,-1},
    {-1,1}
};


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m, vector<int>(n,INT_MAX));

        //base case
        if(m==0 || n==0 || grid[0][0] == 1){
            return -1;
        }
        if(m==1 && n==1) return 1;

        auto isSafe = [&](int x, int y){
            return (x>=0 && y>=0 && x<m && y<n);
        };

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,{0,0}});
        result[0][0]=0;

        while(!pq.empty()){
            int dist = pq.top().first;
            auto curr = pq.top().second;
            int x = curr.first;
            int y = curr.second;
            pq.pop();

            for(auto &dir: directions){
                int x_ = x+dir[0];
                int y_ = y+dir[1];
                int d = 1;

                if(isSafe(x_,y_) && grid[x_][y_]==0 && d+dist < result[x_][y_]){
                    result[x_][y_] = d+dist;
                    pq.push({(d+dist),{x_,y_}});
                }
            }
        }

        return (result[m-1][n-1] == INT_MAX)? -1 : (result[m-1][n-1]+1);

    }
};



int main(){
    int rows,cols;
    cin>>rows;
    cin>>cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    // rows is the size of the grid vector
    // inside this grid, cols vector bhra hua h
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>grid[i][j];
        }
    }

    Solution sol;
    int ans = sol.shortestPathInBinaryMatrix(grid);
    cout<<ans;
    
}