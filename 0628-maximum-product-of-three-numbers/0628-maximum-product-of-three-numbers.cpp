class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int a = INT_MIN;
        int b = INT_MIN;
        int c = INT_MIN;

        for(int i: nums){
            if(i > a){
                c = b;
                b = a;
                a = i;
            }
            else if(i > b){
                c = b;
                b = i;
            }
            else if(i > c){
                c = i;
            }
        }

        int l = INT_MAX;
        int m = INT_MAX;

        for(int i: nums){
            if(i < l){
                m = l;
                l = i;
            }
            else if(i < m){
                m = i;
            }
        }

        return max((a*b*c), (l*m*a));
    }
};