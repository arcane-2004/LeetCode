class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long power = n;
        if(n < 0){
            x = 1.0 / x;
            power = - power;
        }

        while(power > 0){
            if(power % 2 == 1){
                ans *= x;
            }

            x *= x;
            power /= 2;
        }

        return ans;
    }
};