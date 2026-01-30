class Solution {
public:
bool f(int n,int target,vector<int>nums){

    vector<bool>prev(target+1,0),curr(target+1,0);
    prev[0]=true;
    if(nums[0]<=target){
        prev[nums[0]]=true;
    }
    for(int i=1;i<n;i++){
        curr[0]=true;
        for(int j=1;j<=target;j++){
            bool nottake=prev[j];
            bool take=false;
            if(nums[i]<=j){
               take=prev[j-nums[i]];
            }
            // Update the current row of the DP table
                curr[j] = nottake || take;
        }
        prev=curr;

        
    }
    return prev[target];
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        if(totalsum%2) return false;
        int target=totalsum/2;
        return f(n,target,nums);
        
    }
};