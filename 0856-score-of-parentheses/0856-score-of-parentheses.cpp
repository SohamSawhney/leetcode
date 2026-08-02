class Solution {
public:
    int scoreOfParentheses(string s) {
        int curr=0;

        stack<char>st;
        for(char ch:s){
            if(ch=='('){
                st.push(curr);
                curr=0;
            }
            else{
                int prev=st.top();
                st.pop();

                curr=prev+max(2*curr,1);
            }
        }
        

        return curr;
        
    }
};