class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>mp(26);
        for(int i=0;i<order.size();i++){
            mp[order[i]-'a']=i;
        }

        for(int i=0;i<words.size()-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            bool founddiff=false;
            int len=min(s1.length(),s2.length());
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    if(mp[s1[j]-'a']>mp[s2[j]-'a']){
                        return false;
                    }
                    founddiff=true;
                    break;
                }
            }
                if(!founddiff && s1.size()>s2.size()){
                    return false;
                }
                
            
        }
        return true;
        
    }
};