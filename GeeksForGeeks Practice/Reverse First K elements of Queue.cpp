#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    queue<int> ans;
    
    while(k--) {
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty()) {
        ans.push(st.top());
        st.pop();
    }
    
    while(!q.empty()) {
        ans.push(q.front());
        q.pop();
    }
    
    return ans;
}