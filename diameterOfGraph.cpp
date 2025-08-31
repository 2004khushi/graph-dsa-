pair<int, int> BFS(unordered_map<int, vector<int>>& adj, int start) {
    queue<int> q;
    q.push(start);
    unordered_set<int> visited;
    visited.insert(start);

    int far = start;
    int dist = 0;

    while (!q.empty()) {
        int N = q.size();
        while (N--) {
            int curr = q.front();
            q.pop();
            far = curr; // the last node popped is the farthest

            for (auto& v : adj[curr]) {
                if (visited.find(v) == visited.end()) {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
        if (!q.empty()) dist++;
    }
    return {far, dist};
}

int findDiam(unordered_map<int, vector<int>>& adj) {
    if (adj.empty()) return 0;
    // Start from the first node in the map
    int startNode = adj.begin()->first;
    auto [farthestNode, dist] = BFS(adj, startNode);
    auto [otherNode, diam] = BFS(adj, farthestNode);
    return diam;
}

int giveDiameter(vector<vector<int>> edges) {
    unordered_map<int, vector<int>> adj;
    for (auto& e : edges) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return findDiam(adj);
}