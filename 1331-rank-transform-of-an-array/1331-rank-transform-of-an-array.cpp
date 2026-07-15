class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int x:arr){
            pq.push(x);
        }
        unordered_map<int,int>rank;
        int r=1;
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();


            if(rank.find(x)==rank.end()){
                rank[x]=r++;
            }
        }
        vector<int>ans;
        for(int x:arr){
            ans.push_back(rank[x]);
        }
        return ans;
        
    }
};