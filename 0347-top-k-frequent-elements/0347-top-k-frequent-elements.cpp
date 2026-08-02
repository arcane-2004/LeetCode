class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int i: nums){
            freq[i]++;
        }

        vector<pair<int, int>> v;

        for(auto i: freq){
            v.push_back({i.second, i.first});
        }

        sort(v.rbegin(), v.rend());



        

        vector<int> ans;
        int i=0;
        while(k--){

            ans.push_back(v[i].second);
            i++;
        }

        return ans;
    }
};