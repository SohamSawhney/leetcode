class Solution {
public:
    vector<int>Psee(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            int curr=arr[i];

            while(!st.empty() and arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=!st.empty()?st.top():-1;
            st.push(i);
        }
       return ans;


    }
    vector<int>Nsee(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
               while(!st.empty() and arr[st.top()]>arr[i]){
                st.pop();
               }
        ans[i]=!st.empty()?st.top():n;
        st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int>nse=Nsee(arr);
        vector<int>pse=Psee(arr);

        int n=arr.size();
        int mod=1e9+7;
        long long sum=0;

        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;

            long long freq=left*right*1LL;

            int value=(freq*arr[i]*1LL)%mod;

            sum=(sum+value)%mod;
        }

        return sum;
    }
};