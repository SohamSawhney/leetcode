class Solution {
public:
    bool checkPowersOfThree(int n) {

    while (n > 0) {
            int digit = n % 3;   // get last base-3 digit
            if (digit == 2) return false;  // if any digit is 2, not valid
            n /= 3;              // move to next base-3 digit
        }
        return true;  // all digits were 0 or 1
    }
   
    
};