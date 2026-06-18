class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int,int>mp;
        int maxfruit=0;
        int left=0;
        int right=0;
        int n=fruits.size();
        while(right<n){
            mp[fruits[right]]++;
            while(mp.size()>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }





                left++;
            }
            maxfruit=max(maxfruit,right-left+1);
            right++;
        }
        return maxfruit;

    }
};