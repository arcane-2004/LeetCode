class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color (n, -1);

        queue<int> q;

        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                q.push(i);
                color[i] = 0;

                while(!q.empty()){
                    int top = q.front();
                    q.pop();

                    for(int i : graph[top]){
                        if(color[i] == -1){
                            color[i] = !color[top];
                            q.push(i);
                        }

                        else if(color[i] == color[top]){
                            return false;
                        }
                    }
                }
            }
        }
        

        return true;
    }
};