class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
       for(char c:num){
        while(!st.empty()  and k>0 and st.top()>c){
            st.pop();
            k--;
        }
        st.push(c);
       }
       while(k>0 and !st.empty()){
        st.pop();
        k--;
       }


       string res="";
       while(!st.empty()){
        res.push_back(st.top());
        st.pop();
       }

       reverse(res.begin(),res.end());

       // remove leading zero 
       int i=0;
       while(i<res.size() and res[i]=='0'){
        i++;
       }
       string ans=res.substr(i);

       if(ans.empty()){
        return "0";
       }



       return ans;
    }
};