class Solution {
public:

   void solve(vector<string>&ans,int ind,string mapping[10],string output,string digits){
    if(ind>=digits.length()){
        ans.push_back(output);
        return;

    }
    int number=digits[ind]-'0';
    string value=mapping[number];

    for(int i=0;i<value.size();i++){
        output.push_back(value[i]);
        solve(ans,ind+1,mapping,output,digits);
        output.pop_back();


    }

   }

    vector<string> letterCombinations(string digits) {
        

        vector<string>ans;

        if(digits.empty())
            return ans;
        string output="";
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int ind=0;
        solve(ans,ind,mapping,output,digits);  
        return ans;      
    }
};