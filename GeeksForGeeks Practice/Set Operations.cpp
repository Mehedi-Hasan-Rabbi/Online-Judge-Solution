//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

set<int> setInsert(int arr[],int n); //Function to insert elements of array into a set and return a set


void setDisplay(set<int>s); //function to print the elements of the set


void setErase(set<int>&s,int x); //function to erase x from set if it exists


// } Driver Code Ends
//User function Template for C++


set<int> setInsert(int arr[],int n)
{
    set<int>s;
    
    for(int i = 0; i < n; i++) s.insert(arr[i]);
    
    return s;
    
}


void setDisplay(set<int>s)
{
    for (auto u: s)
        cout << u << " ";
    cout<<endl;
}


void setErase(set<int>&s,int x)
{
   //write if condition here
   if (s.count(x) == 1) {
       s.erase(x);
       cout<<"erased "<<x;
   }
    
    //write else condition here
    else cout<<"not found";
    
    cout<<endl;
}

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n]; //array of size n
        for(int i=0;i<n;i++)
            cin>>arr[i]; //Input the array
        
        set<int>s=setInsert(arr,n); //call the insert function that returns a set
        setDisplay(s);// display the inserted set
        int x;
        cin>>x; //x element that needs to be erased from set
        
        setErase(s,x); //try to erase x from set
        setDisplay(s); //print the set after erase operation
        
        
    }
	return 0;
}

// } Driver Code Ends