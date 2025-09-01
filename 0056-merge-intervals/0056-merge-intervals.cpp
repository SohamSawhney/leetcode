class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     vector<vector<int>>ans;
     int n=intervals.size();
     sort(intervals.begin(),intervals.end());
     for(int i=0;i<intervals.size();i++){
        int start=intervals[i][0];
        int end=intervals[i][1];
        if(!ans.empty() && ans.back()[1]>=start){
            ans.back()[1]=max(ans.back()[1],end);
        }
        else{
            ans.push_back({start,end});
        }
     }
     return ans;
    }
};