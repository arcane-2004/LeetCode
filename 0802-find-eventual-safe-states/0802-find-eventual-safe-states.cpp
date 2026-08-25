class Solution {
    bool solve(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &pathVisited, vector<int> &checked, vector<vector<int>>& graph){

        visited[node] = 1;
        pathVisited[node] = 1;

        for(int i: graph[node]){
            if(!visited[i]){
                bool check = solve(i, visited, pathVisited, checked, graph);
                if(check){
                    return true; 
                }
            }
            else if(pathVisited[i]){
                return true;
            }
        }
        pathVisited[node] = 0;
        checked.push_back(node);
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        unordered_map<int, bool> visited;
        unordered_map<int, bool> pathVisited;
        vector<int> checked;

        for(int i=0; i<graph.size(); i++){

            if(!visited[i]){
                solve(i, visited, pathVisited, checked, graph);
            }
        }

        sort(checked.begin(), checked.end());

        return checked;
    }
};