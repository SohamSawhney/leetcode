class Solution {
public:
 int maxArea(vector<int>& heights){
int n=heights.size();
  int maxsofar=0;
  int i=0;
  int j=n-1;
while(i<j){
    int width=j-i;
    int height=min(heights[i],heights[j]);
    int area=width*height;
    maxsofar=max(area,maxsofar);
    if(heights[i]<heights[j]){
        i++;
    }
    else {
       j--;
    }


}

return maxsofar;



}
};