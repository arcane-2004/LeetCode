class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int m = k;
        for(int i=0; i<n; i++){
            
            if(nums[i] % k == 0){
                if(m == nums[i]){
                    m += k;
                }
                else if(m > nums[i]){
                    continue;
                }
                else{
                    return m;
                } 
            }
        }

        return m;
    }
};