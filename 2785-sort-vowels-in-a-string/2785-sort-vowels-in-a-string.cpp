class Solution {
public:
    bool isvowel(char ch){
      char c=tolower(ch);


        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    string sortVowels(string s) {

        vector<char>vowels;
        for(char ch:s){
            if(isvowel(ch)){
                vowels.push_back(ch);
            }
        }


        sort(vowels.begin(),vowels.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                s[i]=vowels[j++];
            }
        }
        return s;
    }
};