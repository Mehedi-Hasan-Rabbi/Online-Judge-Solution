//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void insert(set<int> &s,int x);

void print_contents(set<int> &s);

void erase(set<int> &s,int x);

int find(set<int> &s,int x);

int size(set<int> &s);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		set<int> s;
		int q;
		cin>>q;
		while(q--)
		{
			char c;
			cin>>c;
			if(c=='a')
			{
				int x;
				cin>>x;
				insert(s,x);
			}
			if(c=='b')
			{
				print_contents(s);
			}
			if(c=='c')
			{
				int x;
				cin>>x;
				erase(s,x);
			}
			if(c=='d')
			{
				int x;
				cin>>x;
				cout<<find(s,x)<<" ";
			}
                       if(c=='e')
                       cout<<size(s)<<" ";
		
		}
cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/* You are required to complete below methods */

/*inserts an element x to the set s */
void insert(set<int> &s,int x)
{
    s.insert(x);
}

/*prints the contents of the set s */
void print_contents(set<int> &s)
{
    for (auto u: s) cout << u << " ";
}

/*erases an element x from the set s */
void erase(set<int> &s,int x)
{
    s.erase(x);
}

/*returns 1 if the element x is
present in set s else returns -1 */
int find(set<int> &s,int x)
{
    if (s.count(x) == 1) return 1;
    else return -1;
}

/*returns the size of the set s */
int size(set<int> &s)
{
   return s.size();
}