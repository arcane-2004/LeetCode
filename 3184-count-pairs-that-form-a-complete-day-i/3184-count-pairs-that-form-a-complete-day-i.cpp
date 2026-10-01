class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        
        unordered_map<int, int> mp;

        int cnt = 0;
        for(int i: hours){


            int tg = 24 - (i % 24);

            cnt += mp[tg % 24];
            mp[i % 24] += 1;
            
        }

        return cnt;
    }
};