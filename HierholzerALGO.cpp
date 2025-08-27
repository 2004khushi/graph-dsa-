//FIND EULER PATH ->

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        //1. adj list banao
        unordered_map<int, vector<int>> adj;

            //1.1initialize indegree and outdegree
            unordered_map<int, int> indegree, outdegree;
        
        for(auto &vec: pairs){
            int u = vec[0]; int v = vec[1];
            adj[u].push_back(v);

            outdegree[u]++;
            indegree[v]++;
        }
        
        
        //2. start node
        int startNode = pairs[0][0];
        for(auto &it : adj){
            int node = it.first;

            //2.1see logic from the picture of the graph
            if(outdegree[node] - indegree[node] == 1){
                startNode = node;
                break;
            }
        }


        //3. DFS
        stack<int> st;
        vector<int> EP;
        st.push(startNode);
        while(!st.empty()){
            int curr = st.top();
            //ye if statement hi dfs kraaega
            if(!adj[curr].empty()){
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }else{
                EP.push_back(curr);
                st.pop();
            }
        }


        //4. reverse 
        reverse(begin(EP), end(EP));

        //5. output show kro
        vector<vector<int>> ans;
        for(int i=0; i<EP.size()-1; i++){
            ans.push_back({EP[i], EP[i+1]});
        }

        return ans;
    }
}


int main() {
    int N;
    cin >> N;

    vector<vector<int>> pairs(N, vector<int>(2));
    for (int i = 0; i < N; i++) {
        cin >> pairs[i][0] >> pairs[i][1];
    }

    Solution sol;
    vector<vector<int>> answ = sol.validArrangement(pairs);

    for (auto &pair : answ) {
        cout << pair[0] << " " << pair[1] << endl;
    }
    return 0;
}
