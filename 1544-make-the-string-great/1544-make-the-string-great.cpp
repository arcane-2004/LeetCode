class Solution {
public:
    string makeGood(string s) {
        
        int n = s.length();
        if(n < 2) return s;

        string ans = "";
        stack<char> st;
        st.push(s[0]);

        for(int i=1; i<n; i++){
            if(!st.empty() && abs(st.top() - s[i]) == 32){
                st.pop();
            }

            else{
                st.push(s[i]);
            }  



        }

        while(!st.empty()){
            char top = st.top();
            st.pop();

            ans = top + ans;
        }
        
        return ans;
    }
};