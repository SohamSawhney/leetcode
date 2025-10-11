class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>maxHeap;
 
        int n=arr.size();
        for(int i=0;i<n;i++){
            int dis=abs(arr[i]-x);
            if(maxHeap.size()<k){
                maxHeap.push({dis,arr[i]});
            }
            else if(dis<maxHeap.top().first){
                maxHeap.pop();
                maxHeap.push({dis,arr[i]});
            }
        }
        vector<int>ans;
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};