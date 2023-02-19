#include<bits/stdc++.h>
using namespace std;
int n,N;
int A[210]={0};
int main()
{
    int sumA=0;
    A[0]=0;
    cin>>n>>N;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    int now=0;
    for(int i=0;i<=n;i++)
    {
        if(A[i]>now){
            sumA+=i-1;
            i--;
            now++;
            if(now==N)break;
        }
        if(i==n && A[i]<=now)
        {
            sumA+=(n*(N-now));
        }
        
    }
    cout<<sumA;

    return 0;
}