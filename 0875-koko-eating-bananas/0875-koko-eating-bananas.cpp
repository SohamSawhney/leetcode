class Solution {
public:
   long long calculateTotal(vector<int>& piles,int mid){
    long long totalHours=0;
    for(int banana:piles){
        totalHours+=(1ll*banana+mid-1)/mid;

    }
    return totalHours;
   }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long  totalh=calculateTotal(piles,mid);

            if(totalh<=h){
                ans=mid;
             high=mid-1;
            }
            else{
             low=mid+1;
            }
        }
        return ans;
        
    }
};