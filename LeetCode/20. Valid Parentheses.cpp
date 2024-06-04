class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto u: s) {
            if (stk.empty()) 
                stk.push(u);
            else if (u == '(' || u == '{' || u == '[')
                stk.push(u);
            else if (u == ')') {
                if (stk.top() == '(') stk.pop();
                else stk.push(u);
            }
            else if (u == '}') {
                if (stk.top() == '{') stk.pop();
                else stk.push(u);
            }
            else if (u == ']') {
                if (stk.top() == '[') stk.pop();
                else stk.push(u);
            }
        }

        if (stk.empty()) return true;
        else return false;
    }
};