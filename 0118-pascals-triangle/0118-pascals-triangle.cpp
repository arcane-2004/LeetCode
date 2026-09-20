class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;

        int curr = 1;
        for(int i=1; i<=numRows; i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1; j<i; j++){
                curr = curr * (i-j);
                curr = curr / j;
                temp.push_back(curr);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};