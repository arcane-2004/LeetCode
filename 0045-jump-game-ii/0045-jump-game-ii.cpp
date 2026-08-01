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
        vector<long long> dp(n, INT_MAX);

        dp[0] = 0;

        for(int j=0; j<n; j++){
       

            for(int i=1; i <= nums[j] && (i+j) < n; i++){

                dp[i+j] = min(dp[i+j], dp[j] + 1);

            }
        }

        return dp[n-1];
    }
};