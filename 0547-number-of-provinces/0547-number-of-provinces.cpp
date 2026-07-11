class Solution {

void solve(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
    queue<int> q;

    visited[src] = 1;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i: adj[node]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        unordered_map<int, list<int>> adj;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                }
            }
        }

        unordered_map<int, bool> visited;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                cnt++;
                solve(i, visited, adj);
            }
        }

        return cnt;
    }
};