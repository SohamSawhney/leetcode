class Solution {
public:
    int firstUniqChar(string s) {

        int n=s.length();
        int freq[26]={0};
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int index=-1;
        for(int i=0;i<n;i++){
            if(freq[s[i]-'a']==1){
                index=i;
                break;
            }
        }
        return index;
    }
};