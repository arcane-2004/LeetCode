class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size();
        int maxi = INT_MIN;
        for(int i: candies){
            maxi = max(i, maxi);
        }

        int sub = maxi - extraCandies;

        vector<bool> ans(n);

        for(int i=0; i<n; i++){
            if(candies[i] >= sub){
                ans[i] = true;
            }
            else{
                ans[i] = false;
            }
        }

        return ans;
    }
};