class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size()-1;

        if(digits[n] != 9){
            digits[n]+= 1;
            return digits; 
        }

        while(n >= 0 && digits[n] == 9){
            digits[n] = 0;
            n--;
        }

        if(n < 0){
            digits[0] = 1;
            for(int i=1; i<digits.size(); i++){
                digits[i] = 0;
            }
            digits.push_back(0);
        }

        else{
            digits[n] += 1;
        }

        return digits;


    }
};