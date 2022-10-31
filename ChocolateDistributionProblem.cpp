#include<bits/stdc++.h>
using namespace std;
int chocolateDis(int arr[],int n,int m)
{
	sort(arr,arr+n);
    if(n==0||m==0)
    return 0;
    int ans=INT_MAX;
    for(int i=0;i+m-1<n;i++)
    {
    	ans=min(ans,arr[i+m-1]-arr[i]);
	}
	return ans;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int arr[n];
     for(int i=0;i<n;i++)
     cin>>arr[i];
	int ans=chocolateDis(arr,n,m);
	cout<<ans<<endl;
	return 0;
}
