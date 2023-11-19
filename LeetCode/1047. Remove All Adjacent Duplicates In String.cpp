class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for (auto u: s)
        {
            if (st.empty()) st.push(u);
            else {
                if (st.top() == u) st.pop();
                else st.push(u);
            }
        }

        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};