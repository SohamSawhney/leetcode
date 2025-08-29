class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int el;
        for(int i=0;i<n;i++){
            if(count==0){
                el=nums[i];
                count=1;
            }
            else if(nums[i]==el){
                count++;
            }
            else{
                count--;
            }
        }
        int count2=0;
        for(int i=0;i<n;i++){
            if(el==nums[i]){
                count2++;
            }
        }
        if(count2>(n/2)){
            return el;
        }
        return -1;
    }
};