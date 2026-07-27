class Solution {
public:
   int maxRow(vector<vector<int>>&mat,int col,int n){
    int index=-1;
    int maxval=-1;
    for(int i=0;i<n;i++){
        if(mat[i][col]>maxval){
            maxval=mat[i][col];
            index=i;
        }
    }
    return index;
   }


    vector<int> findPeakGrid(vector<vector<int>>& mat) {
      
      int n=mat.size();
      int m=mat[0].size();
      int low=0;
      int high=m-1;
      while(low<=high){
        int mid=low+(high-low)/2;
        int row=maxRow(mat,mid,n);

        int left=mid-1>=0?mat[row][mid-1]:-1;
        int right=mid+1<m?mat[row][mid+1]:-1;

        if(mat[row][mid]>left and mat[row][mid]>right){
            return {row,mid};
        }
        else if(left>mat[row][mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
      }

      return {-1,-1};
    }
};