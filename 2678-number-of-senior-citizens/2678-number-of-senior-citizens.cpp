class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int cnt=0;
        int age = 0;
        for(auto p: details){
            int a = p[11] - '0';    
            int b = p[12] - '0';    
            age = a*10 + b;
            if(age > 60) {
                cnt++;
            }
        }

        return cnt;
    }
};