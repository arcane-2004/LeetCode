class Solution {
public:
    string smallestPalindrome(string s) {
        
        int n = s.length();
        vector<int> arr(26,0);

        for(int i=0; i<n; i++){
            arr[s[i] -'a']++;
        }

        string left = "";
        string middle = "";
        string right = "";

        for(int i=0; i<26; i++){
            if(arr[i] % 2 == 1){
                char ch = 'a'+ i;
                middle += ch;
            }
            
            int d = arr[i]/2;
            char ch = 'a'+i;
            left.append(d, ch);
            

        }

        for(int i = left.length()-1; i>=0; i--){
            right += left[i];
        }
        cout<<left<<endl;
        cout<<middle<<endl;
        cout<<right<<endl;
        string ans = left + middle + right;
        return ans;


    }
};