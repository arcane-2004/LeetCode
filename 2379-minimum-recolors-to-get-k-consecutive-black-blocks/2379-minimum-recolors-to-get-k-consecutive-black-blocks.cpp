class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int n = blocks.size();
        int ans = INT_MAX;
        int cnt = 0;

        int l = 0;

        for(int r=0; r<n; r++){

            if(blocks[r] == 'W'){
                cnt++;
            }

   
            while((r-l+1) > k){
                if(blocks[l] == 'W'){
                    cnt--;
                }
                l++;
            }

            if(k == r-l+1){
                ans = min(ans, cnt);
            }

        }

        return ans;
    }
};