class Solution {
public:
    int myAtoi(string s) {
     int i=0;
     while(s[i]==' '){
        i++;
     }
     int sign=1;
     if(i<s.size() && (s[i]=='+' or s[i]=='-')){
         sign=(s[i]=='-')?-1:1;
         i++;
     }
        long long result=0;
        while(s[i]>='0' and s[i]<='9'){
            result=result*10+(s[i]-'0');
            if(result*sign>INT_MAX){
                return INT_MAX;
            }
            if(result*sign<INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return (result*sign);
        
    }
};