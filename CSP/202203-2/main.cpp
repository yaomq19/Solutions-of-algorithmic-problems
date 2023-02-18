#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int t[n+1],c[n+1];
    int q[m+1];
    for(int i=1;i<=n;i++)
    {
        cin>>t[i]>>c[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>q[i];
    }
    
    for(int i=1;i<=m;i++)
    {
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(t[i]>=q[i]+k && t[i]<=q[i]+k+c[i]-1)
                count++;
        }
        cout<<count;
        if(i<m)cout<<endl;
    }
    return 0;
}