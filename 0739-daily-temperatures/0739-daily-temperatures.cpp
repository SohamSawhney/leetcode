class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
          int n = temperatures.size();
    vector<int> ans(n, 0);

    stack<pair<int,int>> st; // {temperature, days}

    for (int i = n - 1; i >= 0; i--) {

        int days = 1;

        while (!st.empty() && st.top().first <= temperatures[i]) {
            days += st.top().second;
            st.pop();
        }

        if (st.empty())
            ans[i] = 0;
        else
            ans[i] = days;

        st.push({temperatures[i], days});
    }

    return ans;
    }
};