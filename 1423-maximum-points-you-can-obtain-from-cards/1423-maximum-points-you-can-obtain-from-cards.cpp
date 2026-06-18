class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
      int  maxsum=0;
       int totalsum=0;
        for(int i=0;i<k;i++){
            totalsum+=cardPoints[i];

        }
        maxsum=totalsum;

        for(int i=0;i<k;i++){
            totalsum-=cardPoints[k-1-i];
            totalsum+=cardPoints[n-1-i];
            maxsum=max(totalsum,maxsum);
        }
        return maxsum;
    }
};