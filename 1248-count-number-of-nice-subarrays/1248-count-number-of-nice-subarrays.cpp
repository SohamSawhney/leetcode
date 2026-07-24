class Solution {
public:
int atmost(vector<int>&nums,int k){
    int left=0;
    int right=0;
    int res=0;
    int n=nums.size();
    while(right<n){
    if(nums[right]%2!=0){
        k--;
    }
    while(k<0){
        if(nums[left]%2!=0){
            k++;
        }
        left++;
        
    }

    res+=(right-left+1);

    right++;

    }

    return res;
}
    int numberOfSubarrays(vector<int>& nums, int k) {

       return  atmost(nums,k)-atmost(nums,k-1);
        
        
    }
};