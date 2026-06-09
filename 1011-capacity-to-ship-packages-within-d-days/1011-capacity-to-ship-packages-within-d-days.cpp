class Solution {
public:
    int finddays(vector<int>&weight,int capacity){
        int load=0;
        int day=1;
        int n=weight.size();
        for(int i=0;i<n;i++){
            if(load+weight[i]>capacity){
                day+=1;
                load=weight[i];
            }
            else{
                load+=weight[i];
            }

        }
        return day;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid=(low+high)/2;
            int noofDays=finddays(weights,mid);
            if(noofDays<=days){
              high=mid-1;
            }
            else{
              low=mid+1;

            }

        }

        return low;


        
    }
};