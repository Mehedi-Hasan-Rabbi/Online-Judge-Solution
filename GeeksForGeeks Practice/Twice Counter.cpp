#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int countWords(string list[], int n)
        {
           map<string, int> freq;
           
           for(int i = 0; i < n; i++) {
               string s = list[i];
               freq[s]++;
           }
           
           int ans = 0;
           for(auto u: freq) {
               if (u.second == 2) ans++;
           }
           
           return ans;
        }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string list[n];
        for(int i=0;i<n;i++)
            cin>>list[i];
        Solution ob;    
        cout <<ob.countWords(list, n)<<endl;
    }
    return 0;
}