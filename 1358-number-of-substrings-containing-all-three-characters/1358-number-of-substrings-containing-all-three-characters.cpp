class Solution {
public:
    int numberOfSubstrings(string s) {
     int left=0;
     int res=0;
     vector<int>freq(3,0);
     int right=0;
     int n=s.length();

     while(right<n){
        freq[s[right]-'a']++;
        

    while(freq[0]>0 and freq[1]>0 and freq[2]>0){
        res+=(n-right);
        freq[s[left]-'a']--;
        left++;

    }




        right++;
     }
        

        return res;
    }
};