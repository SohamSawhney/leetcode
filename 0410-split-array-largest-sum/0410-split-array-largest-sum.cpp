class Solution {
public:
  int partition(vector<int>&arr,int mid){
    int partition=1;
    int sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(sum+arr[i]<=mid){
            sum+=arr[i];
        }
        else{
            sum=arr[i];
            partition++;
        }

    }
    return partition;
  }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(partition(nums,mid)<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};