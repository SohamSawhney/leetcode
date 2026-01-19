class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0;
        int maxpoint=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            total+=cardPoints[i];
        }
   maxpoint=total;
   for(int i=0;i<k;i++){
    total-=cardPoints[k-1-i];
    total+=cardPoints[n-1-i];




    maxpoint=max(maxpoint,total);
   }


   return maxpoint;


    }
};