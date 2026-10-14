class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0;
        int r = 0;
        int k = 0;
        while(r < n){

            while(r+1 < n && nums[r] == nums[r+1]){
                r++;
            }

            swap(nums[r], nums[l]);
            l++;
            r++;
            k++;
        }

        return k;
    }
};