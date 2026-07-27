class Solution {
    bool solve(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &pathVisited, int check[], vector<vector<int>>& graph){

        visited[src] = 1;
        pathVisited[src] = 1;
        check[src] = 0;

        for(int i: graph[src]){
            if(!visited[i]){
                bool ch = solve(i, visited, pathVisited, check, graph);
                if(ch){
                    check[i] = 0;
                    return true;
                }
            }

            else if(pathVisited[i]){
                check[i] = 0;
                return true;
            }
        }

        check[src] = 1;
        pathVisited[src] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        unordered_map<int, bool> visited;
        unordered_map<int, bool> pathVisited;

        int check[n];
        vector<int> safe;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                solve(i, visited, pathVisited, check, graph);
            }
        }

        for(int i=0; i<n; i++){
            if(check[i]){
                safe.push_back(i);
            }
        }

        return safe;
    }
};