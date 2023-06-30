#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define show(x) cout << #x << " : " << x << endl
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient ios::sync_with_stdio(0); cin.tie(0);

void solve()
{
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;

    s3 = s1+s2;

    set<char> uni(s3.begin(), s3.end());

    cout << uni.size()-1 << endl;

}

int main(void)
{
    efficient;

    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
 
