class Solution {
public:
int lowerBound(vector<int> &arr,int x){
    int low=0,high=arr.size()-1;
    int ans=high+1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int count_max=-1;
        int index=-1;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            sort(mat[i].begin(), mat[i].end());
            int count_ones=m-lowerBound(mat[i],1);
            if(count_ones>count_max){
                count_max=count_ones;
                index=i;
            }
        }
        return {index,count_max};
    }
};