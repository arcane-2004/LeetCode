class Solution {
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(ind == 0){
            if(amount % coins[0] == 0){
                return amount/coins[0];
            }
            return 1e9;
        }

        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }

        int notTake = 0 + solve(ind-1, amount, coins, dp);
        int take = INT_MAX;
        if(coins[ind] <= amount){
            take = 1 + solve(ind, amount-coins[ind], coins, dp);
        }

        dp[ind][amount] = min(take, notTake);
        return dp[ind][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
        vector<vector<int>>dp (n, vector<int> (amount+1, 0));
        
        for(int amt = 0; amt <= amount; amt++){
            if(amt % coins[0] == 0) dp[0][amt] = amt/coins[0];
            else dp[0][amt] = 1e9;
        }

        for(int ind = 1; ind<n; ind++){
            for(int amt =0; amt <= amount; amt++){
                int notTake = 0 + dp[ind-1][amt];
                int take = INT_MAX;
                if(coins[ind] <= amt){
                    take = 1 + dp[ind][amt-coins[ind]];
                }

                dp[ind][amt] = min(take, notTake);
            }
            
        }

        int ans = dp[n-1][amount];

        if( ans >= 1e9) return -1;

        return ans;
    }
};