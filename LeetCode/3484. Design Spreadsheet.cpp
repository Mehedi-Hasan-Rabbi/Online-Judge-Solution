class Spreadsheet {
    vector<vector<int>> sheet;
    
    pair<int, int> location (string s) {
        int x = 0, y = 0;

        if ('A' <= s[0] and s[0] <= 'Z') {
            y = s[0] - 'A';
            s.erase(s.begin());
            x = stoi(s) - 1;
        }
        else {
            x = stoi(s);
            y = -1;
        }

        return {x, y};
    }

public:
    Spreadsheet(int rows) {
        sheet.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int row = location(cell).first;
        int col = location(cell).second;
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int row = location(cell).first;
        int col = location(cell).second;
        
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        reverse(formula.begin(), formula.end());
        formula.pop_back(); // Remove "=";
        
        string s1 = "", s2 = "";
        while (formula.back() != '+') {
            s1 += formula.back();
            formula.pop_back();
        }
        
        formula.pop_back();
        while (!formula.empty()) {
            s2 += formula.back();
            formula.pop_back();
        }

        int ans = 0;

        int row = location(s1).first;
        int col = location(s1).second;

        if (col != -1) ans += sheet[row][col];
        else ans += row;
        
        row = location(s2).first;
        col = location(s2).second;

        if (col != -1) ans += sheet[row][col];
        else ans += row;

        return ans;
    }
};