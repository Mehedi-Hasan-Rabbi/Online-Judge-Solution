//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string maximumFrequency(string s);

int main()
{
    int t;cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++)
    {

        string s;
        getline(cin,s);
        
        
        cout << maximumFrequency(s) << endl;

    }
    return 0;
}

// } Driver Code Ends


string maximumFrequency(string s){
        vector<string> word;
        string temp;
        
        for (auto u: s)
        {
            if (isspace(u)) {
                word.push_back(temp);
                temp.clear();
            }
            else temp += u;
        }
	    word.push_back(temp);
        
        int maxi = 0;
        map<string, int> freq;
        for (auto u: word) 
        {
            freq[u]++;
            maxi = max(maxi, freq[u]);
        }
        
        string ans;
        for (auto u: word)
        {
            if (freq[u] == maxi) {
                ans = u;
                ans += " ";
                ans += to_string(maxi);
                break;
            }
        }
        
        return ans;
}