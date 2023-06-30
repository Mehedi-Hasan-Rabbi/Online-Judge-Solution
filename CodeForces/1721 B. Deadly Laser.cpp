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
    int row, col, Sx, Sy, d, start_to_end, Gx1, Gy1, Gx2, Gy2;
    cin >> row >> col >> Sx >> Sy >> d;

    start_to_end = abs(1-row) + abs(1-col);


    Gx1 = abs(Sx-Sx) + abs(Sy-1);
    Gy1 = abs(Sx-1) + abs(Sy-Sy);
    Gx2 = col-Gx1-1;
    Gy2 = row-Gy1-1;

    if ((Gx1 > d && Gy2 > d) || (Gy1 > d && Gx2 > d))
        cout << start_to_end << endl;

    else
        cout << "-1" << endl;

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

