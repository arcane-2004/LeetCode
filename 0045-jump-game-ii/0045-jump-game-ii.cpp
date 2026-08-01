#include<algorithm>
#include<cmath>
class Solution {

    int solve(int id, vector<int>& nums, vector<int> &dp){
        int n = nums.size();
        if(id >= n-1){
            return 0;
        }

        long long mini = INT_MAX;

        if(dp[id] != -1){
            return dp[id];
        }

        for(int i=1; i <= nums[id] && (i+id) < n; i++){

            long long step = solve(i+id, nums, dp);
            mini = min(mini, (step + 1));

        }

        dp[id] = mini;
        return mini;
    }
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};