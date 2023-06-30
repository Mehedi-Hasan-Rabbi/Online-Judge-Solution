#include<bits/stdc++.h>

using namespace std;
#define el endl;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int rem = n%10;
       while(n>9)
       {
           n = n/10;
       }
       cout<<n+rem<<el;
   }  
    return 0;
}