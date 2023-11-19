class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (auto u: operations)
        {
            if ( u.size() > 1 )
                st.push( stoi(u) );
            else {
                if (isdigit(u[0])) st.push(u[0] - '0');
                else if (u[0] == '+') {
                    if (st.size() >= 2) {
                        int top1 = st.top();
                        st.pop();
                        int top2 = st.top();
                        st.pop();

                        st.push(top2);
                        st.push(top1);
                        st.push(top1 + top2);
                    }
                }
                else if (u[0] == 'D') {
                    if (!st.empty()) st.push( 2 * st.top() );
                }
                else {
                    if (!st.empty()) st.pop();
                }
            }
        }

        long long ans = 0LL;
        while(!st.empty()) {
            ans += (long long) st.top();
            st.pop();
        }

        return ans;
    }
};