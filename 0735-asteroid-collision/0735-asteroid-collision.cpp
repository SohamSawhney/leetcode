class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int>st;
         

        for(int ast:asteroids){
            if(ast<0 and !st.empty() and st.top()>0){
                bool  flag=true;

                while(!st.empty() and st.top()>0){

                    if(abs(ast)<st.top()){
                        flag=false;
                        break;
                    }
                    else if(abs(ast)==st.top()){
                        st.pop();
                        flag=false;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if(flag){
                    st.push(ast);
                }


                }
        

            else{
                st.push(ast);
            }
        }
        vector<int>ans;
        int n=st.size();
        for(int i=0;i<n;i++){
            ans.push_back(st.top());
            st.pop();
        }
     

     reverse(ans.begin(),ans.end());
    


    return ans;
        
    }
};