//AC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1],b[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i]-a[i-1];
    }
    int l,r,c;
    while(m--)
    {
        cin>>l>>r>>c;
        b[l]+=c;
        if(r+1<=n)b[r+1]-=c;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+b[i];
        cout<<a[i]<<" ";
    }
    return 0;
}