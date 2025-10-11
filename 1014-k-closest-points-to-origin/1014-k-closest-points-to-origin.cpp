class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>wack;
        int n=points.size();
        for(int i=0;i<n;i++){
            wack.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(wack.size()>k){
                wack.pop();
            }
        }
     
        vector<vector<int>> ans;
        while(!wack.empty()){
            pair<int,int>p=wack.top().second;
            ans.push_back({p.first,p.second});
              
            wack.pop();
        }
        return ans;

    }
};