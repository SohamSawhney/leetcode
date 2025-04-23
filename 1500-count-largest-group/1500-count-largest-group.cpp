class Solution {
public:
    int finddigitsum(int num){
        int sum=0;
        while(num){
           sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int maxsize=0;
        int count=0;
        for(int num=1;num<=n;num++){
            int digitssum=finddigitsum(num);
            mp[digitssum]++;
            if(mp[digitssum]==maxsize){
                count++;
            }
            else if(mp[digitssum]>maxsize){
                maxsize=mp[digitssum];
                count=1;
            }
        }
        return count;
    }
};