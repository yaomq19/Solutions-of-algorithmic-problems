#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,vector<ll>> q;
ll n,m,i,j,k,p,h,c[10100],d[10100];
int main()
{
    cin>>n>>p>>h>>m;
    for (i=1;i<=m;i++)
    {
        ll A,B;
        cin>>A>>B;
        if (A>B)
            swap(A,B);
        bool find = false;
        for(auto &it:q[A])
        {
            if(it==B){
                find=true;break;
            }
        }
        if (!find){
            q[A].push_back(B),d[A+1]--,d[B]++;
        }
            
    }
    for (i=1;i<=n;i++)
        c[i]=c[i-1]+d[i];
    for (i=1;i<=n;i++)
        cout<<c[i]+h<<endl;
}