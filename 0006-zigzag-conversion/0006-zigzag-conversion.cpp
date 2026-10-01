class Solution {
public:
    string convert(string s, int numRows) {
        if( numRows == 1) return s;
        int n = s.length();

        string ans = "";
        
        int inc = (numRows - 1) * 2;
        for(int i=0; i<numRows; i++){
            
            int st = i;
            while(st < n){
                ans += s[st];
                if(i != 0 && i != numRows-1 && (st+inc) - 2*i <= n-1){
                    ans += s[(st+inc) - 2*i];
                }
                st += inc;
            }
        }

        return ans;
    }
};