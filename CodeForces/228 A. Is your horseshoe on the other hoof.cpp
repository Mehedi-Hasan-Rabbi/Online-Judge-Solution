#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll color[4];
    for(ll i=0; i<4; i++)
        cin >> color[i];

    set<ll> uni(color, color+4);

    cout<<4-uni.size()<<'\n';
}
