class Solution {
public:
     long long mod=1e9+7;
long long power(int  x,long long y){
    if(y==0){
        return 1;
    }


    long long A=power(x,y/2);
    if(y%2==0){
        return (A*A)%mod;
    }
    else{
        return (A*A*x)%mod;
    }

}
    int countGoodNumbers(long long n) {
      
        long long odd=n/2;
        long long even=n-odd;
        long long p1=power(4,odd);
        long long p2=power(5,even);


         return (p1 * p2) % mod;
    }
};