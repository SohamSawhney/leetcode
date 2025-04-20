class Solution {
public:
int sumBy(vector<int>&nums,int mid){
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum += ceil((double)(nums[i])/(double)(mid));
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int mid=(low+high)/2;
        int n=nums.size();
        int ans=high;
        if(n>threshold) return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(sumBy(nums,mid)<=threshold){
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