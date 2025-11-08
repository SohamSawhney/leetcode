class Solution {
public:
bool f(const vector<int>&bloomDay,int m,int k,int timelimit){
//can i make 'm'  bouqets of k adjacent flowers 
// in the  given time limit 
int count=0;
int bouqetcounter=0;
for(int i=0;i<bloomDay.size();i++){     
    if(bloomDay[i]<=timelimit){
        count++;
        if(count==k){
            bouqetcounter++;
            count=0;
        }
    }
    else{
        count=0;
    }
}

return bouqetcounter>=m;

}
    int minDays(vector<int>& bloomDay, int m, int k) {
      
        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(s<=e){      // n.(log(e-s))
             int mid=s+(e-s)/2;
             //can i make 'm'  bouqets of k adjacent flowers
             // in the mid no. of days
        if(f(bloomDay,m,k,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }

        }
        return ans;
       
    }

};