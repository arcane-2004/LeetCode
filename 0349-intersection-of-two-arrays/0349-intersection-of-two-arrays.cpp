class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> mp;

        for(int i: nums1){
            mp[i] = 1;
        }

        vector<int> ans;
        for(int i: nums2){
            if(mp[i]){
                ans.push_back(i);
                mp[i] = 0;
            }
        }

        return ans;
    }
};