class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int xorall=0;
      int n=nums.size();
      for(int i=0;i<=n;i++){
        xorall=xorall^i;
      }
      for(int i=0;i<n;i++){
        xorall=xorall^nums[i];
      }
      return xorall;

    }
};