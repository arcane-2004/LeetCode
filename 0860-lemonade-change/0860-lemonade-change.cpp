class Solution {

    bool solve(int change, unordered_map<int, int>& freq){
        if(change == 15){
            if(freq[10] >= 1 && freq[5] >= 1){
                freq[10]--;
                freq[5]--;
                return true;
            }
            else if(freq[5] >= 3){
                freq[5] -= 3;
                return true;
            }
        }
        else{
            if(freq[5] >= 1){
                freq[10]++;
                freq[5]--;
                return true;
            }
        }

        return false;
    }
public:
    bool lemonadeChange(vector<int>& bills) {
        
        unordered_map<int, int> freq;

        for(int i: bills){

            if(i == 5){
                freq[5]++;
            }

            else{
                int change = i - 5;
                bool check = solve(change, freq);
                if(!check) return false;
            }
        }

        return true;
    }
};