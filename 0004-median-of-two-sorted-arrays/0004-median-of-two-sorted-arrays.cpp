class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int idx1 = (n1+n2)/2 - 1;
        int idx2 = (n1+n2)/2;
        int l = 0, r = 0;
        int k = 0;
        int ele1, ele2;

        while(l < n1 && r < n2){
            if(nums1[l] <= nums2[r]){
                if(k == idx1){
                    ele1 = nums1[l];
                }
                else if(k == idx2){
                    ele2 = nums1[l];
                }
                k++;
                l++;
            }
            else{
                if(k == idx1){
                    ele1 = nums2[r];
                }
                else if(k == idx2){
                    ele2 = nums2[r];
                }
                k++;
                r++;
            }
        }

        while(l < n1){
            if(k == idx1){
                ele1 = nums1[l];
            }
            else if(k == idx2){
                ele2 = nums1[l];
            }
            k++;
            l++;
        }

        while(r < n2){
            if(k == idx1){
                ele1 = nums2[r];
            }
            else if(k == idx2){
                ele2 = nums2[r];
            }
            k++;
            r++;
        }

        if((n1+n2) % 2 == 1){
            return ele2;
        }
        else{
            double d = (ele1 + ele2) / 2.0;
            return d;
        }
    }
};