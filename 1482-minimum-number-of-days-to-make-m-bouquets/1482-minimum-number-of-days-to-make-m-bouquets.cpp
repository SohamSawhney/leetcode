class Solution {
public:
 bool f(const vector<int>& bloomDay,int m,int k,int time){
    int count=0;
    int bloomcount=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=time){
            count++;
            if(count==k){
                bloomcount++;
                count=0;
            }
        }
        else{
            count=0;
        }
    }





    return bloomcount>=m;
 }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
         int mid=(low+high)/2;
            if(f(bloomDay,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};