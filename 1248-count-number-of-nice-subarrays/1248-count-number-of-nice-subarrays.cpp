class Solution {
public:
int atmost(vector<int>&nums,int k){
    int right=0;
    int left=0;
    int res=0;
    while(right<nums.size()){
        if(nums[right]%2!=0){
            k--;
        }
       while(k<0){
        if(nums[left]%2!=0){
            k++;

        }
        left++;
       }

        right++;
        res+=(right-left+1);
    }
    return res;
}
    int numberOfSubarrays(vector<int>& nums, int k) {

       return  atmost(nums,k)-atmost(nums,k-1);
        
        
    }
};