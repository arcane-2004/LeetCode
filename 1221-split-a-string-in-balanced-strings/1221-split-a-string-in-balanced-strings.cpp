class Solution {
public:
    int balancedStringSplit(string s) {
        
        int cnt = 0;

        int l = 0; 
        int r = 0;
        for(char c: s){
            if(c == 'L'){
                l++;
            }
            else{
                r++;
            }

            if(l == r){
                cnt++;
                l = 0;
                r = 0;
            }
        }

        return cnt;
    }
};