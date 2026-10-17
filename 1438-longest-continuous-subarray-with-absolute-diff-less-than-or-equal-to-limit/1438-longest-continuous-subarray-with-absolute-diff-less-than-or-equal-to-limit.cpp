class Solution {
public:
    typedef pair<int, int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<P> maxi;
        priority_queue<P, vector<P>, greater<P>> mini;

        int i = 0, j = 0;
        int ans = 0;

        while(j < n){
            maxi.push({nums[j], j});
            mini.push({nums[j], j});


            while(maxi.top().first - mini.top().first > limit){
                i = min(maxi.top().second, mini.top().second) + 1;

                while(maxi.top().second < i){
                    maxi.pop();
                }

                while(mini.top().second < i){
                    mini.pop();
                }
            }

            ans = max(ans, j-i+1);
            j++;

        }

        return ans;
        
    }
};