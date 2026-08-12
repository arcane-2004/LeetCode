class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = INT_MAX;
        int profit = 0;

        for(int i: prices){

            mini = min(i, mini);

            int pro = i - mini;

            profit = max(pro, profit);
        }

        return profit;

    }
};