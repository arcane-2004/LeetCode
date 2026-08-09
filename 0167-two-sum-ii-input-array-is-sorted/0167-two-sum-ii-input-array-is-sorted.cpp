class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int r = numbers.size()-1;
        int l = 0;
        vector<int> ans(2);
        while(l<r){
            int sum = numbers[l] + numbers[r];
            if(sum == target){
                ans[0] = (l+1);
                ans[1] = (r+1);
                break;
            }

            else if(sum > target) r--;
            else l++;
        }

        return ans;
    }
};