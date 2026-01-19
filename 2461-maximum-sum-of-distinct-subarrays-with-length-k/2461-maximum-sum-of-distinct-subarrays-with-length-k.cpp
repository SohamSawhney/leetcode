class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int i=0;
        int j=0;
        int n=nums.size();
        long long maxsum=0;
        long long wsum=0;
        while(j<k){
            wsum+=nums[j];
            freq[nums[j]]++;
            j++;
        }
        if(freq.size()==k){
      
                    maxsum=max(maxsum,wsum);

        }
       
        while(j<n){
            wsum-=nums[i];
            freq[nums[i]]--;
            if(freq[nums[i]]==0){
                freq.erase(nums[i]);
            }
            i++;
            
            wsum+=nums[j];
            freq[nums[j]]++;
            j++;
         if(freq.size()==k){
            maxsum=max(maxsum,wsum);
         }

        }
        return maxsum;
    }
};