class Solution {
public:
void combination(int last,vector<int>&ds, vector<vector<int>>&ans,int k,int target){
    if(target==0 and ds.size()==k){
        ans.push_back(ds);
        return;
    }
    if(target<0 or ds.size()>k){
        return;
    }

    for(int i=last;i<=9;i++){
        ds.push_back(i);
        combination(i+1,ds,ans,k,target-i);
        ds.pop_back();

    }
}
    vector<vector<int>> combinationSum3(int k, int n) {


        vector<int>ds;
        vector<vector<int>>ans;
        combination(1,ds,ans,k,n);



        return ans;
        
    }
};