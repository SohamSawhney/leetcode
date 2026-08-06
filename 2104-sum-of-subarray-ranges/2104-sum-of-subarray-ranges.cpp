class Solution {
public:






    vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }


       vector<int>findPSE(vector<int>&nums){
    int n=nums.size();
    stack<int>st;
    vector<int>ans(n);

    for(int i=0;i<n;i++){
        int curr=nums[i];
        while(!st.empty() and nums[st.top()]>curr){
            st.pop();
        }
        ans[i]=!st.empty()?st.top():-1;
        st.push(i);
    }
    
  return ans;
   }




    vector<int>findPGE(vector<int>&nums){
    int n=nums.size();
    stack<int>st;
    vector<int>ans(n);

    for(int i=0;i<n;i++){
        int curr=nums[i];
        while(!st.empty() and nums[st.top()]<curr){
            st.pop();
        }
        ans[i]=!st.empty()?st.top():-1;
        st.push(i);
    }
    
  return ans;
   }



    vector<int>findNGE(vector<int>&nums){
    int n=nums.size();
    stack<int>st;
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=nums[i];
        while(!st.empty() and nums[st.top()]<=curr){
            st.pop();
        }
        ans[i]=!st.empty()?st.top():n;
        st.push(i);
    }
    
  return ans;
   }

   


    long long sumSubarrayMin(vector<int>&nums){
        vector<int>pse=findPSE(nums);
        vector<int>nse=findNSE(nums);

        long long sum=0;
int n=nums.size();
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;


            long long freq=left*right*1LL;

            long long val=(freq*nums[i]*1LL);
            sum+=val;

        }
        return sum;
    }
    long long sumSubarrayMax(vector<int>&nums){
        vector<int>pge=findPGE(nums);
        vector<int>nge=findNGE(nums);
       int n=nums.size();

        
        long long sum=0;

        for(int i=0;i<n;i++){
            int left=i-pge[i];
            int right=nge[i]-i;


            long long freq=left*right*1LL;

            long long val=(freq*nums[i]*1LL);
            sum+=val;

        }
        return sum; 



    }
    long long subArrayRanges(vector<int>& nums) { 

        return (sumSubarrayMax(nums) - 
                 sumSubarrayMin(nums));
        
    }
};



























// class Solution {
// public:
//     vector<int> findPSE(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);
//         stack<int> st;

//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && nums[st.top()] > nums[i]) {
//                 st.pop();
//             }
//             ans[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }
//         return ans;
//     }

//     vector<int> findNSE(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);
//         stack<int> st;

//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && nums[st.top()] >= nums[i]) {
//                 st.pop();
//             }
//             ans[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }
//         return ans;
//     }

//     vector<int> findPGE(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);
//         stack<int> st;

//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && nums[st.top()] < nums[i]) {
//                 st.pop();
//             }
//             ans[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }
//         return ans;
//     }

//     vector<int> findNGE(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);
//         stack<int> st;

//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && nums[st.top()] <= nums[i]) {
//                 st.pop();
//             }
//             ans[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }
//         return ans;
//     }

//     long long sumSubarrayMin(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> pse = findPSE(nums);
//         vector<int> nse = findNSE(nums);

//         long long sum = 0;

//         for (int i = 0; i < n; i++) {
//             long long left = i - pse[i];
//             long long right = nse[i] - i;

//             sum += 1LL * nums[i] * left * right;
//         }

//         return sum;
//     }

//     long long sumSubarrayMax(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> pge = findPGE(nums);
//         vector<int> nge = findNGE(nums);

//         long long sum = 0;

//         for (int i = 0; i < n; i++) {
//             long long left = i - pge[i];
//             long long right = nge[i] - i;

//             sum += 1LL * nums[i] * left * right;
//         }

//         return sum;
//     }

//     long long subArrayRanges(vector<int>& nums) {
//         return sumSubarrayMax(nums) - sumSubarrayMin(nums);
//     }
// };