class Solution {
public:
bool isPalindrome(string s){
    string s2=s;
    reverse(s2.begin(),s2.end());

    return s==s2;
}
   void divide(string s,vector<string>&Partition,vector<vector<string>>&ans,int idx){


    if(s.length()==0){
        ans.push_back(Partition);
        return;
    }
     
        for(int i=0;i<s.length();i++){


       string part=s.substr(0,i+1);
        if(isPalindrome(part)){

            Partition.push_back(part);
            divide(s.substr(i+1),Partition,ans,idx+1);
            Partition.pop_back();

        }
}

   }
    vector<vector<string>> partition(string s) {
        vector<string>Partition;
        vector<vector<string>>ans;
        divide(s,Partition,ans,0);
        return ans;

    
        
    }
};