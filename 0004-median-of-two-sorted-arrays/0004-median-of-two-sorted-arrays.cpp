class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        int l = 0, r = 0;
        vector<int> ans;

        while(l < n1 && r < n2){
            if(nums1[l] <= nums2[r]){
                ans.push_back(nums1[l++]);
            }
            else{
                ans.push_back(nums2[r++]);
            }
        }

        while(l < n1){
            ans.push_back(nums1[l++]);
        }

        while(r < n2){
            ans.push_back(nums2[r++]);
        }

        int n = ans.size();
        if(n % 2 == 1){
            return ans[n/2];
        }
        else{
            double d = 1.0 * (ans[(n-1)/2] + ans[n/2]) / 2;
            return d;
        }
    }
};