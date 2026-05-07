class Solution {
public:
    int findNthDigit(int n) {

        long long digit=1;
        long long count=9;
        long long start=1;
        while(n>digit*count){
            n=n-digit*count;
            digit++;
            count=count*10;
            start=start*10;

        }

       long long number=start+(n-1)/digit;
       string s=to_string(number);

       return s[(n-1)%digit]-'0';
        
    }
};