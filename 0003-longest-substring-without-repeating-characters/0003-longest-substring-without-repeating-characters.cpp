class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
    int j=0;
    int n=s.length();
    int maxLen=0;
    unordered_map<char,int>freqMap;

  while(j<n){
    freqMap[s[j]]++;
    while(freqMap[s[j]]>1){
        freqMap[s[i]]--;
        

        i++;
    }



maxLen=max(maxLen,j-i+1);
    j++;
  }
    return maxLen;
    }
};