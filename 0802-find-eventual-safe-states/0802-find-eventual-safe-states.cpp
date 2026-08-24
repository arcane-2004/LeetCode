class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int e = graph.size();
        unordered_map<int, list<int>> adj;
        for(int i=0; i<e; i++){
            int v = i;
            for(int u: graph[i]){
                adj[u].push_back(v);
            }
        }

        
        unordered_map<int, bool> visited;
        vector<int> indegree(e, 0);

        queue<int> q;

        for(int i=0; i<e; i++){
            for(int a: adj[i]){
                indegree[a]++;
            }
        }

        for(int i=0; i<e; i++){
            if(indegree[i] == 0){
                q.push(i);
               
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);

            for(int i: adj[top]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }

        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};