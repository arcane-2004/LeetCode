class Solution {
    bool solve(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &pathVisited, unordered_map<int, list<int>> &adj){

        visited[src] = 1;
        pathVisited[src] = 1;

        for(auto i: adj[src]){
            if(!visited[i]){
                bool check = solve(i, visited, pathVisited, adj);
                if(check){
                    return true;
                }
            }
            else if(pathVisited[i]){
                return true;
            }
        }
        pathVisited[src] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        unordered_map<int, list<int>> adj;
        for(int i=0; i<n ; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> pathVisited;


        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(solve(i, visited, pathVisited, adj)){
                    return false;
                }
            }
        }

        return true;
    }
};