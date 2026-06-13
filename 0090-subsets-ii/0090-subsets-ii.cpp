class Solution {
public:

    void subset2(int idx,vector<int>&nums,vector<int>ds,vector<vector<int>>&ans){
        int n=nums.size();
        ans.push_back(ds);
        for(int i=idx;i<n;i++){
            if(i>idx and nums[i-1]==nums[i]){
                continue;
            }
            ds.push_back(nums[i]);
            subset2(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int>ds;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        subset2(0,nums,ds,ans);


        return ans;
        
    }
};