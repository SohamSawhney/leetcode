class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        vector<int>freq(3,0);
        int res=0;
        for(int right=0;right<s.length();right++){
            freq[s[right]-'a']++;

            while(freq[0]>0 and freq[1]>0 and freq[2]>0){
                res+=(s.length()-right);
                freq[s[left]-'a']--;


                left++;
            }
            
        }
        return res;
        
    }
};