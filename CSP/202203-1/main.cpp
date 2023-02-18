#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int left,right;
    bool ischushihua[n+1]={0};
    ischushihua[0]=true;
    int count=0;
    for(int i=1;i<=k;i++)
    {
        cin>>left>>right;
        if(!ischushihua[right])
        {
            count++;
        }
        ischushihua[left] = true;
    }
    cout<<count;
    return 0;
}