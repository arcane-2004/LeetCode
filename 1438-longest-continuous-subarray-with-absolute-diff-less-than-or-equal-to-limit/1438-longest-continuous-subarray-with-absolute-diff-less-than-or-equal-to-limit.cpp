class Solution {
public:

    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        multiset<int> st;

        int i = 0, j = 0;
        int ans = 0;

        while(j < n){
            st.insert(nums[j]);

            while(*st.rbegin() - *st.begin() > limit){
            
                st.erase(st.find(nums[i]));
                i++;
            }

            ans = max(ans, j-i+1);
            j++;

        }

        return ans;
        
    }
};