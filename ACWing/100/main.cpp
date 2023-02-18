//AC
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long a[N];
long long b[N];
int main()
{
    int n;
    cin>>n;
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i]-a[i-1];
    }
    long long posiabs=0,negaabs=0;
    for(int i=2;i<=n;i++)
    {
        if(b[i]>0)posiabs+=b[i];
        else if(b[i]<0)negaabs-=b[i];
    }
    cout<<max(posiabs,negaabs)<<endl;
    cout<<max(posiabs,negaabs)-min(posiabs,negaabs)+1<<endl;
}