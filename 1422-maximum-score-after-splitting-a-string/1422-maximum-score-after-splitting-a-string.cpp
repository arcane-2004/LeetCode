class Solution {

    int solve(string s, int n){

        int len = s.size();

        int ones = 0;
        for(int i=n+1; i<len; i++){
            if(s[i] == '1'){
                ones += 1;
            }
        }

        int zeros = 0;
        for(int i=0; i<=n; i++){
            if(s[i] == '0'){
                zeros += 1;
            }
        }

        return ones + zeros;
    }
    
public:
    int maxScore(string s) {
        
        int n = s.size()-1;

        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int cur = solve(s, i);
            ans = max(cur, ans);
        }

        return ans;
    }
};