class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum=0;
        int count=0;
        int n=nums.size();
        map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remove=presum-k;
            if(mp.find(remove)!=mp.end()){
                count+=mp[remove];
        
            }
             mp[presum]= mp[presum]+1;
        
        }
        return count;
    }
};